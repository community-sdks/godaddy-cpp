#include "godaddy/services/subscriptions_service.hpp"

namespace godaddy {

SubscriptionsService::SubscriptionsService(ApiClient& client) : BaseService(client, "subscriptions") {}

Result SubscriptionsService::list(const Value& xAppKey, const Value& xShopperId, const Value& xMarketId, const Value& productGroupKeys, const Value& includes, const Value& offset, const Value& limit, const Value& sort) {
    return call(
        "GET",
        "/v1/subscriptions",
        {},
        {{"productGroupKeys", productGroupKeys}, {"includes", includes}, {"offset", offset}, {"limit", limit}, {"sort", sort}},
        {{"X-App-Key", xAppKey}, {"X-Shopper-Id", xShopperId}, {"X-Market-Id", xMarketId}},
        Value{}
    );
}

Result SubscriptionsService::productGroups(const Value& xAppKey, const Value& xShopperId) {
    return call(
        "GET",
        "/v1/subscriptions/productGroups",
        {},
        {},
        {{"X-App-Key", xAppKey}, {"X-Shopper-Id", xShopperId}},
        Value{}
    );
}

Result SubscriptionsService::cancel(const Value& subscriptionId, const Value& xAppKey, const Value& xShopperId) {
    return call(
        "DELETE",
        "/v1/subscriptions/{subscriptionId}",
        {{"subscriptionId", subscriptionId}},
        {},
        {{"X-App-Key", xAppKey}, {"X-Shopper-Id", xShopperId}},
        Value{}
    );
}

Result SubscriptionsService::get(const Value& subscriptionId, const Value& xAppKey, const Value& xShopperId) {
    return call(
        "GET",
        "/v1/subscriptions/{subscriptionId}",
        {{"subscriptionId", subscriptionId}},
        {},
        {{"X-App-Key", xAppKey}, {"X-Shopper-Id", xShopperId}},
        Value{}
    );
}

Result SubscriptionsService::update(const Value& subscriptionId, const Value& xAppKey, const Value& subscription, const Value& xShopperId) {
    return call(
        "PATCH",
        "/v1/subscriptions/{subscriptionId}",
        {{"subscriptionId", subscriptionId}},
        {},
        {{"X-App-Key", xAppKey}, {"X-Shopper-Id", xShopperId}},
        subscription
    );
}

}  // namespace godaddy
