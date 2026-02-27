#include <cassert>
#include <memory>
#include <vector>

#include "godaddy/client.hpp"

namespace {

class MockTransport final : public godaddy::Transport {
public:
    std::vector<godaddy::Response> responses;
    std::vector<godaddy::Request> requests;

    godaddy::Response send(const godaddy::Request& request) override {
        requests.push_back(request);
        if (responses.empty()) return {200, {{"content-type", "application/json"}}, "{}"};
        const auto response = responses.front();
        responses.erase(responses.begin());
        return response;
    }
};

}  // namespace

void test_generated_services() {
    auto transport = std::make_shared<MockTransport>();
    godaddy::Config config;
    config.api_key = "key";
    config.api_secret = "secret";
    config.max_retries = 0;
    godaddy::Client client(config, transport);

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.abuse().getTickets(std::string{"sample"}, true, std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::int64_t{1}, std::int64_t{1});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.abuse().createTicket(std::string{"{\"sample\":true}"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.abuse().getTicketInfo(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.abuse().getTicketsV2(std::string{"sample"}, true, std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::int64_t{1}, std::int64_t{1});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.abuse().createTicketV2(std::string{"{\"sample\":true}"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.abuse().getTicketInfoV2(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.aftermarket().getListings(std::string{"sample"}, std::vector<std::string>{"sample"}, std::vector<std::string>{"sample"}, std::string{"sample"}, std::string{"sample"}, std::int64_t{1}, std::int64_t{1});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.aftermarket().deleteListings(std::vector<std::string>{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "DELETE");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.aftermarket().addExpiryListings(std::vector<std::string>{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.agreements().get(std::vector<std::string>{"sample"}, std::string{"header-value"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().searchAnsName(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::int64_t{1}, std::int64_t{1});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().registerAgent(std::string{"{\"sample\":true}"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().resolveAnsName(std::string{"{\"sample\":true}"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().getAgent(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().validateRegistration(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().verifyDnsRecords(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().getAgentIdentityCertificateByAgentId(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().submitAgentIdentityCsrByAgentId(std::string{"sample"}, std::string{"{\"sample\":true}"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().getAgentServerCertificateByAgentId(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().submitAgentServerCsrByAgentId(std::string{"sample"}, std::string{"{\"sample\":true}"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().getAgentCsrStatusByAgentId(std::string{"sample"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().getAgentEvents(std::string{"header-value"}, std::string{"sample"}, std::string{"sample"}, std::int64_t{1});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.auctions().placeBids(std::string{"sample"}, std::string{"{\"sample\":true}"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().certificateCreate(std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().certificateValidate(std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().certificateGet(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().certificateActionRetrieve(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().certificateResendEmail(std::string{"sample"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().certificateAlternateEmailAddress(std::string{"sample"}, std::vector<std::string>{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().certificateResendEmailAddress(std::string{"sample"}, std::string{"sample"}, std::vector<std::string>{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().certificateEmailHistory(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().certificateCallbackDelete(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "DELETE");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().certificateCallbackGet(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().certificateCallbackReplace(std::string{"sample"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PUT");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().certificateCancel(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().certificateDownload(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().certificateReissue(std::string{"sample"}, std::string{"{\"sample\":true}"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().certificateRenew(std::string{"sample"}, std::string{"{\"sample\":true}"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().certificateRevoke(std::string{"sample"}, std::string{"{\"sample\":true}"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().certificateSitesealGet(std::string{"sample"}, std::string{"sample"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().certificateVerifydomaincontrol(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().certificateGetEntitlement(std::string{"sample"}, true);
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().certificateCreateV2(std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().certificateDownloadEntitlement(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().getCustomerCertificatesByCustomerId(std::string{"sample"}, std::int64_t{1}, std::int64_t{1});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().getCertificateDetailByCertIdentifier(std::string{"sample"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().getDomainInformationByCertificateId(std::string{"sample"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().getDomainDetailsByDomain(std::string{"sample"}, std::string{"sample"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().getAcmeExternalAccountBinding(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().retrieveSslByDomainReseller(std::int64_t{1}, std::int64_t{1}, std::string{"sample"}, std::vector<std::string>{"sample"}, std::string{"sample"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().retrieveSslByDomainSubscriptionReseller(std::string{"sample"}, std::int64_t{1}, std::int64_t{1}, std::string{"sample"}, std::vector<std::string>{"sample"}, std::string{"sample"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.countries().getCountries(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.countries().getCountry(std::string{"sample"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().list(std::string{"header-value"}, std::vector<std::string>{"sample"}, std::vector<std::string>{"sample"}, std::int64_t{1}, std::string{"sample"}, std::vector<std::string>{"sample"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getAgreement(std::vector<std::string>{"sample"}, true, std::string{"header-value"}, true);
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().available(std::string{"sample"}, std::string{"sample"}, true);
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().availableBulk(std::vector<std::string>{"sample"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().contactsValidate(std::string{"{\"sample\":true}"}, std::string{"header-value"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().purchase(std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().schema(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().validate(std::string{"{\"sample\":true}"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().suggest(std::string{"header-value"}, std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::vector<std::string>{"sample"}, std::vector<std::string>{"sample"}, std::int64_t{1}, std::int64_t{1}, std::int64_t{1}, std::int64_t{1});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().tlds();
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().cancel(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "DELETE");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().get(std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().update(std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PATCH");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().updateContacts(std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PATCH");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().cancelPrivacy(std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "DELETE");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().purchasePrivacy(std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().recordAdd(std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PATCH");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().recordReplace(std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PUT");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().recordGet(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"header-value"}, std::int64_t{1}, std::int64_t{1});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().recordReplaceTypeName(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PUT");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().recordDeleteTypeName(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "DELETE");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().recordReplaceType(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PUT");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().renew(std::string{"sample"}, std::string{"header-value"}, std::string{"{\"sample\":true}"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().transferIn(std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().verifyEmail(std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getV2CustomersCustomerIdDomainsDomain(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"}, std::vector<std::string>{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().deleteV2CustomersCustomerIdDomainsDomainChangeOfRegistrant(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "DELETE");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getV2CustomersCustomerIdDomainsDomainChangeOfRegistrant(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().patchV2CustomersCustomerIdDomainsDomainDnssecRecords(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PATCH");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().deleteV2CustomersCustomerIdDomainsDomainDnssecRecords(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "DELETE");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().putV2CustomersCustomerIdDomainsDomainNameServers(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PUT");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getV2CustomersCustomerIdDomainsDomainPrivacyForwarding(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().patchV2CustomersCustomerIdDomainsDomainPrivacyForwarding(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PATCH");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().postV2CustomersCustomerIdDomainsDomainRedeem(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"}, std::string{"{\"sample\":true}"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().postV2CustomersCustomerIdDomainsDomainRenew(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().postV2CustomersCustomerIdDomainsDomainTransfer(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getV2CustomersCustomerIdDomainsDomainTransfer(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().postV2CustomersCustomerIdDomainsDomainTransferValidate(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().postV2CustomersCustomerIdDomainsDomainTransferInAccept(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().postV2CustomersCustomerIdDomainsDomainTransferInCancel(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().postV2CustomersCustomerIdDomainsDomainTransferInRestart(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().postV2CustomersCustomerIdDomainsDomainTransferInRetry(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().postV2CustomersCustomerIdDomainsDomainTransferOut(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().postV2CustomersCustomerIdDomainsDomainTransferOutAccept(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().postV2CustomersCustomerIdDomainsDomainTransferOutReject(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().domainsForwardsDelete(std::string{"sample"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "DELETE");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().domainsForwardsGet(std::string{"sample"}, std::string{"sample"}, true);
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().domainsForwardsPut(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PUT");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().domainsForwardsPost(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getV2CustomersCustomerIdDomainsDomainActions(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().deleteV2CustomersCustomerIdDomainsDomainActionsType(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "DELETE");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getV2CustomersCustomerIdDomainsDomainActionsType(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getV2CustomersCustomerIdDomainsNotifications(std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getV2CustomersCustomerIdDomainsNotificationsOptIn(std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().putV2CustomersCustomerIdDomainsNotificationsOptIn(std::string{"sample"}, std::vector<std::string>{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PUT");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getV2CustomersCustomerIdDomainsNotificationsSchemasType(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().postV2CustomersCustomerIdDomainsNotificationsNotificationIdAcknowledge(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().postV2CustomersCustomerIdDomainsRegister(std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getV2CustomersCustomerIdDomainsRegisterSchemaTld(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().postV2CustomersCustomerIdDomainsRegisterValidate(std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getV2DomainsMaintenances(std::string{"header-value"}, std::vector<std::string>{"sample"}, std::string{"sample"}, std::string{"sample"}, std::int64_t{1});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getV2DomainsMaintenancesMaintenanceId(std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getV2DomainsUsageYyyymm(std::string{"sample"}, std::string{"header-value"}, std::vector<std::string>{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().patchV2CustomersCustomerIdDomainsDomainContacts(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PATCH");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().postV2CustomersCustomerIdDomainsDomainRegenerateAuthCode(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.orders().list(std::string{"header-value"}, std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::int64_t{1}, std::int64_t{1}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.orders().get(std::string{"sample"}, std::string{"header-value"}, std::string{"header-value"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.parking().getMetrics(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::int64_t{1}, std::int64_t{1}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.parking().getMetricsByDomain(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::vector<std::string>{"sample"}, std::string{"sample"}, std::string{"sample"}, std::int64_t{1}, std::int64_t{1}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.shoppers().createSubaccount(std::string{"{\"sample\":true}"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.shoppers().get(std::string{"{\"sample\":true}"}, std::vector<std::string>{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.shoppers().update(std::string{"{\"sample\":true}"}, std::string{"{\"sample\":true}"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.shoppers().delete(std::string{"{\"sample\":true}"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "DELETE");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.shoppers().getStatus(std::string{"{\"sample\":true}"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.shoppers().changePassword(std::string{"{\"sample\":true}"}, std::string{"{\"sample\":true}"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PUT");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.subscriptions().list(std::string{"header-value"}, std::string{"header-value"}, std::string{"header-value"}, std::vector<std::string>{"sample"}, std::vector<std::string>{"sample"}, std::int64_t{1}, std::int64_t{1}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.subscriptions().productGroups(std::string{"header-value"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.subscriptions().cancel(std::string{"{\"sample\":true}"}, std::string{"header-value"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "DELETE");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.subscriptions().get(std::string{"{\"sample\":true}"}, std::string{"header-value"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.subscriptions().update(std::string{"{\"sample\":true}"}, std::string{"header-value"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PATCH");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }
}
