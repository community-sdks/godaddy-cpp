#include "godaddy/client.hpp"

namespace godaddy {

Client::Client(Config config, std::shared_ptr<Transport> transport) : api_client_(std::move(config), std::move(transport)) {
    abuse_ = std::make_unique<AbuseService>(api_client_);
    aftermarket_ = std::make_unique<AftermarketService>(api_client_);
    agreements_ = std::make_unique<AgreementsService>(api_client_);
    ans_ = std::make_unique<AnsService>(api_client_);
    auctions_ = std::make_unique<AuctionsService>(api_client_);
    certificates_ = std::make_unique<CertificatesService>(api_client_);
    countries_ = std::make_unique<CountriesService>(api_client_);
    domains_ = std::make_unique<DomainsService>(api_client_);
    orders_ = std::make_unique<OrdersService>(api_client_);
    parking_ = std::make_unique<ParkingService>(api_client_);
    shoppers_ = std::make_unique<ShoppersService>(api_client_);
    subscriptions_ = std::make_unique<SubscriptionsService>(api_client_);
}

Result BaseService::call(const std::string& method, const std::string& path, const std::vector<Param>& path_params,
                         const std::vector<Param>& query_params, const std::vector<Param>& headers, const Value& body) const {
    return client_.request(method, base_url_, path, path_params, query_params, headers, body);
}

}  // namespace godaddy
