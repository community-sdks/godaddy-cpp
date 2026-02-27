#pragma once

#include "godaddy/service_base.hpp"

namespace godaddy {

class CertificatesService final : public BaseService {
public:
    explicit CertificatesService(ApiClient& client);
    Result certificateCreate(const Value& certificateCreate, const Value& xMarketId = {});
    Result certificateValidate(const Value& certificateCreate, const Value& xMarketId = {});
    Result certificateGet(const Value& certificateId);
    Result certificateActionRetrieve(const Value& certificateId);
    Result certificateResendEmail(const Value& certificateId, const Value& emailId);
    Result certificateAlternateEmailAddress(const Value& certificateId, const Value& emailAddress);
    Result certificateResendEmailAddress(const Value& certificateId, const Value& emailId, const Value& emailAddress);
    Result certificateEmailHistory(const Value& certificateId);
    Result certificateCallbackDelete(const Value& certificateId);
    Result certificateCallbackGet(const Value& certificateId);
    Result certificateCallbackReplace(const Value& certificateId, const Value& callbackUrl);
    Result certificateCancel(const Value& certificateId);
    Result certificateDownload(const Value& certificateId);
    Result certificateReissue(const Value& certificateId, const Value& reissueCreate);
    Result certificateRenew(const Value& certificateId, const Value& renewCreate);
    Result certificateRevoke(const Value& certificateId, const Value& certificateRevoke);
    Result certificateSitesealGet(const Value& certificateId, const Value& theme = {}, const Value& locale = {});
    Result certificateVerifydomaincontrol(const Value& certificateId);
    Result certificateGetEntitlement(const Value& entitlementId, const Value& latest = {});
    Result certificateCreateV2(const Value& subscriptionCertificateCreate, const Value& xMarketId = {});
    Result certificateDownloadEntitlement(const Value& entitlementId);
    Result getCustomerCertificatesByCustomerId(const Value& customerId, const Value& offset = {}, const Value& limit = {});
    Result getCertificateDetailByCertIdentifier(const Value& customerId, const Value& certificateId);
    Result getDomainInformationByCertificateId(const Value& customerId, const Value& certificateId);
    Result getDomainDetailsByDomain(const Value& customerId, const Value& certificateId, const Value& domain);
    Result getAcmeExternalAccountBinding(const Value& customerId);
    Result retrieveSslByDomainReseller(const Value& pageSize = {}, const Value& page = {}, const Value& domain = {}, const Value& status = {}, const Value& typeValue = {}, const Value& validation = {});
    Result retrieveSslByDomainSubscriptionReseller(const Value& guid, const Value& pageSize = {}, const Value& page = {}, const Value& domain = {}, const Value& status = {}, const Value& typeValue = {}, const Value& validation = {});
};

}  // namespace godaddy
