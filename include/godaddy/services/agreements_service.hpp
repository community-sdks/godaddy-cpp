#pragma once

#include "godaddy/service_base.hpp"

namespace godaddy {

class AgreementsService final : public BaseService {
public:
    explicit AgreementsService(ApiClient& client);
    Result get(const Value& keys, const Value& xPrivateLabelId = {}, const Value& xMarketId = {});
};

}  // namespace godaddy
