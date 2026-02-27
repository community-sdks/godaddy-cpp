#pragma once

#include "godaddy/service_base.hpp"

namespace godaddy {

class SubscriptionsService final : public BaseService {
public:
    explicit SubscriptionsService(ApiClient& client);
    Result list(const Value& xAppKey, const Value& xShopperId = {}, const Value& xMarketId = {}, const Value& productGroupKeys = {}, const Value& includes = {}, const Value& offset = {}, const Value& limit = {}, const Value& sort = {});
    Result productGroups(const Value& xAppKey, const Value& xShopperId = {});
    Result cancel(const Value& subscriptionId, const Value& xAppKey, const Value& xShopperId = {});
    Result get(const Value& subscriptionId, const Value& xAppKey, const Value& xShopperId = {});
    Result update(const Value& subscriptionId, const Value& xAppKey, const Value& subscription, const Value& xShopperId = {});
};

}  // namespace godaddy
