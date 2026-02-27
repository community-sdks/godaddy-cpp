#pragma once

#include <memory>

#include "godaddy/api_client.hpp"
#include "godaddy/services/abuse_service.hpp"
#include "godaddy/services/aftermarket_service.hpp"
#include "godaddy/services/agreements_service.hpp"
#include "godaddy/services/ans_service.hpp"
#include "godaddy/services/auctions_service.hpp"
#include "godaddy/services/certificates_service.hpp"
#include "godaddy/services/countries_service.hpp"
#include "godaddy/services/domains_service.hpp"
#include "godaddy/services/orders_service.hpp"
#include "godaddy/services/parking_service.hpp"
#include "godaddy/services/shoppers_service.hpp"
#include "godaddy/services/subscriptions_service.hpp"

namespace godaddy {

class Client final {
public:
    explicit Client(Config config = {}, std::shared_ptr<Transport> transport = nullptr);
    ApiClient& api_client() noexcept { return api_client_; }
    AbuseService& abuse() noexcept { return *abuse_; }
    AftermarketService& aftermarket() noexcept { return *aftermarket_; }
    AgreementsService& agreements() noexcept { return *agreements_; }
    AnsService& ans() noexcept { return *ans_; }
    AuctionsService& auctions() noexcept { return *auctions_; }
    CertificatesService& certificates() noexcept { return *certificates_; }
    CountriesService& countries() noexcept { return *countries_; }
    DomainsService& domains() noexcept { return *domains_; }
    OrdersService& orders() noexcept { return *orders_; }
    ParkingService& parking() noexcept { return *parking_; }
    ShoppersService& shoppers() noexcept { return *shoppers_; }
    SubscriptionsService& subscriptions() noexcept { return *subscriptions_; }

private:
    ApiClient api_client_;
    std::unique_ptr<AbuseService> abuse_;
    std::unique_ptr<AftermarketService> aftermarket_;
    std::unique_ptr<AgreementsService> agreements_;
    std::unique_ptr<AnsService> ans_;
    std::unique_ptr<AuctionsService> auctions_;
    std::unique_ptr<CertificatesService> certificates_;
    std::unique_ptr<CountriesService> countries_;
    std::unique_ptr<DomainsService> domains_;
    std::unique_ptr<OrdersService> orders_;
    std::unique_ptr<ParkingService> parking_;
    std::unique_ptr<ShoppersService> shoppers_;
    std::unique_ptr<SubscriptionsService> subscriptions_;
};

}  // namespace godaddy
