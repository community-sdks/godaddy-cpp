# SubscriptionsService

Subscription listing and management endpoints for recurring products.

## Accessor

```cpp
auto& service = client.subscriptions();
```

## Endpoints

### list

Calls `GET /v1/subscriptions`.

```cpp
auto response = client.subscriptions().list(
    std::string{"123456"},
    std::string{"123456"},
    std::string{"123456"},
    std::vector<std::string>{"example.com"},
    std::vector<std::string>{"example.com"},
    std::int64_t{1},
    std::int64_t{1},
    std::string{"example.com"}
);
```

```json
{
  "subscriptions": [
    {
      "subscriptionId": "sub_123456",
      "status": "ACTIVE",
      "renewAuto": true
    }
  ],
  "pagination": {
    "total": 1,
    "next": null
  }
}
```

### productGroups

Calls `GET /v1/subscriptions/productGroups`.

```cpp
auto response = client.subscriptions().productGroups(
    std::string{"123456"},
    std::string{"123456"}
);
```

```json
{
  "productGroups": [
    {
      "productGroupKey": "domains",
      "subscriptionCount": 1
    }
  ]
}
```

### cancel

Calls `DELETE /v1/subscriptions/{subscriptionId}`.

```cpp
auto response = client.subscriptions().cancel(
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"},
    std::string{"123456"}
);
```

```json
{
  "subscriptionId": "sub_123456",
  "status": "CANCELLED"
}
```

### get

Calls `GET /v1/subscriptions/{subscriptionId}`.

```cpp
auto response = client.subscriptions().get(
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"},
    std::string{"123456"}
);
```

```json
{
  "subscriptionId": "sub_123456",
  "status": "ACTIVE",
  "label": "My Subscription",
  "renewAuto": true
}
```

### update

Calls `PATCH /v1/subscriptions/{subscriptionId}`.

```cpp
auto response = client.subscriptions().update(
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"},
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "subscriptionId": "sub_123456",
  "status": "ACTIVE"
}
```





