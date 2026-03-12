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
        client.abuse().createTicket(std::string{"123456"});
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
        client.abuse().createTicketV2(std::string{"123456"});
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
        client.ans().search(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::int64_t{1}, std::int64_t{1});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().registerAgent(std::string{"123456"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().resolve(std::string{"123456"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().get(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().verifyAcme(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().verifyDns(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().getIdentityCertificates(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().submitIdentityCsr(std::string{"sample"}, std::string{"123456"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().getServerCertificates(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().submitServerCsr(std::string{"sample"}, std::string{"123456"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().getCsrStatus(std::string{"sample"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.ans().events(std::string{"header-value"}, std::string{"sample"}, std::string{"sample"}, std::int64_t{1});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.auctions().placeBids(std::string{"sample"}, std::string{"123456"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().create(std::string{"123456"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().validate(std::string{"123456"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().get(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().listActions(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().resendEmail(std::string{"sample"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().addAlternateEmailAddress(std::string{"sample"}, std::vector<std::string>{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().resendEmailToAddress(std::string{"sample"}, std::string{"sample"}, std::vector<std::string>{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().getEmailHistory(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().deleteCallback(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "DELETE");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().getCallback(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().replaceCallback(std::string{"sample"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PUT");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().cancel(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().download(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().reissue(std::string{"sample"}, std::string{"123456"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().renew(std::string{"sample"}, std::string{"123456"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().revoke(std::string{"sample"}, std::string{"123456"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().getSiteSeal(std::string{"sample"}, std::string{"sample"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().verifyDomainControl(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().getByEntitlement(std::string{"sample"}, true);
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().createForEntitlement(std::string{"123456"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().downloadByEntitlement(std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().listCustomerCertificates(std::string{"sample"}, std::int64_t{1}, std::int64_t{1});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().getCustomerCertificate(std::string{"sample"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().listDomainVerifications(std::string{"sample"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().getDomainVerificationDetails(std::string{"sample"}, std::string{"sample"}, std::string{"sample"});
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
        client.certificates().searchSubscriptionsByDomain(std::int64_t{1}, std::int64_t{1}, std::string{"sample"}, std::vector<std::string>{"sample"}, std::string{"sample"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.certificates().listSubscriptionCertificates(std::string{"sample"}, std::int64_t{1}, std::int64_t{1}, std::string{"sample"}, std::vector<std::string>{"sample"}, std::string{"sample"}, std::string{"sample"});
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
        client.domains().contactsValidate(std::string{"123456"}, std::string{"header-value"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().purchase(std::string{"123456"}, std::string{"header-value"});
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
        client.domains().validate(std::string{"123456"});
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
        client.domains().update(std::string{"sample"}, std::string{"123456"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PATCH");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().updateContacts(std::string{"sample"}, std::string{"123456"}, std::string{"header-value"});
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
        client.domains().purchasePrivacy(std::string{"sample"}, std::string{"123456"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().recordAdd(std::string{"sample"}, std::string{"123456"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PATCH");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().recordReplace(std::string{"sample"}, std::string{"123456"}, std::string{"header-value"});
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
        client.domains().recordReplaceTypeName(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"123456"}, std::string{"header-value"});
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
        client.domains().recordReplaceType(std::string{"sample"}, std::string{"sample"}, std::string{"123456"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PUT");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().renew(std::string{"sample"}, std::string{"header-value"}, std::string{"123456"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().transferIn(std::string{"sample"}, std::string{"123456"}, std::string{"header-value"});
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
        client.domains().getCustomerDomain(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"}, std::vector<std::string>{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().cancelCustomerDomainChangeOfRegistrant(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "DELETE");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getCustomerDomainChangeOfRegistrant(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().addCustomerDomainDnssecRecords(std::string{"sample"}, std::string{"sample"}, std::string{"123456"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PATCH");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().removeCustomerDomainDnssecRecords(std::string{"sample"}, std::string{"sample"}, std::string{"123456"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "DELETE");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().replaceCustomerDomainNameServers(std::string{"sample"}, std::string{"sample"}, std::string{"123456"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PUT");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getCustomerDomainPrivacyForwarding(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().updateCustomerDomainPrivacyForwarding(std::string{"sample"}, std::string{"sample"}, std::string{"123456"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PATCH");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().redeemCustomerDomain(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"}, std::string{"123456"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().renewCustomerDomain(std::string{"sample"}, std::string{"sample"}, std::string{"123456"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().transferCustomerDomain(std::string{"sample"}, std::string{"sample"}, std::string{"123456"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getCustomerDomainTransferStatus(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().validateCustomerDomainTransfer(std::string{"sample"}, std::string{"sample"}, std::string{"123456"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().acceptCustomerDomainTransferIn(std::string{"sample"}, std::string{"sample"}, std::string{"123456"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().cancelCustomerDomainTransferIn(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().restartCustomerDomainTransferIn(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().retryCustomerDomainTransferIn(std::string{"sample"}, std::string{"sample"}, std::string{"123456"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().initiateCustomerDomainTransferOut(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().acceptCustomerDomainTransferOut(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().rejectCustomerDomainTransferOut(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().deleteDomainForwarding(std::string{"sample"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "DELETE");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getDomainForwarding(std::string{"sample"}, std::string{"sample"}, true);
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().updateDomainForwarding(std::string{"sample"}, std::string{"sample"}, std::string{"123456"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PUT");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().createDomainForwarding(std::string{"sample"}, std::string{"sample"}, std::string{"123456"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().listCustomerDomainActions(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().cancelCustomerDomainAction(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "DELETE");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getCustomerDomainAction(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getCustomerDomainNotifications(std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getCustomerDomainNotificationOptIns(std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().updateCustomerDomainNotificationOptIns(std::string{"sample"}, std::vector<std::string>{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PUT");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getCustomerDomainNotificationSchema(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().acknowledgeCustomerDomainNotification(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().registerCustomerDomain(std::string{"sample"}, std::string{"123456"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getCustomerDomainRegisterSchema(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().validateCustomerDomainRegister(std::string{"sample"}, std::string{"123456"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().listDomainMaintenances(std::string{"header-value"}, std::vector<std::string>{"sample"}, std::string{"sample"}, std::string{"sample"}, std::int64_t{1});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getDomainMaintenance(std::string{"sample"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().getDomainUsage(std::string{"sample"}, std::string{"header-value"}, std::vector<std::string>{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().updateCustomerDomainContacts(std::string{"sample"}, std::string{"sample"}, std::string{"123456"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PATCH");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.domains().regenerateCustomerDomainAuthCode(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
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
        client.shoppers().createSubaccount(std::string{"123456"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.shoppers().get(std::string{"123456"}, std::vector<std::string>{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.shoppers().update(std::string{"123456"}, std::string{"123456"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "POST");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.shoppers().deleteShopper(std::string{"123456"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "DELETE");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.shoppers().getStatus(std::string{"123456"}, std::string{"sample"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.shoppers().changePassword(std::string{"123456"}, std::string{"123456"});
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
        client.subscriptions().cancel(std::string{"123456"}, std::string{"header-value"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "DELETE");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.subscriptions().get(std::string{"123456"}, std::string{"header-value"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "GET");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }

    {
        transport->responses.push_back({200, {{"content-type", "application/json"}}, "{}"});
        const auto before = transport->requests.size();
        client.subscriptions().update(std::string{"123456"}, std::string{"header-value"}, std::string{"123456"}, std::string{"header-value"});
        const auto& request = transport->requests.at(before);
        assert(request.method == "PATCH");
        assert(request.headers.at("Authorization") == "sso-key key:secret");
        assert(request.url.find('{') == std::string::npos);
    }
}





