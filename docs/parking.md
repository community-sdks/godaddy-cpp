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
auto response = client.parking().getMetrics(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::int64_t{1},
    std::int64_t{1},
    std::string{"123456"}
);
```

```json
{
  "currencyId": "USD",
  "metrics": [
    {
      "periodPtz": "2026-03-11",
      "visitCount": 120,
      "adClickCount": 14,
      "revenue": 3450
    }
  ],
  "pagination": {
    "total": 1,
    "next": null
  }
}
```

### getMetricsByDomain

Calls `GET /v1/customers/{customerId}/parking/metricsByDomain`.

```cpp
auto response = client.parking().getMetricsByDomain(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::vector<std::string>{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::int64_t{1},
    std::int64_t{1},
    std::string{"123456"}
);
```

```json
{
  "currencyId": "USD",
  "startDate": "2026-03-01",
  "endDate": "2026-03-11",
  "metrics": [
    {
      "domain": "example.com",
      "visitCount": 120,
      "pageViewCount": 200,
      "revenue": 3450
    }
  ],
  "pagination": {
    "total": 1,
    "next": null
  }
}
```





