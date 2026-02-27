#include "godaddy/services/domains_service.hpp"

namespace godaddy {

DomainsService::DomainsService(ApiClient& client) : BaseService(client, "https://api.ote-godaddy.com") {}

Result DomainsService::list(const Value& xShopperId, const Value& statuses, const Value& statusGroups, const Value& limit, const Value& marker, const Value& includes, const Value& modifiedDate) {
    return call(
        "GET",
        "/v1/domains",
        {},
        {{"statuses", statuses}, {"statusGroups", statusGroups}, {"limit", limit}, {"marker", marker}, {"includes", includes}, {"modifiedDate", modifiedDate}},
        {{"X-Shopper-Id", xShopperId}},
        Value{}
    );
}

Result DomainsService::getAgreement(const Value& tlds, const Value& privacy, const Value& xMarketId, const Value& forTransfer) {
    return call(
        "GET",
        "/v1/domains/agreements",
        {},
        {{"tlds", tlds}, {"privacy", privacy}, {"forTransfer", forTransfer}},
        {{"X-Market-Id", xMarketId}},
        Value{}
    );
}

Result DomainsService::available(const Value& domain, const Value& checkType, const Value& forTransfer) {
    return call(
        "GET",
        "/v1/domains/available",
        {},
        {{"domain", domain}, {"checkType", checkType}, {"forTransfer", forTransfer}},
        {},
        Value{}
    );
}

Result DomainsService::availableBulk(const Value& domains, const Value& checkType) {
    return call(
        "POST",
        "/v1/domains/available",
        {},
        {{"checkType", checkType}},
        {},
        domains
    );
}

Result DomainsService::contactsValidate(const Value& body, const Value& xPrivateLabelId, const Value& marketId) {
    return call(
        "POST",
        "/v1/domains/contacts/validate",
        {},
        {{"marketId", marketId}},
        {{"X-Private-Label-Id", xPrivateLabelId}},
        body
    );
}

Result DomainsService::purchase(const Value& body, const Value& xShopperId) {
    return call(
        "POST",
        "/v1/domains/purchase",
        {},
        {},
        {{"X-Shopper-Id", xShopperId}},
        body
    );
}

Result DomainsService::schema(const Value& tld) {
    return call(
        "GET",
        "/v1/domains/purchase/schema/{tld}",
        {{"tld", tld}},
        {},
        {},
        Value{}
    );
}

Result DomainsService::validate(const Value& body) {
    return call(
        "POST",
        "/v1/domains/purchase/validate",
        {},
        {},
        {},
        body
    );
}

Result DomainsService::suggest(const Value& xShopperId, const Value& query, const Value& country, const Value& city, const Value& sources, const Value& tlds, const Value& lengthMax, const Value& lengthMin, const Value& limit, const Value& waitMs) {
    return call(
        "GET",
        "/v1/domains/suggest",
        {},
        {{"query", query}, {"country", country}, {"city", city}, {"sources", sources}, {"tlds", tlds}, {"lengthMax", lengthMax}, {"lengthMin", lengthMin}, {"limit", limit}, {"waitMs", waitMs}},
        {{"X-Shopper-Id", xShopperId}},
        Value{}
    );
}

Result DomainsService::tlds() {
    return call(
        "GET",
        "/v1/domains/tlds",
        {},
        {},
        {},
        Value{}
    );
}

Result DomainsService::cancel(const Value& domain) {
    return call(
        "DELETE",
        "/v1/domains/{domain}",
        {{"domain", domain}},
        {},
        {},
        Value{}
    );
}

Result DomainsService::get(const Value& domain, const Value& xShopperId) {
    return call(
        "GET",
        "/v1/domains/{domain}",
        {{"domain", domain}},
        {},
        {{"X-Shopper-Id", xShopperId}},
        Value{}
    );
}

Result DomainsService::update(const Value& domain, const Value& body, const Value& xShopperId) {
    return call(
        "PATCH",
        "/v1/domains/{domain}",
        {{"domain", domain}},
        {},
        {{"X-Shopper-Id", xShopperId}},
        body
    );
}

Result DomainsService::updateContacts(const Value& domain, const Value& contacts, const Value& xShopperId) {
    return call(
        "PATCH",
        "/v1/domains/{domain}/contacts",
        {{"domain", domain}},
        {},
        {{"X-Shopper-Id", xShopperId}},
        contacts
    );
}

Result DomainsService::cancelPrivacy(const Value& domain, const Value& xShopperId) {
    return call(
        "DELETE",
        "/v1/domains/{domain}/privacy",
        {{"domain", domain}},
        {},
        {{"X-Shopper-Id", xShopperId}},
        Value{}
    );
}

Result DomainsService::purchasePrivacy(const Value& domain, const Value& body, const Value& xShopperId) {
    return call(
        "POST",
        "/v1/domains/{domain}/privacy/purchase",
        {{"domain", domain}},
        {},
        {{"X-Shopper-Id", xShopperId}},
        body
    );
}

Result DomainsService::recordAdd(const Value& domain, const Value& records, const Value& xShopperId) {
    return call(
        "PATCH",
        "/v1/domains/{domain}/records",
        {{"domain", domain}},
        {},
        {{"X-Shopper-Id", xShopperId}},
        records
    );
}

Result DomainsService::recordReplace(const Value& domain, const Value& records, const Value& xShopperId) {
    return call(
        "PUT",
        "/v1/domains/{domain}/records",
        {{"domain", domain}},
        {},
        {{"X-Shopper-Id", xShopperId}},
        records
    );
}

Result DomainsService::recordGet(const Value& domain, const Value& typeValue, const Value& name, const Value& xShopperId, const Value& offset, const Value& limit) {
    return call(
        "GET",
        "/v1/domains/{domain}/records/{type}/{name}",
        {{"domain", domain}, {"type", typeValue}, {"name", name}},
        {{"offset", offset}, {"limit", limit}},
        {{"X-Shopper-Id", xShopperId}},
        Value{}
    );
}

Result DomainsService::recordReplaceTypeName(const Value& domain, const Value& typeValue, const Value& name, const Value& records, const Value& xShopperId) {
    return call(
        "PUT",
        "/v1/domains/{domain}/records/{type}/{name}",
        {{"domain", domain}, {"type", typeValue}, {"name", name}},
        {},
        {{"X-Shopper-Id", xShopperId}},
        records
    );
}

Result DomainsService::recordDeleteTypeName(const Value& domain, const Value& typeValue, const Value& name, const Value& xShopperId) {
    return call(
        "DELETE",
        "/v1/domains/{domain}/records/{type}/{name}",
        {{"domain", domain}, {"type", typeValue}, {"name", name}},
        {},
        {{"X-Shopper-Id", xShopperId}},
        Value{}
    );
}

Result DomainsService::recordReplaceType(const Value& domain, const Value& typeValue, const Value& records, const Value& xShopperId) {
    return call(
        "PUT",
        "/v1/domains/{domain}/records/{type}",
        {{"domain", domain}, {"type", typeValue}},
        {},
        {{"X-Shopper-Id", xShopperId}},
        records
    );
}

Result DomainsService::renew(const Value& domain, const Value& xShopperId, const Value& body) {
    return call(
        "POST",
        "/v1/domains/{domain}/renew",
        {{"domain", domain}},
        {},
        {{"X-Shopper-Id", xShopperId}},
        body
    );
}

Result DomainsService::transferIn(const Value& domain, const Value& body, const Value& xShopperId) {
    return call(
        "POST",
        "/v1/domains/{domain}/transfer",
        {{"domain", domain}},
        {},
        {{"X-Shopper-Id", xShopperId}},
        body
    );
}

Result DomainsService::verifyEmail(const Value& domain, const Value& xShopperId) {
    return call(
        "POST",
        "/v1/domains/{domain}/verifyRegistrantEmail",
        {{"domain", domain}},
        {},
        {{"X-Shopper-Id", xShopperId}},
        Value{}
    );
}

Result DomainsService::getV2CustomersCustomerIdDomainsDomain(const Value& customerId, const Value& domain, const Value& xRequestId, const Value& includes) {
    return call(
        "GET",
        "/v2/customers/{customerId}/domains/{domain}",
        {{"customerId", customerId}, {"domain", domain}},
        {{"includes", includes}},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::deleteV2CustomersCustomerIdDomainsDomainChangeOfRegistrant(const Value& customerId, const Value& domain, const Value& xRequestId) {
    return call(
        "DELETE",
        "/v2/customers/{customerId}/domains/{domain}/changeOfRegistrant",
        {{"customerId", customerId}, {"domain", domain}},
        {},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::getV2CustomersCustomerIdDomainsDomainChangeOfRegistrant(const Value& customerId, const Value& domain, const Value& xRequestId) {
    return call(
        "GET",
        "/v2/customers/{customerId}/domains/{domain}/changeOfRegistrant",
        {{"customerId", customerId}, {"domain", domain}},
        {},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::patchV2CustomersCustomerIdDomainsDomainDnssecRecords(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId) {
    return call(
        "PATCH",
        "/v2/customers/{customerId}/domains/{domain}/dnssecRecords",
        {{"customerId", customerId}, {"domain", domain}},
        {},
        {{"X-Request-Id", xRequestId}},
        body
    );
}

Result DomainsService::deleteV2CustomersCustomerIdDomainsDomainDnssecRecords(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId) {
    return call(
        "DELETE",
        "/v2/customers/{customerId}/domains/{domain}/dnssecRecords",
        {{"customerId", customerId}, {"domain", domain}},
        {},
        {{"X-Request-Id", xRequestId}},
        body
    );
}

Result DomainsService::putV2CustomersCustomerIdDomainsDomainNameServers(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId) {
    return call(
        "PUT",
        "/v2/customers/{customerId}/domains/{domain}/nameServers",
        {{"customerId", customerId}, {"domain", domain}},
        {},
        {{"X-Request-Id", xRequestId}},
        body
    );
}

Result DomainsService::getV2CustomersCustomerIdDomainsDomainPrivacyForwarding(const Value& customerId, const Value& domain, const Value& xRequestId) {
    return call(
        "GET",
        "/v2/customers/{customerId}/domains/{domain}/privacy/forwarding",
        {{"customerId", customerId}, {"domain", domain}},
        {},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::patchV2CustomersCustomerIdDomainsDomainPrivacyForwarding(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId) {
    return call(
        "PATCH",
        "/v2/customers/{customerId}/domains/{domain}/privacy/forwarding",
        {{"customerId", customerId}, {"domain", domain}},
        {},
        {{"X-Request-Id", xRequestId}},
        body
    );
}

Result DomainsService::postV2CustomersCustomerIdDomainsDomainRedeem(const Value& customerId, const Value& domain, const Value& xRequestId, const Value& body) {
    return call(
        "POST",
        "/v2/customers/{customerId}/domains/{domain}/redeem",
        {{"customerId", customerId}, {"domain", domain}},
        {},
        {{"X-Request-Id", xRequestId}},
        body
    );
}

Result DomainsService::postV2CustomersCustomerIdDomainsDomainRenew(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId) {
    return call(
        "POST",
        "/v2/customers/{customerId}/domains/{domain}/renew",
        {{"customerId", customerId}, {"domain", domain}},
        {},
        {{"X-Request-Id", xRequestId}},
        body
    );
}

Result DomainsService::postV2CustomersCustomerIdDomainsDomainTransfer(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId) {
    return call(
        "POST",
        "/v2/customers/{customerId}/domains/{domain}/transfer",
        {{"customerId", customerId}, {"domain", domain}},
        {},
        {{"X-Request-Id", xRequestId}},
        body
    );
}

Result DomainsService::getV2CustomersCustomerIdDomainsDomainTransfer(const Value& customerId, const Value& domain, const Value& xRequestId) {
    return call(
        "GET",
        "/v2/customers/{customerId}/domains/{domain}/transfer",
        {{"customerId", customerId}, {"domain", domain}},
        {},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::postV2CustomersCustomerIdDomainsDomainTransferValidate(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId) {
    return call(
        "POST",
        "/v2/customers/{customerId}/domains/{domain}/transfer/validate",
        {{"customerId", customerId}, {"domain", domain}},
        {},
        {{"X-Request-Id", xRequestId}},
        body
    );
}

Result DomainsService::postV2CustomersCustomerIdDomainsDomainTransferInAccept(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId) {
    return call(
        "POST",
        "/v2/customers/{customerId}/domains/{domain}/transferInAccept",
        {{"customerId", customerId}, {"domain", domain}},
        {},
        {{"X-Request-Id", xRequestId}},
        body
    );
}

Result DomainsService::postV2CustomersCustomerIdDomainsDomainTransferInCancel(const Value& customerId, const Value& domain, const Value& xRequestId) {
    return call(
        "POST",
        "/v2/customers/{customerId}/domains/{domain}/transferInCancel",
        {{"customerId", customerId}, {"domain", domain}},
        {},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::postV2CustomersCustomerIdDomainsDomainTransferInRestart(const Value& customerId, const Value& domain, const Value& xRequestId) {
    return call(
        "POST",
        "/v2/customers/{customerId}/domains/{domain}/transferInRestart",
        {{"customerId", customerId}, {"domain", domain}},
        {},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::postV2CustomersCustomerIdDomainsDomainTransferInRetry(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId) {
    return call(
        "POST",
        "/v2/customers/{customerId}/domains/{domain}/transferInRetry",
        {{"customerId", customerId}, {"domain", domain}},
        {},
        {{"X-Request-Id", xRequestId}},
        body
    );
}

Result DomainsService::postV2CustomersCustomerIdDomainsDomainTransferOut(const Value& customerId, const Value& domain, const Value& registrar, const Value& xRequestId) {
    return call(
        "POST",
        "/v2/customers/{customerId}/domains/{domain}/transferOut",
        {{"customerId", customerId}, {"domain", domain}},
        {{"registrar", registrar}},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::postV2CustomersCustomerIdDomainsDomainTransferOutAccept(const Value& customerId, const Value& domain, const Value& xRequestId) {
    return call(
        "POST",
        "/v2/customers/{customerId}/domains/{domain}/transferOutAccept",
        {{"customerId", customerId}, {"domain", domain}},
        {},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::postV2CustomersCustomerIdDomainsDomainTransferOutReject(const Value& customerId, const Value& domain, const Value& xRequestId, const Value& reason) {
    return call(
        "POST",
        "/v2/customers/{customerId}/domains/{domain}/transferOutReject",
        {{"customerId", customerId}, {"domain", domain}},
        {{"reason", reason}},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::domainsForwardsDelete(const Value& customerId, const Value& fqdn) {
    return call(
        "DELETE",
        "/v2/customers/{customerId}/domains/forwards/{fqdn}",
        {{"customerId", customerId}, {"fqdn", fqdn}},
        {},
        {},
        Value{}
    );
}

Result DomainsService::domainsForwardsGet(const Value& customerId, const Value& fqdn, const Value& includeSubs) {
    return call(
        "GET",
        "/v2/customers/{customerId}/domains/forwards/{fqdn}",
        {{"customerId", customerId}, {"fqdn", fqdn}},
        {{"includeSubs", includeSubs}},
        {},
        Value{}
    );
}

Result DomainsService::domainsForwardsPut(const Value& customerId, const Value& fqdn, const Value& body) {
    return call(
        "PUT",
        "/v2/customers/{customerId}/domains/forwards/{fqdn}",
        {{"customerId", customerId}, {"fqdn", fqdn}},
        {},
        {},
        body
    );
}

Result DomainsService::domainsForwardsPost(const Value& customerId, const Value& fqdn, const Value& body) {
    return call(
        "POST",
        "/v2/customers/{customerId}/domains/forwards/{fqdn}",
        {{"customerId", customerId}, {"fqdn", fqdn}},
        {},
        {},
        body
    );
}

Result DomainsService::getV2CustomersCustomerIdDomainsDomainActions(const Value& customerId, const Value& domain, const Value& xRequestId) {
    return call(
        "GET",
        "/v2/customers/{customerId}/domains/{domain}/actions",
        {{"customerId", customerId}, {"domain", domain}},
        {},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::deleteV2CustomersCustomerIdDomainsDomainActionsType(const Value& customerId, const Value& domain, const Value& typeValue, const Value& xRequestId) {
    return call(
        "DELETE",
        "/v2/customers/{customerId}/domains/{domain}/actions/{type}",
        {{"customerId", customerId}, {"domain", domain}, {"type", typeValue}},
        {},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::getV2CustomersCustomerIdDomainsDomainActionsType(const Value& customerId, const Value& domain, const Value& typeValue, const Value& xRequestId) {
    return call(
        "GET",
        "/v2/customers/{customerId}/domains/{domain}/actions/{type}",
        {{"customerId", customerId}, {"domain", domain}, {"type", typeValue}},
        {},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::getV2CustomersCustomerIdDomainsNotifications(const Value& customerId, const Value& xRequestId) {
    return call(
        "GET",
        "/v2/customers/{customerId}/domains/notifications",
        {{"customerId", customerId}},
        {},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::getV2CustomersCustomerIdDomainsNotificationsOptIn(const Value& customerId, const Value& xRequestId) {
    return call(
        "GET",
        "/v2/customers/{customerId}/domains/notifications/optIn",
        {{"customerId", customerId}},
        {},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::putV2CustomersCustomerIdDomainsNotificationsOptIn(const Value& customerId, const Value& types, const Value& xRequestId) {
    return call(
        "PUT",
        "/v2/customers/{customerId}/domains/notifications/optIn",
        {{"customerId", customerId}},
        {{"types", types}},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::getV2CustomersCustomerIdDomainsNotificationsSchemasType(const Value& customerId, const Value& typeValue, const Value& xRequestId) {
    return call(
        "GET",
        "/v2/customers/{customerId}/domains/notifications/schemas/{type}",
        {{"customerId", customerId}, {"type", typeValue}},
        {},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::postV2CustomersCustomerIdDomainsNotificationsNotificationIdAcknowledge(const Value& customerId, const Value& notificationId, const Value& xRequestId) {
    return call(
        "POST",
        "/v2/customers/{customerId}/domains/notifications/{notificationId}/acknowledge",
        {{"customerId", customerId}, {"notificationId", notificationId}},
        {},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::postV2CustomersCustomerIdDomainsRegister(const Value& customerId, const Value& body, const Value& xRequestId) {
    return call(
        "POST",
        "/v2/customers/{customerId}/domains/register",
        {{"customerId", customerId}},
        {},
        {{"X-Request-Id", xRequestId}},
        body
    );
}

Result DomainsService::getV2CustomersCustomerIdDomainsRegisterSchemaTld(const Value& customerId, const Value& tld, const Value& xRequestId) {
    return call(
        "GET",
        "/v2/customers/{customerId}/domains/register/schema/{tld}",
        {{"customerId", customerId}, {"tld", tld}},
        {},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::postV2CustomersCustomerIdDomainsRegisterValidate(const Value& customerId, const Value& body, const Value& xRequestId) {
    return call(
        "POST",
        "/v2/customers/{customerId}/domains/register/validate",
        {{"customerId", customerId}},
        {},
        {{"X-Request-Id", xRequestId}},
        body
    );
}

Result DomainsService::getV2DomainsMaintenances(const Value& xRequestId, const Value& status, const Value& modifiedAtAfter, const Value& startsAtAfter, const Value& limit) {
    return call(
        "GET",
        "/v2/domains/maintenances",
        {},
        {{"status", status}, {"modifiedAtAfter", modifiedAtAfter}, {"startsAtAfter", startsAtAfter}, {"limit", limit}},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::getV2DomainsMaintenancesMaintenanceId(const Value& maintenanceId, const Value& xRequestId) {
    return call(
        "GET",
        "/v2/domains/maintenances/{maintenanceId}",
        {{"maintenanceId", maintenanceId}},
        {},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::getV2DomainsUsageYyyymm(const Value& yyyymm, const Value& xRequestId, const Value& includes) {
    return call(
        "GET",
        "/v2/domains/usage/{yyyymm}",
        {{"yyyymm", yyyymm}},
        {{"includes", includes}},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

Result DomainsService::patchV2CustomersCustomerIdDomainsDomainContacts(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId) {
    return call(
        "PATCH",
        "/v2/customers/{customerId}/domains/{domain}/contacts",
        {{"customerId", customerId}, {"domain", domain}},
        {},
        {{"X-Request-Id", xRequestId}},
        body
    );
}

Result DomainsService::postV2CustomersCustomerIdDomainsDomainRegenerateAuthCode(const Value& customerId, const Value& domain, const Value& xRequestId) {
    return call(
        "POST",
        "/v2/customers/{customerId}/domains/{domain}/regenerateAuthCode",
        {{"customerId", customerId}, {"domain", domain}},
        {},
        {{"X-Request-Id", xRequestId}},
        Value{}
    );
}

}  // namespace godaddy
