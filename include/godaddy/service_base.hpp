#pragma once

#include <string>
#include <vector>

#include "godaddy/api_client.hpp"

namespace godaddy {

class BaseService {
public:
    BaseService(ApiClient& client, std::string base_url) : client_(client), base_url_(std::move(base_url)) {}

protected:
    Result call(const std::string& method, const std::string& path, const std::vector<Param>& path_params = {},
                const std::vector<Param>& query_params = {}, const std::vector<Param>& headers = {},
                const Value& body = {}) const;

    ApiClient& client_;
    std::string base_url_;
};

}  // namespace godaddy
