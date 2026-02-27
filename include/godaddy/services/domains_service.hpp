#pragma once

#include "godaddy/service_base.hpp"

namespace godaddy {

class DomainsService final : public BaseService {
public:
    explicit DomainsService(ApiClient& client);
    Result list(const Value& xShopperId = {}, const Value& statuses = {}, const Value& statusGroups = {}, const Value& limit = {}, const Value& marker = {}, const Value& includes = {}, const Value& modifiedDate = {});
    Result getAgreement(const Value& tlds, const Value& privacy, const Value& xMarketId = {}, const Value& forTransfer = {});
    Result available(const Value& domain, const Value& checkType = {}, const Value& forTransfer = {});
    Result availableBulk(const Value& domains, const Value& checkType = {});
    Result contactsValidate(const Value& body, const Value& xPrivateLabelId = {}, const Value& marketId = {});
    Result purchase(const Value& body, const Value& xShopperId = {});
    Result schema(const Value& tld);
    Result validate(const Value& body);
    Result suggest(const Value& xShopperId = {}, const Value& query = {}, const Value& country = {}, const Value& city = {}, const Value& sources = {}, const Value& tlds = {}, const Value& lengthMax = {}, const Value& lengthMin = {}, const Value& limit = {}, const Value& waitMs = {});
    Result tlds();
    Result cancel(const Value& domain);
    Result get(const Value& domain, const Value& xShopperId = {});
    Result update(const Value& domain, const Value& body, const Value& xShopperId = {});
    Result updateContacts(const Value& domain, const Value& contacts, const Value& xShopperId = {});
    Result cancelPrivacy(const Value& domain, const Value& xShopperId = {});
    Result purchasePrivacy(const Value& domain, const Value& body, const Value& xShopperId = {});
    Result recordAdd(const Value& domain, const Value& records, const Value& xShopperId = {});
    Result recordReplace(const Value& domain, const Value& records, const Value& xShopperId = {});
    Result recordGet(const Value& domain, const Value& typeValue, const Value& name, const Value& xShopperId = {}, const Value& offset = {}, const Value& limit = {});
    Result recordReplaceTypeName(const Value& domain, const Value& typeValue, const Value& name, const Value& records, const Value& xShopperId = {});
    Result recordDeleteTypeName(const Value& domain, const Value& typeValue, const Value& name, const Value& xShopperId = {});
    Result recordReplaceType(const Value& domain, const Value& typeValue, const Value& records, const Value& xShopperId = {});
    Result renew(const Value& domain, const Value& xShopperId = {}, const Value& body = {});
    Result transferIn(const Value& domain, const Value& body, const Value& xShopperId = {});
    Result verifyEmail(const Value& domain, const Value& xShopperId = {});
    Result getV2CustomersCustomerIdDomainsDomain(const Value& customerId, const Value& domain, const Value& xRequestId = {}, const Value& includes = {});
    Result deleteV2CustomersCustomerIdDomainsDomainChangeOfRegistrant(const Value& customerId, const Value& domain, const Value& xRequestId = {});
    Result getV2CustomersCustomerIdDomainsDomainChangeOfRegistrant(const Value& customerId, const Value& domain, const Value& xRequestId = {});
    Result patchV2CustomersCustomerIdDomainsDomainDnssecRecords(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId = {});
    Result deleteV2CustomersCustomerIdDomainsDomainDnssecRecords(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId = {});
    Result putV2CustomersCustomerIdDomainsDomainNameServers(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId = {});
    Result getV2CustomersCustomerIdDomainsDomainPrivacyForwarding(const Value& customerId, const Value& domain, const Value& xRequestId = {});
    Result patchV2CustomersCustomerIdDomainsDomainPrivacyForwarding(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId = {});
    Result postV2CustomersCustomerIdDomainsDomainRedeem(const Value& customerId, const Value& domain, const Value& xRequestId = {}, const Value& body = {});
    Result postV2CustomersCustomerIdDomainsDomainRenew(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId = {});
    Result postV2CustomersCustomerIdDomainsDomainTransfer(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId = {});
    Result getV2CustomersCustomerIdDomainsDomainTransfer(const Value& customerId, const Value& domain, const Value& xRequestId = {});
    Result postV2CustomersCustomerIdDomainsDomainTransferValidate(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId = {});
    Result postV2CustomersCustomerIdDomainsDomainTransferInAccept(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId = {});
    Result postV2CustomersCustomerIdDomainsDomainTransferInCancel(const Value& customerId, const Value& domain, const Value& xRequestId = {});
    Result postV2CustomersCustomerIdDomainsDomainTransferInRestart(const Value& customerId, const Value& domain, const Value& xRequestId = {});
    Result postV2CustomersCustomerIdDomainsDomainTransferInRetry(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId = {});
    Result postV2CustomersCustomerIdDomainsDomainTransferOut(const Value& customerId, const Value& domain, const Value& registrar, const Value& xRequestId = {});
    Result postV2CustomersCustomerIdDomainsDomainTransferOutAccept(const Value& customerId, const Value& domain, const Value& xRequestId = {});
    Result postV2CustomersCustomerIdDomainsDomainTransferOutReject(const Value& customerId, const Value& domain, const Value& xRequestId = {}, const Value& reason = {});
    Result domainsForwardsDelete(const Value& customerId, const Value& fqdn);
    Result domainsForwardsGet(const Value& customerId, const Value& fqdn, const Value& includeSubs = {});
    Result domainsForwardsPut(const Value& customerId, const Value& fqdn, const Value& body);
    Result domainsForwardsPost(const Value& customerId, const Value& fqdn, const Value& body);
    Result getV2CustomersCustomerIdDomainsDomainActions(const Value& customerId, const Value& domain, const Value& xRequestId = {});
    Result deleteV2CustomersCustomerIdDomainsDomainActionsType(const Value& customerId, const Value& domain, const Value& typeValue, const Value& xRequestId = {});
    Result getV2CustomersCustomerIdDomainsDomainActionsType(const Value& customerId, const Value& domain, const Value& typeValue, const Value& xRequestId = {});
    Result getV2CustomersCustomerIdDomainsNotifications(const Value& customerId, const Value& xRequestId = {});
    Result getV2CustomersCustomerIdDomainsNotificationsOptIn(const Value& customerId, const Value& xRequestId = {});
    Result putV2CustomersCustomerIdDomainsNotificationsOptIn(const Value& customerId, const Value& types, const Value& xRequestId = {});
    Result getV2CustomersCustomerIdDomainsNotificationsSchemasType(const Value& customerId, const Value& typeValue, const Value& xRequestId = {});
    Result postV2CustomersCustomerIdDomainsNotificationsNotificationIdAcknowledge(const Value& customerId, const Value& notificationId, const Value& xRequestId = {});
    Result postV2CustomersCustomerIdDomainsRegister(const Value& customerId, const Value& body, const Value& xRequestId = {});
    Result getV2CustomersCustomerIdDomainsRegisterSchemaTld(const Value& customerId, const Value& tld, const Value& xRequestId = {});
    Result postV2CustomersCustomerIdDomainsRegisterValidate(const Value& customerId, const Value& body, const Value& xRequestId = {});
    Result getV2DomainsMaintenances(const Value& xRequestId = {}, const Value& status = {}, const Value& modifiedAtAfter = {}, const Value& startsAtAfter = {}, const Value& limit = {});
    Result getV2DomainsMaintenancesMaintenanceId(const Value& maintenanceId, const Value& xRequestId = {});
    Result getV2DomainsUsageYyyymm(const Value& yyyymm, const Value& xRequestId = {}, const Value& includes = {});
    Result patchV2CustomersCustomerIdDomainsDomainContacts(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId = {});
    Result postV2CustomersCustomerIdDomainsDomainRegenerateAuthCode(const Value& customerId, const Value& domain, const Value& xRequestId = {});
};

}  // namespace godaddy
