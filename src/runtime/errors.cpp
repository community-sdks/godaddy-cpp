#include "godaddy/errors.hpp"

namespace godaddy {

ApiException::ApiException(std::string message, int status_code, std::string response_body, std::map<std::string, std::string> headers,
                           std::string request_method, std::string request_url)
    : std::runtime_error(std::move(message)),
      status_code_(status_code),
      response_body_(std::move(response_body)),
      headers_(std::move(headers)),
      request_method_(std::move(request_method)),
      request_url_(std::move(request_url)) {}

std::string ApiException::request_id() const {
    const auto lower = headers_.find("x-request-id");
    if (lower != headers_.end()) return lower->second;
    const auto upper = headers_.find("X-Request-Id");
    if (upper != headers_.end()) return upper->second;
    return {};
}

}  // namespace godaddy
