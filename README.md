# GoDaddy C++ SDK

A community-maintained C++ SDK for the provided GoDaddy OpenAPI specs.

## Build

Using vcpkg manifest mode (recommended):

```bash
cmake -S . -B build -DCMAKE_TOOLCHAIN_FILE="$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake"
cmake --build build
```

Or plain CMake:

```bash
cmake -S . -B build
cmake --build build
```

## Getting Started

```cpp
#include <godaddy/client.hpp>
#include <iostream>

int main() {
    auto config = godaddy::sandbox_config("your-api-key", "your-api-secret");

    godaddy::Client client(config);
    auto response = client.domains().tlds();
    std::cout << response.as_string() << std::endl;
}
```

## Configuration

- `godaddy::sandbox_config(api_key, api_secret)` uses `https://api.ote-godaddy.com`
- `godaddy::production_config(api_key, api_secret)` uses `https://api.godaddy.com`

You can still construct `godaddy::Config` directly when you need full control.

```cpp
godaddy::Config config = godaddy::production_config("your-api-key", "your-api-secret");
config.timeout = std::chrono::milliseconds{60000};
config.max_retries = 3;
config.default_headers["X-Custom-Header"] = "value";
```

## Service Base URL Overrides

You can override base URLs per service using `service_base_urls`.

```cpp
godaddy::Config config = godaddy::sandbox_config("your-api-key", "your-api-secret");
config.service_base_urls["domains"] = "https://api.godaddy.com";
config.service_base_urls["certificates"] = "https://api.godaddy.com";

godaddy::Client client(config);
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
