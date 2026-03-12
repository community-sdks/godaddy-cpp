#pragma once

#include <chrono>
#include <map>
#include <string>

namespace godaddy {

inline constexpr const char* kSandboxBaseUrl = "https://api.ote-godaddy.com";
inline constexpr const char* kProductionBaseUrl = "https://api.godaddy.com";

struct Config {
    std::string api_key{};
    std::string api_secret{};
    std::string base_url{kSandboxBaseUrl};
    std::map<std::string, std::string> service_base_urls{};
    std::chrono::milliseconds timeout{30000};
    int max_retries{2};
    std::chrono::milliseconds retry_delay{200};
    std::map<std::string, std::string> default_headers{};
    std::string user_agent{"community-sdks/godaddy-cpp"};
};

inline Config sandbox_config(std::string api_key, std::string api_secret) {
    Config config;
    config.api_key = std::move(api_key);
    config.api_secret = std::move(api_secret);
    config.base_url = kSandboxBaseUrl;
    return config;
}

inline Config production_config(std::string api_key, std::string api_secret) {
    Config config;
    config.api_key = std::move(api_key);
    config.api_secret = std::move(api_secret);
    config.base_url = kProductionBaseUrl;
    return config;
}

}  // namespace godaddy
