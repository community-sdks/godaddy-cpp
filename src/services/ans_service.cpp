#include "godaddy/services/ans_service.hpp"

namespace godaddy {

AnsService::AnsService(ApiClient& client) : BaseService(client, "ans") {}

Result AnsService::search(const Value& agentDisplayName, const Value& version, const Value& agentHost, const Value& protocol, const Value& limit, const Value& offset) {
    return call(
        "GET",
        "/v1/agents",
        {},
        {{"agentDisplayName", agentDisplayName}, {"version", version}, {"agentHost", agentHost}, {"protocol", protocol}, {"limit", limit}, {"offset", offset}},
        {},
        Value{}
    );
}

Result AnsService::registerAgent(const Value& body) {
    return call(
        "POST",
        "/v1/agents/register",
        {},
        {},
        {},
        body
    );
}

Result AnsService::resolve(const Value& body) {
    return call(
        "POST",
        "/v1/agents/resolution",
        {},
        {},
        {},
        body
    );
}

Result AnsService::get(const Value& agentId) {
    return call(
        "GET",
        "/v1/agents/{agentId}",
        {{"agentId", agentId}},
        {},
        {},
        Value{}
    );
}

Result AnsService::verifyAcme(const Value& agentId) {
    return call(
        "POST",
        "/v1/agents/{agentId}/verify-acme",
        {{"agentId", agentId}},
        {},
        {},
        Value{}
    );
}

Result AnsService::verifyDns(const Value& agentId) {
    return call(
        "POST",
        "/v1/agents/{agentId}/verify-dns",
        {{"agentId", agentId}},
        {},
        {},
        Value{}
    );
}

Result AnsService::getIdentityCertificates(const Value& agentId) {
    return call(
        "GET",
        "/v1/agents/{agentId}/certificates/identity",
        {{"agentId", agentId}},
        {},
        {},
        Value{}
    );
}

Result AnsService::submitIdentityCsr(const Value& agentId, const Value& body) {
    return call(
        "POST",
        "/v1/agents/{agentId}/certificates/identity",
        {{"agentId", agentId}},
        {},
        {},
        body
    );
}

Result AnsService::getServerCertificates(const Value& agentId) {
    return call(
        "GET",
        "/v1/agents/{agentId}/certificates/server",
        {{"agentId", agentId}},
        {},
        {},
        Value{}
    );
}

Result AnsService::submitServerCsr(const Value& agentId, const Value& body) {
    return call(
        "POST",
        "/v1/agents/{agentId}/certificates/server",
        {{"agentId", agentId}},
        {},
        {},
        body
    );
}

Result AnsService::getCsrStatus(const Value& agentId, const Value& csrId) {
    return call(
        "GET",
        "/v1/agents/{agentId}/csrs/{csrId}/status",
        {{"agentId", agentId}, {"csrId", csrId}},
        {},
        {},
        Value{}
    );
}

Result AnsService::events(const Value& xRequestId, const Value& providerId, const Value& lastLogId, const Value& limit) {
    return call(
        "GET",
        "/v1/agents/events",
        {},
        {{"providerId", providerId}, {"lastLogId", lastLogId}, {"limit", limit}},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result AnsService::revoke(const Value& agentId, const Value& body) {
    return call(
        "POST",
        "/v1/agents/{agentId}/revoke",
        {{"agentId", agentId}},
        {},
        {},
        body
    );
}

}  // namespace godaddy
