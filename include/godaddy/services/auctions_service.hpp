#pragma once

#include "godaddy/service_base.hpp"

namespace godaddy {

class AuctionsService final : public BaseService {
public:
    explicit AuctionsService(ApiClient& client);
    Result placeBids(const Value& customerId, const Value& requestBody);
};

}  // namespace godaddy
