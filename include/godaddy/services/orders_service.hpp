#pragma once

#include "godaddy/service_base.hpp"

namespace godaddy {

class OrdersService final : public BaseService {
public:
    explicit OrdersService(ApiClient& client);
    Result list(const Value& xAppKey, const Value& periodStart = {}, const Value& periodEnd = {}, const Value& domain = {}, const Value& productGroupId = {}, const Value& paymentProfileId = {}, const Value& parentOrderId = {}, const Value& offset = {}, const Value& limit = {}, const Value& sort = {}, const Value& xShopperId = {});
    Result get(const Value& orderId, const Value& xAppKey, const Value& xShopperId = {}, const Value& xMarketId = {});
};

}  // namespace godaddy
