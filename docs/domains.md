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
auto response = client.domains().list(
    std::string{"123456"},
    std::vector<std::string>{"example.com"},
    std::vector<std::string>{"example.com"},
    std::int64_t{1},
    std::string{"example.com"},
    std::vector<std::string>{"example.com"},
    std::string{"example.com"}
);
```

```json
{
  "domain": "example.com",
  "status": "ACTIVE",
  "expires": "2027-03-11T00:00:00Z",
  "authCode": "AUTHCODE"
}
```

### getAgreement

Calls `GET /v1/domains/agreements`.

```cpp
auto response = client.domains().getAgreement(
    std::vector<std::string>{"example.com"},
    true,
    std::string{"123456"},
    true
);
```

```json
{
  "agreements": [
    {
      "agreementKey": "DNRA",
      "title": "Domain Name Registration Agreement",
      "url": "https://www.godaddy.com/legal/agreements/domain-registration"
    }
  ]
}
```

### available

Calls `GET /v1/domains/available`.

```cpp
auto response = client.domains().available(
    std::string{"example.com"},
    std::string{"example.com"},
    true
);
```

```json
{
  "domain": "example.com",
  "available": true,
  "price": 1999,
  "currency": "USD",
  "definitive": true,
  "period": 1
}
```

### availableBulk

Calls `POST /v1/domains/available`.

```cpp
auto response = client.domains().availableBulk(
    std::vector<std::string>{"example.com"},
    std::string{"example.com"}
);
```

```json
{
  "domains": [
    {
      "domain": "example.com",
      "available": true,
      "price": 1999,
      "currency": "USD"
    }
  ]
}
```

### contactsValidate

Calls `POST /v1/domains/contacts/validate`.

```cpp
auto response = client.domains().contactsValidate(
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"},
    std::string{"example.com"}
);
```

```json
{
  "valid": false,
  "errors": [
    {
      "path": "domain",
      "message": "Domain is invalid"
    }
  ]
}
```

### purchase

Calls `POST /v1/domains/purchase`.

```cpp
auto response = client.domains().purchase(
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "orderId": "1234567890",
  "status": "PENDING",
  "submittedAt": "2026-03-11T12:00:00Z"
}
```

### schema

Calls `GET /v1/domains/purchase/schema/{tld}`.

```cpp
auto response = client.domains().schema(
    std::string{"example.com"}
);
```

```json
{
  "fields": [
    {
      "path": "consent.agreementKeys",
      "type": "array",
      "required": true
    }
  ]
}
```

### validate

Calls `POST /v1/domains/purchase/validate`.

```cpp
auto response = client.domains().validate(
    std::string{R"({"domain":"example.com"})"}
);
```

```json
{
  "valid": false,
  "errors": [
    {
      "path": "domain",
      "message": "Domain is invalid"
    }
  ]
}
```

### suggest

Calls `GET /v1/domains/suggest`.

```cpp
auto response = client.domains().suggest(
    std::string{"123456"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::vector<std::string>{"example.com"},
    std::vector<std::string>{"example.com"},
    std::int64_t{1},
    std::int64_t{1},
    std::int64_t{1},
    std::int64_t{1}
);
```

```json
[
  "example.com",
  "example.net"
]
```

### tlds

Calls `GET /v1/domains/tlds`.

```cpp
auto response = client.domains().tlds(
);
```

```json
{
  "tld": "com",
  "type": "GENERIC",
  "isIdn": false
}
```

### cancel

Calls `DELETE /v1/domains/{domain}`.

```cpp
auto response = client.domains().cancel(
    std::string{"example.com"}
);
```

```json
{
  "success": true
}
```

### get

Calls `GET /v1/domains/{domain}`.

```cpp
auto response = client.domains().get(
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "domain": "example.com",
  "status": "ACTIVE",
  "expires": "2027-03-11T00:00:00Z",
  "authCode": "AUTHCODE"
}
```

### update

Calls `PATCH /v1/domains/{domain}`.

```cpp
auto response = client.domains().update(
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "orderId": "1234567890",
  "status": "PENDING",
  "submittedAt": "2026-03-11T12:00:00Z"
}
```

### updateContacts

Calls `PATCH /v1/domains/{domain}/contacts`.

```cpp
auto response = client.domains().updateContacts(
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "orderId": "1234567890",
  "status": "PENDING",
  "submittedAt": "2026-03-11T12:00:00Z"
}
```

### cancelPrivacy

Calls `DELETE /v1/domains/{domain}/privacy`.

```cpp
auto response = client.domains().cancelPrivacy(
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "success": true
}
```

### purchasePrivacy

Calls `POST /v1/domains/{domain}/privacy/purchase`.

```cpp
auto response = client.domains().purchasePrivacy(
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "orderId": "1234567890",
  "status": "PENDING",
  "submittedAt": "2026-03-11T12:00:00Z"
}
```

### recordAdd

Calls `PATCH /v1/domains/{domain}/records`.

```cpp
auto response = client.domains().recordAdd(
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "type": "A",
  "name": "@",
  "data": "203.0.113.10",
  "ttl": 600
}
```

### recordReplace

Calls `PUT /v1/domains/{domain}/records`.

```cpp
auto response = client.domains().recordReplace(
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "type": "A",
  "name": "@",
  "data": "203.0.113.10",
  "ttl": 600
}
```

### recordGet

Calls `GET /v1/domains/{domain}/records/{type}/{name}`.

```cpp
auto response = client.domains().recordGet(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"123456"},
    std::int64_t{1},
    std::int64_t{1}
);
```

```json
{
  "type": "A",
  "name": "@",
  "data": "203.0.113.10",
  "ttl": 600
}
```

### recordReplaceTypeName

Calls `PUT /v1/domains/{domain}/records/{type}/{name}`.

```cpp
auto response = client.domains().recordReplaceTypeName(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "type": "A",
  "name": "@",
  "data": "203.0.113.10",
  "ttl": 600
}
```

### recordDeleteTypeName

Calls `DELETE /v1/domains/{domain}/records/{type}/{name}`.

```cpp
auto response = client.domains().recordDeleteTypeName(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "type": "A",
  "name": "@",
  "data": "203.0.113.10",
  "ttl": 600
}
```

### recordReplaceType

Calls `PUT /v1/domains/{domain}/records/{type}`.

```cpp
auto response = client.domains().recordReplaceType(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "type": "A",
  "name": "@",
  "data": "203.0.113.10",
  "ttl": 600
}
```

### renew

Calls `POST /v1/domains/{domain}/renew`.

```cpp
auto response = client.domains().renew(
    std::string{"example.com"},
    std::string{"123456"},
    std::string{R"({"domain":"example.com"})"}
);
```

```json
{
  "orderId": "1234567890",
  "status": "PENDING",
  "submittedAt": "2026-03-11T12:00:00Z"
}
```

### transferIn

Calls `POST /v1/domains/{domain}/transfer`.

```cpp
auto response = client.domains().transferIn(
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "domain": "example.com",
  "transferStatus": "PENDING",
  "updatedAt": "2026-03-11T12:00:00Z"
}
```

### verifyEmail

Calls `POST /v1/domains/{domain}/verifyRegistrantEmail`.

```cpp
auto response = client.domains().verifyEmail(
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "domain": "example.com",
  "status": "ACTIVE",
  "expires": "2027-03-11T00:00:00Z",
  "authCode": "AUTHCODE"
}
```

### getCustomerDomain

Calls `GET /v2/customers/{customerId}/domains/{domain}`.

```cpp
auto response = client.domains().getCustomerDomain(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"123456"},
    std::vector<std::string>{"example.com"}
);
```

```json
{
  "domain": "example.com",
  "status": "ACTIVE",
  "expires": "2027-03-11T00:00:00Z",
  "authCode": "AUTHCODE"
}
```

### cancelCustomerDomainChangeOfRegistrant

Calls `DELETE /v2/customers/{customerId}/domains/{domain}/changeOfRegistrant`.

```cpp
auto response = client.domains().cancelCustomerDomainChangeOfRegistrant(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "success": true
}
```

### getCustomerDomainChangeOfRegistrant

Calls `GET /v2/customers/{customerId}/domains/{domain}/changeOfRegistrant`.

```cpp
auto response = client.domains().getCustomerDomainChangeOfRegistrant(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "domain": "example.com",
  "status": "ACTIVE",
  "expires": "2027-03-11T00:00:00Z",
  "authCode": "AUTHCODE"
}
```

### addCustomerDomainDnssecRecords

Calls `PATCH /v2/customers/{customerId}/domains/{domain}/dnssecRecords`.

```cpp
auto response = client.domains().addCustomerDomainDnssecRecords(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "type": "A",
  "name": "@",
  "data": "203.0.113.10",
  "ttl": 600
}
```

### removeCustomerDomainDnssecRecords

Calls `DELETE /v2/customers/{customerId}/domains/{domain}/dnssecRecords`.

```cpp
auto response = client.domains().removeCustomerDomainDnssecRecords(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "type": "A",
  "name": "@",
  "data": "203.0.113.10",
  "ttl": 600
}
```

### replaceCustomerDomainNameServers

Calls `PUT /v2/customers/{customerId}/domains/{domain}/nameServers`.

```cpp
auto response = client.domains().replaceCustomerDomainNameServers(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "orderId": "1234567890",
  "status": "PENDING",
  "submittedAt": "2026-03-11T12:00:00Z"
}
```

### getCustomerDomainPrivacyForwarding

Calls `GET /v2/customers/{customerId}/domains/{domain}/privacy/forwarding`.

```cpp
auto response = client.domains().getCustomerDomainPrivacyForwarding(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "fqdn": "example.com",
  "type": "PERMANENT",
  "to": "https://www.example.com"
}
```

### updateCustomerDomainPrivacyForwarding

Calls `PATCH /v2/customers/{customerId}/domains/{domain}/privacy/forwarding`.

```cpp
auto response = client.domains().updateCustomerDomainPrivacyForwarding(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "fqdn": "example.com",
  "type": "PERMANENT",
  "to": "https://www.example.com"
}
```

### redeemCustomerDomain

Calls `POST /v2/customers/{customerId}/domains/{domain}/redeem`.

```cpp
auto response = client.domains().redeemCustomerDomain(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"123456"},
    std::string{R"({"domain":"example.com"})"}
);
```

```json
{
  "domain": "example.com",
  "status": "ACTIVE",
  "expires": "2027-03-11T00:00:00Z",
  "authCode": "AUTHCODE"
}
```

### renewCustomerDomain

Calls `POST /v2/customers/{customerId}/domains/{domain}/renew`.

```cpp
auto response = client.domains().renewCustomerDomain(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "orderId": "1234567890",
  "status": "PENDING",
  "submittedAt": "2026-03-11T12:00:00Z"
}
```

### transferCustomerDomain

Calls `POST /v2/customers/{customerId}/domains/{domain}/transfer`.

```cpp
auto response = client.domains().transferCustomerDomain(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "domain": "example.com",
  "transferStatus": "PENDING",
  "updatedAt": "2026-03-11T12:00:00Z"
}
```

### getCustomerDomainTransferStatus

Calls `GET /v2/customers/{customerId}/domains/{domain}/transfer`.

```cpp
auto response = client.domains().getCustomerDomainTransferStatus(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "domain": "example.com",
  "transferStatus": "PENDING",
  "updatedAt": "2026-03-11T12:00:00Z"
}
```

### validateCustomerDomainTransfer

Calls `POST /v2/customers/{customerId}/domains/{domain}/transfer/validate`.

```cpp
auto response = client.domains().validateCustomerDomainTransfer(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "valid": false,
  "errors": [
    {
      "path": "domain",
      "message": "Domain is invalid"
    }
  ]
}
```

### acceptCustomerDomainTransferIn

Calls `POST /v2/customers/{customerId}/domains/{domain}/transferInAccept`.

```cpp
auto response = client.domains().acceptCustomerDomainTransferIn(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "domain": "example.com",
  "transferStatus": "PENDING",
  "updatedAt": "2026-03-11T12:00:00Z"
}
```

### cancelCustomerDomainTransferIn

Calls `POST /v2/customers/{customerId}/domains/{domain}/transferInCancel`.

```cpp
auto response = client.domains().cancelCustomerDomainTransferIn(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "domain": "example.com",
  "transferStatus": "PENDING",
  "updatedAt": "2026-03-11T12:00:00Z"
}
```

### restartCustomerDomainTransferIn

Calls `POST /v2/customers/{customerId}/domains/{domain}/transferInRestart`.

```cpp
auto response = client.domains().restartCustomerDomainTransferIn(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "domain": "example.com",
  "transferStatus": "PENDING",
  "updatedAt": "2026-03-11T12:00:00Z"
}
```

### retryCustomerDomainTransferIn

Calls `POST /v2/customers/{customerId}/domains/{domain}/transferInRetry`.

```cpp
auto response = client.domains().retryCustomerDomainTransferIn(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "domain": "example.com",
  "transferStatus": "PENDING",
  "updatedAt": "2026-03-11T12:00:00Z"
}
```

### initiateCustomerDomainTransferOut

Calls `POST /v2/customers/{customerId}/domains/{domain}/transferOut`.

```cpp
auto response = client.domains().initiateCustomerDomainTransferOut(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "domain": "example.com",
  "transferStatus": "PENDING",
  "updatedAt": "2026-03-11T12:00:00Z"
}
```

### acceptCustomerDomainTransferOut

Calls `POST /v2/customers/{customerId}/domains/{domain}/transferOutAccept`.

```cpp
auto response = client.domains().acceptCustomerDomainTransferOut(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "domain": "example.com",
  "transferStatus": "PENDING",
  "updatedAt": "2026-03-11T12:00:00Z"
}
```

### rejectCustomerDomainTransferOut

Calls `POST /v2/customers/{customerId}/domains/{domain}/transferOutReject`.

```cpp
auto response = client.domains().rejectCustomerDomainTransferOut(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"123456"},
    std::string{"example.com"}
);
```

```json
{
  "domain": "example.com",
  "transferStatus": "PENDING",
  "updatedAt": "2026-03-11T12:00:00Z"
}
```

### deleteDomainForwarding

Calls `DELETE /v2/customers/{customerId}/domains/forwards/{fqdn}`.

```cpp
auto response = client.domains().deleteDomainForwarding(
    std::string{"example.com"},
    std::string{"example.com"}
);
```

```json
{
  "fqdn": "example.com",
  "type": "PERMANENT",
  "to": "https://www.example.com"
}
```

### getDomainForwarding

Calls `GET /v2/customers/{customerId}/domains/forwards/{fqdn}`.

```cpp
auto response = client.domains().getDomainForwarding(
    std::string{"example.com"},
    std::string{"example.com"},
    true
);
```

```json
{
  "fqdn": "example.com",
  "type": "PERMANENT",
  "to": "https://www.example.com"
}
```

### updateDomainForwarding

Calls `PUT /v2/customers/{customerId}/domains/forwards/{fqdn}`.

```cpp
auto response = client.domains().updateDomainForwarding(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"}
);
```

```json
{
  "fqdn": "example.com",
  "type": "PERMANENT",
  "to": "https://www.example.com"
}
```

### createDomainForwarding

Calls `POST /v2/customers/{customerId}/domains/forwards/{fqdn}`.

```cpp
auto response = client.domains().createDomainForwarding(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"}
);
```

```json
{
  "fqdn": "example.com",
  "type": "PERMANENT",
  "to": "https://www.example.com"
}
```

### listCustomerDomainActions

Calls `GET /v2/customers/{customerId}/domains/{domain}/actions`.

```cpp
auto response = client.domains().listCustomerDomainActions(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "actionType": "CHANGE_OF_REGISTRANT",
  "status": "PENDING",
  "createdAt": "2026-03-11T12:00:00Z",
  "domain": "example.com"
}
```

### cancelCustomerDomainAction

Calls `DELETE /v2/customers/{customerId}/domains/{domain}/actions/{type}`.

```cpp
auto response = client.domains().cancelCustomerDomainAction(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "success": true
}
```

### getCustomerDomainAction

Calls `GET /v2/customers/{customerId}/domains/{domain}/actions/{type}`.

```cpp
auto response = client.domains().getCustomerDomainAction(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "domain": "example.com",
  "status": "ACTIVE",
  "expires": "2027-03-11T00:00:00Z",
  "authCode": "AUTHCODE"
}
```

### getCustomerDomainNotifications

Calls `GET /v2/customers/{customerId}/domains/notifications`.

```cpp
auto response = client.domains().getCustomerDomainNotifications(
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "type": "EXPIRATION",
  "optedIn": true
}
```

### getCustomerDomainNotificationOptIns

Calls `GET /v2/customers/{customerId}/domains/notifications/optIn`.

```cpp
auto response = client.domains().getCustomerDomainNotificationOptIns(
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "type": "EXPIRATION",
  "optedIn": true
}
```

### updateCustomerDomainNotificationOptIns

Calls `PUT /v2/customers/{customerId}/domains/notifications/optIn`.

```cpp
auto response = client.domains().updateCustomerDomainNotificationOptIns(
    std::string{"example.com"},
    std::vector<std::string>{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "type": "EXPIRATION",
  "optedIn": true
}
```

### getCustomerDomainNotificationSchema

Calls `GET /v2/customers/{customerId}/domains/notifications/schemas/{type}`.

```cpp
auto response = client.domains().getCustomerDomainNotificationSchema(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "fields": [
    {
      "path": "type",
      "type": "string",
      "required": true
    }
  ]
}
```

### acknowledgeCustomerDomainNotification

Calls `POST /v2/customers/{customerId}/domains/notifications/{notificationId}/acknowledge`.

```cpp
auto response = client.domains().acknowledgeCustomerDomainNotification(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "notificationId": "notif_1",
  "acknowledged": true,
  "acknowledgedAt": "2026-03-11T12:00:00Z"
}
```

### registerCustomerDomain

Calls `POST /v2/customers/{customerId}/domains/register`.

```cpp
auto response = client.domains().registerCustomerDomain(
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "orderId": "1234567890",
  "status": "PENDING",
  "submittedAt": "2026-03-11T12:00:00Z"
}
```

### getCustomerDomainRegisterSchema

Calls `GET /v2/customers/{customerId}/domains/register/schema/{tld}`.

```cpp
auto response = client.domains().getCustomerDomainRegisterSchema(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "fields": [
    {
      "path": "consent.agreementKeys",
      "type": "array",
      "required": true
    }
  ]
}
```

### validateCustomerDomainRegister

Calls `POST /v2/customers/{customerId}/domains/register/validate`.

```cpp
auto response = client.domains().validateCustomerDomainRegister(
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "valid": false,
  "errors": [
    {
      "path": "domain",
      "message": "Domain is invalid"
    }
  ]
}
```

### listDomainMaintenances

Calls `GET /v2/domains/maintenances`.

```cpp
auto response = client.domains().listDomainMaintenances(
    std::string{"123456"},
    std::vector<std::string>{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::int64_t{1}
);
```

```json
{
  "maintenanceId": "mnt_1",
  "status": "SCHEDULED",
  "startsAt": "2026-03-20T00:00:00Z",
  "endsAt": "2026-03-20T02:00:00Z"
}
```

### getDomainMaintenance

Calls `GET /v2/domains/maintenances/{maintenanceId}`.

```cpp
auto response = client.domains().getDomainMaintenance(
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "maintenanceId": "mnt_1",
  "status": "SCHEDULED",
  "startsAt": "2026-03-20T00:00:00Z",
  "endsAt": "2026-03-20T02:00:00Z"
}
```

### getDomainUsage

Calls `GET /v2/domains/usage/{yyyymm}`.

```cpp
auto response = client.domains().getDomainUsage(
    std::string{"example.com"},
    std::string{"123456"},
    std::vector<std::string>{"example.com"}
);
```

```json
{
  "month": "202603",
  "domainsUnderManagement": 120,
  "domainAdds": 10,
  "domainTransfersIn": 3
}
```

### updateCustomerDomainContacts

Calls `PATCH /v2/customers/{customerId}/domains/{domain}/contacts`.

```cpp
auto response = client.domains().updateCustomerDomainContacts(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "orderId": "1234567890",
  "status": "PENDING",
  "submittedAt": "2026-03-11T12:00:00Z"
}
```

### regenerateCustomerDomainAuthCode

Calls `POST /v2/customers/{customerId}/domains/{domain}/regenerateAuthCode`.

```cpp
auto response = client.domains().regenerateCustomerDomainAuthCode(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"123456"}
);
```

```json
{
  "domain": "example.com",
  "status": "ACTIVE",
  "expires": "2027-03-11T00:00:00Z",
  "authCode": "AUTHCODE"
}
```






