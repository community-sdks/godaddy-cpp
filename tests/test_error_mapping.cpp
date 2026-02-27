#include <cassert>

#include "godaddy/client.hpp"
#include "godaddy/errors.hpp"

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

void test_error_mapping() {
    auto transport = std::make_shared<MockTransport>();
    godaddy::Config config;
    config.api_key = "key";
    config.api_secret = "secret";
    config.max_retries = 0;
    godaddy::Client client(config, transport);

    transport->responses.push_back({400, {{"content-type", "application/json"}}, "{}"});
    bool threw = false;
    try { client.abuse().getTickets(); } catch (const godaddy::ValidationException&) { threw = true; }
    assert(threw);
}
