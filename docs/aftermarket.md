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
auto response = client.aftermarket().getListings(
    std::string{"example.com"},
    std::vector<std::string>{"example.com"},
    std::vector<std::string>{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::int64_t{1},
    std::int64_t{1}
);
```

```json
{
  "listings": [
    {
      "fqdn": "example.com",
      "listingId": 1001,
      "listingStatus": "ACTIVE",
      "price": 2499,
      "currency": "USD"
    }
  ],
  "pagination": {
    "total": 1,
    "start": 0,
    "limit": 20
  }
}
```

### deleteListings

Calls `DELETE /v1/aftermarket/listings`.

```cpp
auto response = client.aftermarket().deleteListings(
    std::vector<std::string>{"example.com"}
);
```

```json
{
  "listingActionId": 900122
}
```

### addExpiryListings

Calls `POST /v1/aftermarket/listings/expiry`.

```cpp
auto response = client.aftermarket().addExpiryListings(
    std::vector<std::string>{"example.com"}
);
```

```json
{
  "listingActionId": 900122
}
```





