# AuctionsService

Auction listing discovery endpoints for GoDaddy Auctions inventory.

## Accessor

```cpp
auto& service = client.auctions();
```

## Endpoints

### placeBids

Calls `POST /v1/customers/{customerId}/aftermarket/listings/bids`.

```cpp
auto response = client.auctions().placeBids(std::string{"sample"}, std::string{"{\"sample\":true}"});
```

```json
{}
```

