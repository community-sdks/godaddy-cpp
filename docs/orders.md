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
auto response = client.orders().list(std::string{"header-value"}, std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::int64_t{1}, std::int64_t{1}, std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### get

Calls `GET /v1/orders/{orderId}`.

```cpp
auto response = client.orders().get(std::string{"sample"}, std::string{"header-value"}, std::string{"header-value"}, std::string{"header-value"});
```

```json
{}
```

