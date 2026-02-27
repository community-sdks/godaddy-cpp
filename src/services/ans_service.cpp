#include "godaddy/services/ans_service.hpp"

namespace godaddy {

AnsService::AnsService(ApiClient& client) : BaseService(client, "https://api.ote-godaddy.com") {}

Result AnsService::searchAnsName(const Value& agentDisplayName, const Value& version, const Value& agentHost, const Value& protocol, const Value& limit, const Value& offset) {
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

Result AnsService::resolveAnsName(const Value& body) {
    return call(
        "POST",
        "/v1/agents/resolution",
        {},
        {},
        {},
        body
    );
}

Result AnsService::getAgent(const Value& agentId) {
    return call(
        "GET",
        "/v1/agents/{agentId}",
        {{"agentId", agentId}},
        {},
        {},
        Value{}
    );
}

Result AnsService::validateRegistration(const Value& agentId) {
    return call(
        "POST",
        "/v1/agents/{agentId}/verify-acme",
        {{"agentId", agentId}},
        {},
        {},
        Value{}
    );
}

Result AnsService::verifyDnsRecords(const Value& agentId) {
    return call(
        "POST",
        "/v1/agents/{agentId}/verify-dns",
        {{"agentId", agentId}},
        {},
        {},
        Value{}
    );
}

Result AnsService::getAgentIdentityCertificateByAgentId(const Value& agentId) {
    return call(
        "GET",
        "/v1/agents/{agentId}/certificates/identity",
        {{"agentId", agentId}},
        {},
        {},
        Value{}
    );
}

Result AnsService::submitAgentIdentityCsrByAgentId(const Value& agentId, const Value& body) {
    return call(
        "POST",
        "/v1/agents/{agentId}/certificates/identity",
        {{"agentId", agentId}},
        {},
        {},
        body
    );
}

Result AnsService::getAgentServerCertificateByAgentId(const Value& agentId) {
    return call(
        "GET",
        "/v1/agents/{agentId}/certificates/server",
        {{"agentId", agentId}},
        {},
        {},
        Value{}
    );
}

Result AnsService::submitAgentServerCsrByAgentId(const Value& agentId, const Value& body) {
    return call(
        "POST",
        "/v1/agents/{agentId}/certificates/server",
        {{"agentId", agentId}},
        {},
        {},
        body
    );
}

Result AnsService::getAgentCsrStatusByAgentId(const Value& agentId, const Value& csrId) {
    return call(
        "GET",
        "/v1/agents/{agentId}/csrs/{csrId}/status",
        {{"agentId", agentId}, {"csrId", csrId}},
        {},
        {},
        Value{}
    );
}

Result AnsService::getAgentEvents(const Value& xRequestId, const Value& providerId, const Value& lastLogId, const Value& limit) {
    return call(
        "GET",
        "/v1/agents/events",
        {},
        {{"providerId", providerId}, {"lastLogId", lastLogId}, {"limit", limit}},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

}  // namespace godaddy
