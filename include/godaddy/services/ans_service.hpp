#pragma once

#include "godaddy/service_base.hpp"

namespace godaddy {

class AnsService final : public BaseService {
public:
    explicit AnsService(ApiClient& client);
    Result search(const Value& agentDisplayName = {}, const Value& version = {}, const Value& agentHost = {}, const Value& protocol = {}, const Value& limit = {}, const Value& offset = {});
    Result registerAgent(const Value& body);
    Result resolve(const Value& body);
    Result get(const Value& agentId);
    Result verifyAcme(const Value& agentId);
    Result verifyDns(const Value& agentId);
    Result getIdentityCertificates(const Value& agentId);
    Result submitIdentityCsr(const Value& agentId, const Value& body);
    Result getServerCertificates(const Value& agentId);
    Result submitServerCsr(const Value& agentId, const Value& body);
    Result getCsrStatus(const Value& agentId, const Value& csrId);
    Result events(const Value& xRequestId = {}, const Value& providerId = {}, const Value& lastLogId = {}, const Value& limit = {});
    Result revoke(const Value& agentId, const Value& body);
};

}  // namespace godaddy
