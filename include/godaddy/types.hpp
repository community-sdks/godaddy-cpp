#pragma once

#include <any>
#include <cstdint>
#include <map>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace godaddy {

using Value = std::any;
using Param = std::pair<std::string, Value>;
using QueryPair = std::pair<std::string, std::string>;

class Result {
public:
    Result() = default;
    explicit Result(std::string value) : value_(std::move(value)) {}
    const std::string& as_string() const { return value_; }

private:
    std::string value_;
};

}  // namespace godaddy
