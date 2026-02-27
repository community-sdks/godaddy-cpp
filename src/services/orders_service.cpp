#include "godaddy/services/orders_service.hpp"

namespace godaddy {

OrdersService::OrdersService(ApiClient& client) : BaseService(client, "https://api.ote-godaddy.com") {}

Result OrdersService::list(const Value& xAppKey, const Value& periodStart, const Value& periodEnd, const Value& domain, const Value& productGroupId, const Value& paymentProfileId, const Value& parentOrderId, const Value& offset, const Value& limit, const Value& sort, const Value& xShopperId) {
    return call(
        "GET",
        "/v1/orders",
        {},
        {{"periodStart", periodStart}, {"periodEnd", periodEnd}, {"domain", domain}, {"productGroupId", productGroupId}, {"paymentProfileId", paymentProfileId}, {"parentOrderId", parentOrderId}, {"offset", offset}, {"limit", limit}, {"sort", sort}},
        {{"X-Shopper-Id", xShopperId}, {"X-App-Key", xAppKey}},
        Value{}
    );
}

Result OrdersService::get(const Value& orderId, const Value& xAppKey, const Value& xShopperId, const Value& xMarketId) {
    return call(
        "GET",
        "/v1/orders/{orderId}",
        {{"orderId", orderId}},
        {},
        {{"X-Shopper-Id", xShopperId}, {"X-Market-Id", xMarketId}, {"X-App-Key", xAppKey}},
        Value{}
    );
}

}  // namespace godaddy
