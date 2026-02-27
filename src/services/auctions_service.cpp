#include "godaddy/services/auctions_service.hpp"

namespace godaddy {

AuctionsService::AuctionsService(ApiClient& client) : BaseService(client, "https://api.ote-godaddy.com") {}

Result AuctionsService::placeBids(const Value& customerId, const Value& requestBody) {
    return call(
        "POST",
        "/v1/customers/{customerId}/aftermarket/listings/bids",
        {{"customerId", customerId}},
        {},
        {},
        requestBody
    );
}

}  // namespace godaddy
