#pragma once

#include "godaddy/service_base.hpp"

namespace godaddy {

class AnsService final : public BaseService {
public:
    explicit AnsService(ApiClient& client);
    Result searchAnsName(const Value& agentDisplayName = {}, const Value& version = {}, const Value& agentHost = {}, const Value& protocol = {}, const Value& limit = {}, const Value& offset = {});
    Result registerAgent(const Value& body);
    Result resolveAnsName(const Value& body);
    Result getAgent(const Value& agentId);
    Result validateRegistration(const Value& agentId);
    Result verifyDnsRecords(const Value& agentId);
    Result getAgentIdentityCertificateByAgentId(const Value& agentId);
    Result submitAgentIdentityCsrByAgentId(const Value& agentId, const Value& body);
    Result getAgentServerCertificateByAgentId(const Value& agentId);
    Result submitAgentServerCsrByAgentId(const Value& agentId, const Value& body);
    Result getAgentCsrStatusByAgentId(const Value& agentId, const Value& csrId);
    Result getAgentEvents(const Value& xRequestId = {}, const Value& providerId = {}, const Value& lastLogId = {}, const Value& limit = {});
};

}  // namespace godaddy
