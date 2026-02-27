# DomainsService

Domain availability, purchase, management, transfer, and DNS endpoints.

## Accessor

```cpp
auto& service = client.domains();
```

## Endpoints

### list

Calls `GET /v1/domains`.

```cpp
auto response = client.domains().list(std::string{"header-value"}, std::vector<std::string>{"sample"}, std::vector<std::string>{"sample"}, std::int64_t{1}, std::string{"sample"}, std::vector<std::string>{"sample"}, std::string{"sample"});
```

```json
{}
```

### getAgreement

Calls `GET /v1/domains/agreements`.

```cpp
auto response = client.domains().getAgreement(std::vector<std::string>{"sample"}, true, std::string{"header-value"}, true);
```

```json
{}
```

### available

Calls `GET /v1/domains/available`.

```cpp
auto response = client.domains().available(std::string{"sample"}, std::string{"sample"}, true);
```

```json
{}
```

### availableBulk

Calls `POST /v1/domains/available`.

```cpp
auto response = client.domains().availableBulk(std::vector<std::string>{"sample"}, std::string{"sample"});
```

```json
{}
```

### contactsValidate

Calls `POST /v1/domains/contacts/validate`.

```cpp
auto response = client.domains().contactsValidate(std::string{"{\"sample\":true}"}, std::string{"header-value"}, std::string{"sample"});
```

```json
{}
```

### purchase

Calls `POST /v1/domains/purchase`.

