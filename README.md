# GoDaddy C++ SDK

A community-maintained C++ SDK for the provided GoDaddy OpenAPI specs.

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Getting Started

```cpp
#include <godaddy/client.hpp>
#include <iostream>

int main() {
    godaddy::Config config;
    config.api_key = "your-api-key";
    config.api_secret = "your-api-secret";

    godaddy::Client client(config);
    auto response = client.domains().tlds();
    std::cout << response.as_string() << std::endl;
}
```

## Services

- [AbuseService](./docs/abuse.md): Abuse reporting and ticket lookup endpoints for phishing, malware, and related investigations.
- [AftermarketService](./docs/aftermarket.md): Aftermarket listing and sales endpoints for secondary-market domain workflows.
- [AgreementsService](./docs/agreements.md): Agreement retrieval endpoints for legal terms and consent workflows.
- [AnsService](./docs/ans.md): Authoritative DNS record and nameserver management endpoints.
- [AuctionsService](./docs/auctions.md): Auction listing discovery endpoints for GoDaddy Auctions inventory.
- [CertificatesService](./docs/certificates.md): SSL certificate purchase, validation, lifecycle, and revocation endpoints.
- [CountriesService](./docs/countries.md): Country and market metadata endpoints used across purchase flows.
- [DomainsService](./docs/domains.md): Domain availability, purchase, management, transfer, and DNS endpoints.
- [OrdersService](./docs/orders.md): Order lookup endpoints for commerce and fulfillment status.
- [ParkingService](./docs/parking.md): Domain parking optimization and template management endpoints.
- [ShoppersService](./docs/shoppers.md): Shopper profile, account, and delegated access endpoints.
- [SubscriptionsService](./docs/subscriptions.md): Subscription listing and management endpoints for recurring products.
