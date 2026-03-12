# ShoppersService

Shopper profile, account, and delegated access endpoints.

## Accessor

```cpp
auto& service = client.shoppers();
```

## Endpoints

### createSubaccount

Calls `POST /v1/shoppers/subaccount`.

```cpp
auto response = client.shoppers().createSubaccount(
    std::string{R"({"domain":"example.com"})"}
);
```

```json
{
  "shopperId": "987654321",
  "customerId": "123456789"
}
```

### get

Calls `GET /v1/shoppers/{shopperId}`.

```cpp
auto response = client.shoppers().get(
    std::string{R"({"domain":"example.com"})"},
    std::vector<std::string>{"example.com"}
);
```

```json
{
  "shopperId": "987654321",
  "nameFirst": "Jane",
  "nameLast": "Doe",
  "email": "admin@example.com",
  "marketId": "en-US",
  "customerId": "123456789"
}
```

### update

Calls `POST /v1/shoppers/{shopperId}`.

```cpp
auto response = client.shoppers().update(
    std::string{R"({"domain":"example.com"})"},
    std::string{R"({"domain":"example.com"})"}
);
```

```json
{
  "shopperId": "987654321",
  "customerId": "123456789"
}
```

### delete

Calls `DELETE /v1/shoppers/{shopperId}`.

```cpp
auto response = client.shoppers().deleteShopper(
    std::string{R"({"domain":"example.com"})"},
    std::string{"example.com"}
);
```

```json
{
  "deleted": true
}
```

### getStatus

Calls `GET /v1/shoppers/{shopperId}/status`.

```cpp
auto response = client.shoppers().getStatus(
    std::string{R"({"domain":"example.com"})"},
    std::string{"example.com"}
);
```

```json
{
  "billingState": "ACTIVE"
}
```

### changePassword

Calls `PUT /v1/shoppers/{shopperId}/factors/password`.

```cpp
auto response = client.shoppers().changePassword(
    std::string{R"({"domain":"example.com"})"},
    std::string{R"({"domain":"example.com"})"}
);
```

```json
{
  "shopperId": "987654321",
  "customerId": "123456789"
}
```





