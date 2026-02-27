#pragma once

#include <memory>
#include <string>
#include <vector>

#include "godaddy/config.hpp"
#include "godaddy/http.hpp"
#include "godaddy/types.hpp"

namespace godaddy {

class ApiClient {
public:
    explicit ApiClient(Config config = {}, std::shared_ptr<Transport> transport = nullptr);
    Result request(const std::string& method, const std::string& service_base_url, const std::string& path,
                   const std::vector<Param>& path_params = {}, const std::vector<Param>& query_params = {},
                   const std::vector<Param>& headers = {}, const Value& body = {}) const;

    static std::vector<QueryPair> build_query_pairs(const std::vector<Param>& values);

private:
    Config config_;
    std::shared_ptr<Transport> transport_;
};

}  // namespace godaddy
