#include "godaddy/services/shoppers_service.hpp"

namespace godaddy {

ShoppersService::ShoppersService(ApiClient& client) : BaseService(client, "shoppers") {}

Result ShoppersService::createSubaccount(const Value& subaccount) {
    return call(
        "POST",
        "/v1/shoppers/subaccount",
        {},
        {},
        {},
        subaccount
    );
}

Result ShoppersService::get(const Value& shopperId, const Value& includes) {
    return call(
        "GET",
        "/v1/shoppers/{shopperId}",
        {{"shopperId", shopperId}},
        {{"includes", includes}},
        {},
        Value{}
    );
}

Result ShoppersService::update(const Value& shopperId, const Value& shopper) {
    return call(
        "POST",
        "/v1/shoppers/{shopperId}",
        {{"shopperId", shopperId}},
        {},
        {},
        shopper
    );
}

Result ShoppersService::deleteShopper(const Value& shopperId, const Value& auditClientIp) {
    return call(
        "DELETE",
        "/v1/shoppers/{shopperId}",
        {{"shopperId", shopperId}},
        {{"auditClientIp", auditClientIp}},
        {},
        Value{}
    );
}

Result ShoppersService::getStatus(const Value& shopperId, const Value& auditClientIp) {
    return call(
        "GET",
        "/v1/shoppers/{shopperId}/status",
        {{"shopperId", shopperId}},
        {{"auditClientIp", auditClientIp}},
        {},
        Value{}
    );
}

Result ShoppersService::changePassword(const Value& shopperId, const Value& secret) {
    return call(
        "PUT",
        "/v1/shoppers/{shopperId}/factors/password",
        {{"shopperId", shopperId}},
        {},
        {},
        secret
    );
}

}  // namespace godaddy
