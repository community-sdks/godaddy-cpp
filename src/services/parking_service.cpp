#include "godaddy/services/parking_service.hpp"

namespace godaddy {

ParkingService::ParkingService(ApiClient& client) : BaseService(client, "parking") {}

Result ParkingService::getMetrics(const Value& customerId, const Value& periodStartPtz, const Value& periodEndPtz, const Value& limit, const Value& offset, const Value& xRequestId) {
    return call(
        "GET",
        "/v1/customers/{customerId}/parking/metrics",
        {{"customerId", customerId}},
        {{"periodStartPtz", periodStartPtz}, {"periodEndPtz", periodEndPtz}, {"limit", limit}, {"offset", offset}},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result ParkingService::getMetricsByDomain(const Value& customerId, const Value& startDate, const Value& endDate, const Value& domains, const Value& domainLike, const Value& portfolioId, const Value& limit, const Value& offset, const Value& xRequestId) {
    return call(
        "GET",
        "/v1/customers/{customerId}/parking/metricsByDomain",
        {{"customerId", customerId}},
        {{"startDate", startDate}, {"endDate", endDate}, {"domains", domains}, {"domainLike", domainLike}, {"portfolioId", portfolioId}, {"limit", limit}, {"offset", offset}},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

}  // namespace godaddy
