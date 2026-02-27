#pragma once

#include "godaddy/service_base.hpp"

namespace godaddy {

class ShoppersService final : public BaseService {
public:
    explicit ShoppersService(ApiClient& client);
    Result createSubaccount(const Value& subaccount);
    Result get(const Value& shopperId, const Value& includes = {});
    Result update(const Value& shopperId, const Value& shopper);
    Result delete(const Value& shopperId, const Value& auditClientIp);
    Result getStatus(const Value& shopperId, const Value& auditClientIp);
    Result changePassword(const Value& shopperId, const Value& secret);
};

}  // namespace godaddy
