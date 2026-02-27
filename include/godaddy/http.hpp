#pragma once

#include <map>
#include <memory>
#include <string>
#include <vector>

#include "godaddy/types.hpp"

namespace godaddy {

struct Request {
    std::string method;
    std::string url;
    std::map<std::string, std::string> headers;
    std::vector<QueryPair> query;
    Value body;

    std::string full_url() const;
};

struct Response {
    int status_code{0};
    std::map<std::string, std::string> headers;
    std::string body;
};

class Transport {
public:
    virtual ~Transport() = default;
    virtual Response send(const Request& request) = 0;
};

class HttpTransport final : public Transport {
public:
    Response send(const Request& request) override;
};

}  // namespace godaddy
