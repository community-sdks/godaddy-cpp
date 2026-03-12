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
    Result getCustomerDomain(const Value& customerId, const Value& domain, const Value& xRequestId = {}, const Value& includes = {});
    Result cancelCustomerDomainChangeOfRegistrant(const Value& customerId, const Value& domain, const Value& xRequestId = {});
    Result getCustomerDomainChangeOfRegistrant(const Value& customerId, const Value& domain, const Value& xRequestId = {});
    Result addCustomerDomainDnssecRecords(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId = {});
    Result removeCustomerDomainDnssecRecords(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId = {});
    Result replaceCustomerDomainNameServers(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId = {});
    Result getCustomerDomainPrivacyForwarding(const Value& customerId, const Value& domain, const Value& xRequestId = {});
    Result updateCustomerDomainPrivacyForwarding(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId = {});
    Result redeemCustomerDomain(const Value& customerId, const Value& domain, const Value& xRequestId = {}, const Value& body = {});
    Result renewCustomerDomain(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId = {});
    Result transferCustomerDomain(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId = {});
    Result getCustomerDomainTransferStatus(const Value& customerId, const Value& domain, const Value& xRequestId = {});
    Result validateCustomerDomainTransfer(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId = {});
    Result acceptCustomerDomainTransferIn(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId = {});
    Result cancelCustomerDomainTransferIn(const Value& customerId, const Value& domain, const Value& xRequestId = {});
    Result restartCustomerDomainTransferIn(const Value& customerId, const Value& domain, const Value& xRequestId = {});
    Result retryCustomerDomainTransferIn(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId = {});
    Result initiateCustomerDomainTransferOut(const Value& customerId, const Value& domain, const Value& registrar, const Value& xRequestId = {});
    Result acceptCustomerDomainTransferOut(const Value& customerId, const Value& domain, const Value& xRequestId = {});
    Result rejectCustomerDomainTransferOut(const Value& customerId, const Value& domain, const Value& xRequestId = {}, const Value& reason = {});
    Result deleteDomainForwarding(const Value& customerId, const Value& fqdn);
    Result getDomainForwarding(const Value& customerId, const Value& fqdn, const Value& includeSubs = {});
    Result updateDomainForwarding(const Value& customerId, const Value& fqdn, const Value& body);
    Result createDomainForwarding(const Value& customerId, const Value& fqdn, const Value& body);
    Result listCustomerDomainActions(const Value& customerId, const Value& domain, const Value& xRequestId = {});
    Result cancelCustomerDomainAction(const Value& customerId, const Value& domain, const Value& typeValue, const Value& xRequestId = {});
    Result getCustomerDomainAction(const Value& customerId, const Value& domain, const Value& typeValue, const Value& xRequestId = {});
    Result getCustomerDomainNotifications(const Value& customerId, const Value& xRequestId = {});
    Result getCustomerDomainNotificationOptIns(const Value& customerId, const Value& xRequestId = {});
    Result updateCustomerDomainNotificationOptIns(const Value& customerId, const Value& types, const Value& xRequestId = {});
    Result getCustomerDomainNotificationSchema(const Value& customerId, const Value& typeValue, const Value& xRequestId = {});
    Result acknowledgeCustomerDomainNotification(const Value& customerId, const Value& notificationId, const Value& xRequestId = {});
    Result registerCustomerDomain(const Value& customerId, const Value& body, const Value& xRequestId = {});
    Result getCustomerDomainRegisterSchema(const Value& customerId, const Value& tld, const Value& xRequestId = {});
    Result validateCustomerDomainRegister(const Value& customerId, const Value& body, const Value& xRequestId = {});
    Result listDomainMaintenances(const Value& xRequestId = {}, const Value& status = {}, const Value& modifiedAtAfter = {}, const Value& startsAtAfter = {}, const Value& limit = {});
    Result getDomainMaintenance(const Value& maintenanceId, const Value& xRequestId = {});
    Result getDomainUsage(const Value& yyyymm, const Value& xRequestId = {}, const Value& includes = {});
    Result updateCustomerDomainContacts(const Value& customerId, const Value& domain, const Value& body, const Value& xRequestId = {});
    Result regenerateCustomerDomainAuthCode(const Value& customerId, const Value& domain, const Value& xRequestId = {});
};

}  // namespace godaddy

