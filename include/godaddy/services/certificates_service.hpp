#pragma once

#include "godaddy/service_base.hpp"

namespace godaddy {

class CertificatesService final : public BaseService {
public:
    explicit CertificatesService(ApiClient& client);
    Result create(const Value& create, const Value& xMarketId = {});
    Result validate(const Value& create, const Value& xMarketId = {});
    Result get(const Value& certificateId);
    Result listActions(const Value& certificateId);
    Result resendEmail(const Value& certificateId, const Value& emailId);
    Result addAlternateEmailAddress(const Value& certificateId, const Value& emailAddress);
    Result resendEmailToAddress(const Value& certificateId, const Value& emailId, const Value& emailAddress);
    Result getEmailHistory(const Value& certificateId);
    Result deleteCallback(const Value& certificateId);
    Result getCallback(const Value& certificateId);
    Result replaceCallback(const Value& certificateId, const Value& callbackUrl);
    Result cancel(const Value& certificateId);
    Result download(const Value& certificateId);
    Result reissue(const Value& certificateId, const Value& reissueCreate);
    Result renew(const Value& certificateId, const Value& renewCreate);
    Result revoke(const Value& certificateId, const Value& revoke);
    Result getSiteSeal(const Value& certificateId, const Value& theme = {}, const Value& locale = {});
    Result verifyDomainControl(const Value& certificateId);
    Result getByEntitlement(const Value& entitlementId, const Value& latest = {});
    Result createForEntitlement(const Value& subscriptionCertificateCreate, const Value& xMarketId = {});
    Result downloadByEntitlement(const Value& entitlementId);
    Result listCustomerCertificates(const Value& customerId, const Value& offset = {}, const Value& limit = {});
    Result getCustomerCertificate(const Value& customerId, const Value& certificateId);
    Result listDomainVerifications(const Value& customerId, const Value& certificateId);
    Result getDomainVerificationDetails(const Value& customerId, const Value& certificateId, const Value& domain);
    Result getAcmeExternalAccountBinding(const Value& customerId);
    Result searchSubscriptionsByDomain(const Value& pageSize = {}, const Value& page = {}, const Value& domain = {}, const Value& status = {}, const Value& typeValue = {}, const Value& validation = {});
    Result listSubscriptionCertificates(const Value& guid, const Value& pageSize = {}, const Value& page = {}, const Value& domain = {}, const Value& status = {}, const Value& typeValue = {}, const Value& validation = {});
};

}  // namespace godaddy

