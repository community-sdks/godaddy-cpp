# OrdersService

Order lookup endpoints for commerce and fulfillment status.

## Accessor

```cpp
auto& service = client.orders();
```

## Endpoints

### list

Calls `GET /v1/orders`.

```cpp
auto response = client.orders().list(
    std::string{"123456"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::int64_t{1},
    std::int64_t{1},
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "orders": [
    {
      "orderId": "1234567890",
      "currency": "USD",
      "createdAt": "2026-03-11T12:00:00Z"
    }
  ],
  "pagination": {
    "total": 1,
    "next": null
  }
}
```

### get

Calls `GET /v1/orders/{orderId}`.

```cpp
auto response = client.orders().get(
    std::string{"example.com"},
    std::string{"123456"},
    std::string{"123456"},
    std::string{"123456"}
);
```

```json
{
  "orderId": "1234567890",
  "currency": "USD",
  "createdAt": "2026-03-11T12:00:00Z",
  "status": "PENDING",
  "pricing": {
    "total": "14.99"
  },
  "items": [
    {
      "itemId": "line-1",
      "label": "example.com",
      "status": "PENDING"
    }
  ]
}
```





