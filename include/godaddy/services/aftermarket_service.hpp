#pragma once

#include "godaddy/service_base.hpp"

namespace godaddy {

class AftermarketService final : public BaseService {
public:
    explicit AftermarketService(ApiClient& client);
    Result getListings(const Value& customerId, const Value& domains = {}, const Value& listingStatus = {}, const Value& transferBefore = {}, const Value& transferAfter = {}, const Value& limit = {}, const Value& offset = {});
    Result deleteListings(const Value& domains);
    Result addExpiryListings(const Value& expiryListings);
};

}  // namespace godaddy
