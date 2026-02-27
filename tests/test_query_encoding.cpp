#include <cassert>

#include "godaddy/api_client.hpp"

void test_query_encoding() {
    auto pairs = godaddy::ApiClient::build_query_pairs({{"items", std::vector<std::string>{"a", "b"}}});
    assert(pairs.size() == 2);
    assert(pairs[0].first == "items" && pairs[0].second == "a");
    assert(pairs[1].first == "items" && pairs[1].second == "b");
}
