#include "godaddy/services/certificates_service.hpp"

namespace godaddy {

CertificatesService::CertificatesService(ApiClient& client) : BaseService(client, "https://api.ote-godaddy.com") {}

Result CertificatesService::certificateCreate(const Value& certificateCreate, const Value& xMarketId) {
    return call(
        "POST",
        "/v1/certificates",
        {},
        {},
        {{"X-Market-Id", xMarketId}},
        certificateCreate
    );
}

Result CertificatesService::certificateValidate(const Value& certificateCreate, const Value& xMarketId) {
    return call(
        "POST",
        "/v1/certificates/validate",
        {},
        {},
        {{"X-Market-Id", xMarketId}},
        certificateCreate
    );
}

Result CertificatesService::certificateGet(const Value& certificateId) {
    return call(
        "GET",
        "/v1/certificates/{certificateId}",
        {{"certificateId", certificateId}},
        {},
        {},
        Value{}
    );
}

Result CertificatesService::certificateActionRetrieve(const Value& certificateId) {
    return call(
        "GET",
        "/v1/certificates/{certificateId}/actions",
        {{"certificateId", certificateId}},
        {},
        {},
        Value{}
    );
}

Result CertificatesService::certificateResendEmail(const Value& certificateId, const Value& emailId) {
    return call(
        "POST",
        "/v1/certificates/{certificateId}/email/{emailId}/resend",
        {{"certificateId", certificateId}, {"emailId", emailId}},
        {},
        {},
        Value{}
    );
}

Result CertificatesService::certificateAlternateEmailAddress(const Value& certificateId, const Value& emailAddress) {
    return call(
        "POST",
        "/v1/certificates/{certificateId}/email/resend/{emailAddress}",
        {{"certificateId", certificateId}, {"emailAddress", emailAddress}},
        {},
        {},
        Value{}
    );
}

Result CertificatesService::certificateResendEmailAddress(const Value& certificateId, const Value& emailId, const Value& emailAddress) {
    return call(
        "POST",
        "/v1/certificates/{certificateId}/email/{emailId}/resend/{emailAddress}",
        {{"certificateId", certificateId}, {"emailId", emailId}, {"emailAddress", emailAddress}},
        {},
        {},
        Value{}
    );
}

Result CertificatesService::certificateEmailHistory(const Value& certificateId) {
    return call(
        "GET",
        "/v1/certificates/{certificateId}/email/history",
        {{"certificateId", certificateId}},
        {},
        {},
        Value{}
    );
}

Result CertificatesService::certificateCallbackDelete(const Value& certificateId) {
    return call(
        "DELETE",
        "/v1/certificates/{certificateId}/callback",
        {{"certificateId", certificateId}},
        {},
        {},
        Value{}
    );
}

Result CertificatesService::certificateCallbackGet(const Value& certificateId) {
    return call(
        "GET",
        "/v1/certificates/{certificateId}/callback",
        {{"certificateId", certificateId}},
        {},
        {},
        Value{}
    );
}

Result CertificatesService::certificateCallbackReplace(const Value& certificateId, const Value& callbackUrl) {
    return call(
        "PUT",
        "/v1/certificates/{certificateId}/callback",
        {{"certificateId", certificateId}},
        {{"callbackUrl", callbackUrl}},
        {},
        Value{}
    );
}

Result CertificatesService::certificateCancel(const Value& certificateId) {
    return call(
        "POST",
        "/v1/certificates/{certificateId}/cancel",
        {{"certificateId", certificateId}},
        {},
        {},
        Value{}
    );
}

Result CertificatesService::certificateDownload(const Value& certificateId) {
    return call(
        "GET",
        "/v1/certificates/{certificateId}/download",
        {{"certificateId", certificateId}},
        {},
        {},
        Value{}
    );
}

Result CertificatesService::certificateReissue(const Value& certificateId, const Value& reissueCreate) {
    return call(
        "POST",
        "/v1/certificates/{certificateId}/reissue",
        {{"certificateId", certificateId}},
        {},
        {},
        reissueCreate
    );
}

Result CertificatesService::certificateRenew(const Value& certificateId, const Value& renewCreate) {
    return call(
        "POST",
        "/v1/certificates/{certificateId}/renew",
        {{"certificateId", certificateId}},
        {},
        {},
        renewCreate
    );
}

Result CertificatesService::certificateRevoke(const Value& certificateId, const Value& certificateRevoke) {
    return call(
        "POST",
        "/v1/certificates/{certificateId}/revoke",
        {{"certificateId", certificateId}},
        {},
        {},
        certificateRevoke
    );
}

Result CertificatesService::certificateSitesealGet(const Value& certificateId, const Value& theme, const Value& locale) {
    return call(
        "GET",
        "/v1/certificates/{certificateId}/siteSeal",
        {{"certificateId", certificateId}},
        {{"theme", theme}, {"locale", locale}},
        {},
        Value{}
    );
}

Result CertificatesService::certificateVerifydomaincontrol(const Value& certificateId) {
    return call(
        "POST",
        "/v1/certificates/{certificateId}/verifyDomainControl",
        {{"certificateId", certificateId}},
        {},
        {},
        Value{}
    );
}

Result CertificatesService::certificateGetEntitlement(const Value& entitlementId, const Value& latest) {
    return call(
        "GET",
        "/v2/certificates",
        {},
        {{"entitlementId", entitlementId}, {"latest", latest}},
        {},
        Value{}
    );
}

Result CertificatesService::certificateCreateV2(const Value& subscriptionCertificateCreate, const Value& xMarketId) {
    return call(
        "POST",
        "/v2/certificates",
        {},
        {},
        {{"X-Market-Id", xMarketId}},
        subscriptionCertificateCreate
    );
}

Result CertificatesService::certificateDownloadEntitlement(const Value& entitlementId) {
    return call(
        "GET",
        "/v2/certificates/download",
        {},
        {{"entitlementId", entitlementId}},
        {},
        Value{}
    );
}

Result CertificatesService::getCustomerCertificatesByCustomerId(const Value& customerId, const Value& offset, const Value& limit) {
    return call(
        "GET",
        "/v2/customers/{customerId}/certificates",
        {{"customerId", customerId}},
        {{"offset", offset}, {"limit", limit}},
        {},
        Value{}
    );
}

Result CertificatesService::getCertificateDetailByCertIdentifier(const Value& customerId, const Value& certificateId) {
    return call(
        "GET",
        "/v2/customers/{customerId}/certificates/{certificateId}",
        {{"customerId", customerId}, {"certificateId", certificateId}},
        {},
        {},
        Value{}
    );
}

Result CertificatesService::getDomainInformationByCertificateId(const Value& customerId, const Value& certificateId) {
    return call(
        "GET",
        "/v2/customers/{customerId}/certificates/{certificateId}/domainVerifications",
        {{"customerId", customerId}, {"certificateId", certificateId}},
        {},
        {},
        Value{}
    );
}

Result CertificatesService::getDomainDetailsByDomain(const Value& customerId, const Value& certificateId, const Value& domain) {
    return call(
        "GET",
        "/v2/customers/{customerId}/certificates/{certificateId}/domainVerifications/{domain}",
        {{"customerId", customerId}, {"certificateId", certificateId}, {"domain", domain}},
        {},
        {},
        Value{}
    );
}

Result CertificatesService::getAcmeExternalAccountBinding(const Value& customerId) {
    return call(
        "GET",
        "/v2/customers/{customerId}/certificates/acme/externalAccountBinding",
        {{"customerId", customerId}},
        {},
        {},
        Value{}
    );
}

Result CertificatesService::retrieveSslByDomainReseller(const Value& pageSize, const Value& page, const Value& domain, const Value& status, const Value& typeValue, const Value& validation) {
    return call(
        "GET",
        "/v2/certificates/subscriptions/search",
        {},
        {{"pageSize", pageSize}, {"page", page}, {"domain", domain}, {"status", status}, {"type", typeValue}, {"validation", validation}},
        {},
        Value{}
    );
}

Result CertificatesService::retrieveSslByDomainSubscriptionReseller(const Value& guid, const Value& pageSize, const Value& page, const Value& domain, const Value& status, const Value& typeValue, const Value& validation) {
    return call(
        "GET",
        "/v2/certificates/subscription/{guid}",
        {{"guid", guid}},
        {{"pageSize", pageSize}, {"page", page}, {"domain", domain}, {"status", status}, {"type", typeValue}, {"validation", validation}},
        {},
        Value{}
    );
}

}  // namespace godaddy
