# ParkingService

Domain parking optimization and template management endpoints.

## Accessor

```cpp
auto& service = client.parking();
```

## Endpoints

### getMetrics

Calls `GET /v1/customers/{customerId}/parking/metrics`.

```cpp
auto response = client.parking().getMetrics(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::int64_t{1}, std::int64_t{1}, std::string{"header-value"});
```

```json
{}
```

### getMetricsByDomain

Calls `GET /v1/customers/{customerId}/parking/metricsByDomain`.

```cpp
auto response = client.parking().getMetricsByDomain(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::vector<std::string>{"sample"}, std::string{"sample"}, std::string{"sample"}, std::int64_t{1}, std::int64_t{1}, std::string{"header-value"});
```

```json
{}
```

