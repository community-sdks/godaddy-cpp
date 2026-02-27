#pragma once

#include "godaddy/service_base.hpp"

namespace godaddy {

class ParkingService final : public BaseService {
public:
    explicit ParkingService(ApiClient& client);
    Result getMetrics(const Value& customerId, const Value& periodStartPtz = {}, const Value& periodEndPtz = {}, const Value& limit = {}, const Value& offset = {}, const Value& xRequestId = {});
    Result getMetricsByDomain(const Value& customerId, const Value& startDate, const Value& endDate, const Value& domains = {}, const Value& domainLike = {}, const Value& portfolioId = {}, const Value& limit = {}, const Value& offset = {}, const Value& xRequestId = {});
};

}  // namespace godaddy