```cpp
auto response = client.domains().purchase(std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### schema

Calls `GET /v1/domains/purchase/schema/{tld}`.

```cpp
auto response = client.domains().schema(std::string{"sample"});
```

```json
{}
```

### validate

Calls `POST /v1/domains/purchase/validate`.

```cpp
auto response = client.domains().validate(std::string{"{\"sample\":true}"});
```

```json
{}
```

### suggest

Calls `GET /v1/domains/suggest`.

```cpp
auto response = client.domains().suggest(std::string{"header-value"}, std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::vector<std::string>{"sample"}, std::vector<std::string>{"sample"}, std::int64_t{1}, std::int64_t{1}, std::int64_t{1}, std::int64_t{1});
```

```json
{}
```

### tlds

Calls `GET /v1/domains/tlds`.

```cpp
auto response = client.domains().tlds();
```

```json
{}
```

### cancel

Calls `DELETE /v1/domains/{domain}`.

```cpp
auto response = client.domains().cancel(std::string{"sample"});
```

```json
{}
```

### get

Calls `GET /v1/domains/{domain}`.

```cpp
auto response = client.domains().get(std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### update

Calls `PATCH /v1/domains/{domain}`.

```cpp
auto response = client.domains().update(std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### updateContacts

Calls `PATCH /v1/domains/{domain}/contacts`.

```cpp
auto response = client.domains().updateContacts(std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### cancelPrivacy

Calls `DELETE /v1/domains/{domain}/privacy`.

```cpp
auto response = client.domains().cancelPrivacy(std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### purchasePrivacy

Calls `POST /v1/domains/{domain}/privacy/purchase`.

```cpp
auto response = client.domains().purchasePrivacy(std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### recordAdd

Calls `PATCH /v1/domains/{domain}/records`.

```cpp
auto response = client.domains().recordAdd(std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### recordReplace

Calls `PUT /v1/domains/{domain}/records`.

```cpp
auto response = client.domains().recordReplace(std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### recordGet

Calls `GET /v1/domains/{domain}/records/{type}/{name}`.

```cpp
auto response = client.domains().recordGet(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"header-value"}, std::int64_t{1}, std::int64_t{1});
```

```json
{}
```

### recordReplaceTypeName

Calls `PUT /v1/domains/{domain}/records/{type}/{name}`.

```cpp
auto response = client.domains().recordReplaceTypeName(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### recordDeleteTypeName

Calls `DELETE /v1/domains/{domain}/records/{type}/{name}`.

```cpp
auto response = client.domains().recordDeleteTypeName(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### recordReplaceType

Calls `PUT /v1/domains/{domain}/records/{type}`.

```cpp
auto response = client.domains().recordReplaceType(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### renew

Calls `POST /v1/domains/{domain}/renew`.

```cpp
auto response = client.domains().renew(std::string{"sample"}, std::string{"header-value"}, std::string{"{\"sample\":true}"});
```

```json
{}
```

### transferIn

Calls `POST /v1/domains/{domain}/transfer`.

```cpp
auto response = client.domains().transferIn(std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### verifyEmail

Calls `POST /v1/domains/{domain}/verifyRegistrantEmail`.

```cpp
auto response = client.domains().verifyEmail(std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### getV2CustomersCustomerIdDomainsDomain

Calls `GET /v2/customers/{customerId}/domains/{domain}`.

```cpp
auto response = client.domains().getV2CustomersCustomerIdDomainsDomain(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"}, std::vector<std::string>{"sample"});
```

```json
{}
```

### deleteV2CustomersCustomerIdDomainsDomainChangeOfRegistrant

Calls `DELETE /v2/customers/{customerId}/domains/{domain}/changeOfRegistrant`.

```cpp
auto response = client.domains().deleteV2CustomersCustomerIdDomainsDomainChangeOfRegistrant(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### getV2CustomersCustomerIdDomainsDomainChangeOfRegistrant

Calls `GET /v2/customers/{customerId}/domains/{domain}/changeOfRegistrant`.

```cpp
auto response = client.domains().getV2CustomersCustomerIdDomainsDomainChangeOfRegistrant(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### patchV2CustomersCustomerIdDomainsDomainDnssecRecords

Calls `PATCH /v2/customers/{customerId}/domains/{domain}/dnssecRecords`.

```cpp
auto response = client.domains().patchV2CustomersCustomerIdDomainsDomainDnssecRecords(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### deleteV2CustomersCustomerIdDomainsDomainDnssecRecords

Calls `DELETE /v2/customers/{customerId}/domains/{domain}/dnssecRecords`.

```cpp
auto response = client.domains().deleteV2CustomersCustomerIdDomainsDomainDnssecRecords(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### putV2CustomersCustomerIdDomainsDomainNameServers

Calls `PUT /v2/customers/{customerId}/domains/{domain}/nameServers`.

```cpp
auto response = client.domains().putV2CustomersCustomerIdDomainsDomainNameServers(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### getV2CustomersCustomerIdDomainsDomainPrivacyForwarding

Calls `GET /v2/customers/{customerId}/domains/{domain}/privacy/forwarding`.

```cpp
auto response = client.domains().getV2CustomersCustomerIdDomainsDomainPrivacyForwarding(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### patchV2CustomersCustomerIdDomainsDomainPrivacyForwarding

Calls `PATCH /v2/customers/{customerId}/domains/{domain}/privacy/forwarding`.

```cpp
auto response = client.domains().patchV2CustomersCustomerIdDomainsDomainPrivacyForwarding(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### postV2CustomersCustomerIdDomainsDomainRedeem

Calls `POST /v2/customers/{customerId}/domains/{domain}/redeem`.

```cpp
auto response = client.domains().postV2CustomersCustomerIdDomainsDomainRedeem(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"}, std::string{"{\"sample\":true}"});
```

```json
{}
```

### postV2CustomersCustomerIdDomainsDomainRenew

Calls `POST /v2/customers/{customerId}/domains/{domain}/renew`.

```cpp
auto response = client.domains().postV2CustomersCustomerIdDomainsDomainRenew(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### postV2CustomersCustomerIdDomainsDomainTransfer

Calls `POST /v2/customers/{customerId}/domains/{domain}/transfer`.

```cpp
auto response = client.domains().postV2CustomersCustomerIdDomainsDomainTransfer(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### getV2CustomersCustomerIdDomainsDomainTransfer

Calls `GET /v2/customers/{customerId}/domains/{domain}/transfer`.

```cpp
auto response = client.domains().getV2CustomersCustomerIdDomainsDomainTransfer(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### postV2CustomersCustomerIdDomainsDomainTransferValidate

Calls `POST /v2/customers/{customerId}/domains/{domain}/transfer/validate`.

```cpp
auto response = client.domains().postV2CustomersCustomerIdDomainsDomainTransferValidate(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### postV2CustomersCustomerIdDomainsDomainTransferInAccept

Calls `POST /v2/customers/{customerId}/domains/{domain}/transferInAccept`.

```cpp
auto response = client.domains().postV2CustomersCustomerIdDomainsDomainTransferInAccept(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### postV2CustomersCustomerIdDomainsDomainTransferInCancel

Calls `POST /v2/customers/{customerId}/domains/{domain}/transferInCancel`.

```cpp
auto response = client.domains().postV2CustomersCustomerIdDomainsDomainTransferInCancel(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### postV2CustomersCustomerIdDomainsDomainTransferInRestart

Calls `POST /v2/customers/{customerId}/domains/{domain}/transferInRestart`.

```cpp
auto response = client.domains().postV2CustomersCustomerIdDomainsDomainTransferInRestart(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### postV2CustomersCustomerIdDomainsDomainTransferInRetry

Calls `POST /v2/customers/{customerId}/domains/{domain}/transferInRetry`.

```cpp
auto response = client.domains().postV2CustomersCustomerIdDomainsDomainTransferInRetry(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### postV2CustomersCustomerIdDomainsDomainTransferOut

Calls `POST /v2/customers/{customerId}/domains/{domain}/transferOut`.

```cpp
auto response = client.domains().postV2CustomersCustomerIdDomainsDomainTransferOut(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### postV2CustomersCustomerIdDomainsDomainTransferOutAccept

Calls `POST /v2/customers/{customerId}/domains/{domain}/transferOutAccept`.

```cpp
auto response = client.domains().postV2CustomersCustomerIdDomainsDomainTransferOutAccept(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### postV2CustomersCustomerIdDomainsDomainTransferOutReject

Calls `POST /v2/customers/{customerId}/domains/{domain}/transferOutReject`.

```cpp
auto response = client.domains().postV2CustomersCustomerIdDomainsDomainTransferOutReject(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"}, std::string{"sample"});
```

```json
{}
```

### domainsForwardsDelete

Calls `DELETE /v2/customers/{customerId}/domains/forwards/{fqdn}`.

```cpp
auto response = client.domains().domainsForwardsDelete(std::string{"sample"}, std::string{"sample"});
```

```json
{}
```

### domainsForwardsGet

Calls `GET /v2/customers/{customerId}/domains/forwards/{fqdn}`.

```cpp
auto response = client.domains().domainsForwardsGet(std::string{"sample"}, std::string{"sample"}, true);
```

```json
{}
```

### domainsForwardsPut

Calls `PUT /v2/customers/{customerId}/domains/forwards/{fqdn}`.

```cpp
auto response = client.domains().domainsForwardsPut(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"});
```

```json
{}
```

### domainsForwardsPost

Calls `POST /v2/customers/{customerId}/domains/forwards/{fqdn}`.

```cpp
auto response = client.domains().domainsForwardsPost(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"});
```

```json
{}
```

### getV2CustomersCustomerIdDomainsDomainActions

Calls `GET /v2/customers/{customerId}/domains/{domain}/actions`.

```cpp
auto response = client.domains().getV2CustomersCustomerIdDomainsDomainActions(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### deleteV2CustomersCustomerIdDomainsDomainActionsType

Calls `DELETE /v2/customers/{customerId}/domains/{domain}/actions/{type}`.

```cpp
auto response = client.domains().deleteV2CustomersCustomerIdDomainsDomainActionsType(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### getV2CustomersCustomerIdDomainsDomainActionsType

Calls `GET /v2/customers/{customerId}/domains/{domain}/actions/{type}`.

```cpp
auto response = client.domains().getV2CustomersCustomerIdDomainsDomainActionsType(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### getV2CustomersCustomerIdDomainsNotifications

Calls `GET /v2/customers/{customerId}/domains/notifications`.

```cpp
auto response = client.domains().getV2CustomersCustomerIdDomainsNotifications(std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### getV2CustomersCustomerIdDomainsNotificationsOptIn

Calls `GET /v2/customers/{customerId}/domains/notifications/optIn`.

```cpp
auto response = client.domains().getV2CustomersCustomerIdDomainsNotificationsOptIn(std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### putV2CustomersCustomerIdDomainsNotificationsOptIn

Calls `PUT /v2/customers/{customerId}/domains/notifications/optIn`.

```cpp
auto response = client.domains().putV2CustomersCustomerIdDomainsNotificationsOptIn(std::string{"sample"}, std::vector<std::string>{"sample"}, std::string{"header-value"});
```

```json
{}
```

### getV2CustomersCustomerIdDomainsNotificationsSchemasType

Calls `GET /v2/customers/{customerId}/domains/notifications/schemas/{type}`.

```cpp
auto response = client.domains().getV2CustomersCustomerIdDomainsNotificationsSchemasType(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### postV2CustomersCustomerIdDomainsNotificationsNotificationIdAcknowledge

Calls `POST /v2/customers/{customerId}/domains/notifications/{notificationId}/acknowledge`.

```cpp
auto response = client.domains().postV2CustomersCustomerIdDomainsNotificationsNotificationIdAcknowledge(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### postV2CustomersCustomerIdDomainsRegister

Calls `POST /v2/customers/{customerId}/domains/register`.

```cpp
auto response = client.domains().postV2CustomersCustomerIdDomainsRegister(std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### getV2CustomersCustomerIdDomainsRegisterSchemaTld

Calls `GET /v2/customers/{customerId}/domains/register/schema/{tld}`.

```cpp
auto response = client.domains().getV2CustomersCustomerIdDomainsRegisterSchemaTld(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### postV2CustomersCustomerIdDomainsRegisterValidate

Calls `POST /v2/customers/{customerId}/domains/register/validate`.

```cpp
auto response = client.domains().postV2CustomersCustomerIdDomainsRegisterValidate(std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### getV2DomainsMaintenances

Calls `GET /v2/domains/maintenances`.

```cpp
auto response = client.domains().getV2DomainsMaintenances(std::string{"header-value"}, std::vector<std::string>{"sample"}, std::string{"sample"}, std::string{"sample"}, std::int64_t{1});
```

```json
{}
```

### getV2DomainsMaintenancesMaintenanceId

Calls `GET /v2/domains/maintenances/{maintenanceId}`.

```cpp
auto response = client.domains().getV2DomainsMaintenancesMaintenanceId(std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

### getV2DomainsUsageYyyymm

Calls `GET /v2/domains/usage/{yyyymm}`.

```cpp
auto response = client.domains().getV2DomainsUsageYyyymm(std::string{"sample"}, std::string{"header-value"}, std::vector<std::string>{"sample"});
```

```json
{}
```

### patchV2CustomersCustomerIdDomainsDomainContacts

Calls `PATCH /v2/customers/{customerId}/domains/{domain}/contacts`.

```cpp
auto response = client.domains().patchV2CustomersCustomerIdDomainsDomainContacts(std::string{"sample"}, std::string{"sample"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### postV2CustomersCustomerIdDomainsDomainRegenerateAuthCode

Calls `POST /v2/customers/{customerId}/domains/{domain}/regenerateAuthCode`.

```cpp
auto response = client.domains().postV2CustomersCustomerIdDomainsDomainRegenerateAuthCode(std::string{"sample"}, std::string{"sample"}, std::string{"header-value"});
```

```json
{}
```

