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
auto response = client.auctions().placeBids(
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"}
);
```

```json
{
  "listingId": 200000,
  "bidId": "bid_001",
  "bidAmountUsd": 1500,
  "status": "ACTIVE",
  "isHighestBidder": true
}
```





