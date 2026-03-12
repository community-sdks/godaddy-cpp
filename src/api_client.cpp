#include "godaddy/api_client.hpp"

#include <sstream>
#include <thread>

#include "godaddy/errors.hpp"

namespace godaddy {

namespace {

std::string stringify(const Value& value) {
    if (!value.has_value()) return {};
    if (const auto* boolean = std::any_cast<bool>(&value)) return *boolean ? "true" : "false";
    if (const auto* integer = std::any_cast<std::int64_t>(&value)) return std::to_string(*integer);
    if (const auto* integer32 = std::any_cast<int>(&value)) return std::to_string(*integer32);
    if (const auto* text = std::any_cast<std::string>(&value)) return *text;
    if (const auto* strings = std::any_cast<std::vector<std::string>>(&value)) {
        std::ostringstream stream;
        stream << "[";
        for (std::size_t index = 0; index < strings->size(); ++index) {
            if (index > 0) stream << ",";
            stream << (*strings)[index];
        }
        stream << "]";
        return stream.str();
    }
    return "<value>";
}

Result decode_response(const Response& response) {
    return Result(response.body);
}

}  // namespace

ApiClient::ApiClient(Config config, std::shared_ptr<Transport> transport) : config_(std::move(config)), transport_(std::move(transport)) {
    if (transport_ == nullptr) {
        transport_ = std::make_shared<HttpTransport>();
    }
}

std::vector<QueryPair> ApiClient::build_query_pairs(const std::vector<Param>& values) {
    std::vector<QueryPair> pairs;
    for (const auto& pair : values) {
        if (!pair.second.has_value()) continue;
        if (const auto* items = std::any_cast<std::vector<std::string>>(&pair.second)) {
            for (const auto& item : *items) pairs.emplace_back(pair.first, item);
            continue;
        }
        pairs.emplace_back(pair.first, stringify(pair.second));
    }
    return pairs;
}

std::string ApiClient::resolve_base_url(const std::string& service_name) const {
    // Preserve backward compatibility for existing services that still pass absolute URLs.
    if (service_name.rfind("http://", 0) == 0 || service_name.rfind("https://", 0) == 0) {
        return service_name;
    }
    if (!service_name.empty()) {
        const auto it = config_.service_base_urls.find(service_name);
        if (it != config_.service_base_urls.end() && !it->second.empty()) {
            return it->second;
        }
    }
    if (!config_.base_url.empty()) {
        return config_.base_url;
    }
    return kSandboxBaseUrl;
}

Result ApiClient::request(const std::string& method, const std::string& service_name, const std::string& path,
                          const std::vector<Param>& path_params, const std::vector<Param>& query_params,
                          const std::vector<Param>& headers, const Value& body) const {
    std::string url = resolve_base_url(service_name);
    if (!url.empty() && url.back() == '/') url.pop_back();
    std::string resolved_path = path;
    for (const auto& pair : path_params) {
        if (!pair.second.has_value()) continue;
        const std::string token = "{" + pair.first + "}";
        const auto replacement = stringify(pair.second);
        std::size_t pos = 0;
        while ((pos = resolved_path.find(token, pos)) != std::string::npos) {
            resolved_path.replace(pos, token.size(), replacement);
            pos += replacement.size();
        }
    }

    std::map<std::string, std::string> resolved_headers{{"Accept", "application/json"}, {"User-Agent", config_.user_agent}};
    for (const auto& header : config_.default_headers) resolved_headers[header.first] = header.second;
    for (const auto& header : headers) if (header.second.has_value()) resolved_headers[header.first] = stringify(header.second);
    if (!config_.api_key.empty() && !config_.api_secret.empty()) resolved_headers["Authorization"] = "sso-key " + config_.api_key + ":" + config_.api_secret;
    if (body.has_value() && !resolved_headers.count("Content-Type")) resolved_headers["Content-Type"] = "application/json";

    Request request{method, url + resolved_path, resolved_headers, build_query_pairs(query_params), body};

    int attempt = 0;
    while (true) {
        const auto response = transport_->send(request);
        const bool retryable = response.status_code == 408 || response.status_code == 429 || response.status_code == 500 ||
                               response.status_code == 502 || response.status_code == 503 || response.status_code == 504;
        if (!(retryable && attempt < config_.max_retries)) {
            if (response.status_code < 200 || response.status_code >= 300) {
                auto args = std::make_tuple("GoDaddy API request failed with status " + std::to_string(response.status_code), response.status_code, response.body, response.headers, request.method, request.full_url());
                if (response.status_code == 400) throw ValidationException(std::get<0>(args), std::get<1>(args), std::get<2>(args), std::get<3>(args), std::get<4>(args), std::get<5>(args));
                if (response.status_code == 401 || response.status_code == 403) throw UnauthorizedException(std::get<0>(args), std::get<1>(args), std::get<2>(args), std::get<3>(args), std::get<4>(args), std::get<5>(args));
                if (response.status_code == 404) throw NotFoundException(std::get<0>(args), std::get<1>(args), std::get<2>(args), std::get<3>(args), std::get<4>(args), std::get<5>(args));
                if (response.status_code == 429) throw RateLimitException(std::get<0>(args), std::get<1>(args), std::get<2>(args), std::get<3>(args), std::get<4>(args), std::get<5>(args));
                if (response.status_code >= 500) throw ServerException(std::get<0>(args), std::get<1>(args), std::get<2>(args), std::get<3>(args), std::get<4>(args), std::get<5>(args));
                throw ApiException(std::get<0>(args), std::get<1>(args), std::get<2>(args), std::get<3>(args), std::get<4>(args), std::get<5>(args));
            }
            return decode_response(response);
        }
        std::this_thread::sleep_for(config_.retry_delay * (1 << attempt));
        ++attempt;
    }
}

}  // namespace godaddy
