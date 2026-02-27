#pragma once

#include <chrono>
#include <map>
#include <string>

namespace godaddy {

struct Config {
    std::string api_key{};
    std::string api_secret{};
    std::string base_url{};
    std::chrono::milliseconds timeout{30000};
    int max_retries{2};
    std::chrono::milliseconds retry_delay{200};
    std::map<std::string, std::string> default_headers{};
    std::string user_agent{"community-sdks/godaddy-cpp"};
};

}  // namespace godaddy
