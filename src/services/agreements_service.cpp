#include "godaddy/services/agreements_service.hpp"

namespace godaddy {

AgreementsService::AgreementsService(ApiClient& client) : BaseService(client, "agreements") {}

Result AgreementsService::get(const Value& keys, const Value& xPrivateLabelId, const Value& xMarketId) {
    return call(
        "GET",
        "/v1/agreements",
        {},
        {{"keys", keys}},
        {{"X-Private-Label-Id", xPrivateLabelId}, {"X-Market-Id", xMarketId}},
        Value{}
    );
}

}  // namespace godaddy
