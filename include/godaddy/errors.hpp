#pragma once

#include <stdexcept>
#include <string>
#include <utility>
#include <map>

namespace godaddy {

class ApiException : public std::runtime_error {
public:
    ApiException(std::string message, int status_code, std::string response_body, std::map<std::string, std::string> headers, std::string request_method, std::string request_url);
    int status_code() const noexcept { return status_code_; }
    const std::string& response_body() const noexcept { return response_body_; }
    const std::map<std::string, std::string>& headers() const noexcept { return headers_; }
    const std::string& request_method() const noexcept { return request_method_; }
    const std::string& request_url() const noexcept { return request_url_; }
    std::string request_id() const;

private:
    int status_code_;
    std::string response_body_;
    std::map<std::string, std::string> headers_;
    std::string request_method_;
    std::string request_url_;
};

class ValidationException : public ApiException { using ApiException::ApiException; };
class UnauthorizedException : public ApiException { using ApiException::ApiException; };
class NotFoundException : public ApiException { using ApiException::ApiException; };
class RateLimitException : public ApiException { using ApiException::ApiException; };
class ServerException : public ApiException { using ApiException::ApiException; };

}  // namespace godaddy
