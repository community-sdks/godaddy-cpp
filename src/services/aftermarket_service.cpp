#include "godaddy/services/aftermarket_service.hpp"

namespace godaddy {

AftermarketService::AftermarketService(ApiClient& client) : BaseService(client, "https://api.ote-godaddy.com") {}

Result AftermarketService::getListings(const Value& customerId, const Value& domains, const Value& listingStatus, const Value& transferBefore, const Value& transferAfter, const Value& limit, const Value& offset) {
    return call(
        "GET",
        "/v1/customers/{customerId}/auctions/listings",
        {{"customerId", customerId}},
        {{"domains", domains}, {"listingStatus", listingStatus}, {"transferBefore", transferBefore}, {"transferAfter", transferAfter}, {"limit", limit}, {"offset", offset}},
        {},
        Value{}
    );
}

Result AftermarketService::deleteListings(const Value& domains) {
    return call(
        "DELETE",
        "/v1/aftermarket/listings",
        {},
        {{"domains", domains}},
        {},
        Value{}
    );
}

Result AftermarketService::addExpiryListings(const Value& expiryListings) {
    return call(
        "POST",
        "/v1/aftermarket/listings/expiry",
        {},
        {},
        {},
        expiryListings
    );
}

}  // namespace godaddy
