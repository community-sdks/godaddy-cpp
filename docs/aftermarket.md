# AftermarketService

Aftermarket listing and sales endpoints for secondary-market domain workflows.

## Accessor

```cpp
auto& service = client.aftermarket();
```

## Endpoints

### getListings

Calls `GET /v1/customers/{customerId}/auctions/listings`.

```cpp
auto response = client.aftermarket().getListings(std::string{"sample"}, std::vector<std::string>{"sample"}, std::vector<std::string>{"sample"}, std::string{"sample"}, std::string{"sample"}, std::int64_t{1}, std::int64_t{1});
```

```json
{}
```

### deleteListings

Calls `DELETE /v1/aftermarket/listings`.

```cpp
auto response = client.aftermarket().deleteListings(std::vector<std::string>{"sample"});
```

```json
{}
```

### addExpiryListings

Calls `POST /v1/aftermarket/listings/expiry`.

```cpp
auto response = client.aftermarket().addExpiryListings(std::vector<std::string>{"sample"});
```

```json
{}
```

