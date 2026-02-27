# CertificatesService

SSL certificate purchase, validation, lifecycle, and revocation endpoints.

## Accessor

```cpp
auto& service = client.certificates();
```

## Endpoints

### certificateCreate

Calls `POST /v1/certificates`.

```cpp
auto response = client.certificates().certificateCreate(std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### certificateValidate

Calls `POST /v1/certificates/validate`.

```cpp
auto response = client.certificates().certificateValidate(std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### certificateGet

Calls `GET /v1/certificates/{certificateId}`.

```cpp
auto response = client.certificates().certificateGet(std::string{"sample"});
```

```json
{}
```

### certificateActionRetrieve

Calls `GET /v1/certificates/{certificateId}/actions`.

```cpp
auto response = client.certificates().certificateActionRetrieve(std::string{"sample"});
```

```json
{}
```

### certificateResendEmail

Calls `POST /v1/certificates/{certificateId}/email/{emailId}/resend`.

```cpp
auto response = client.certificates().certificateResendEmail(std::string{"sample"}, std::string{"sample"});
```

```json
{}
```

### certificateAlternateEmailAddress

Calls `POST /v1/certificates/{certificateId}/email/resend/{emailAddress}`.

```cpp
auto response = client.certificates().certificateAlternateEmailAddress(std::string{"sample"}, std::vector<std::string>{"sample"});
```

```json
{}
```

### certificateResendEmailAddress

Calls `POST /v1/certificates/{certificateId}/email/{emailId}/resend/{emailAddress}`.

```cpp
auto response = client.certificates().certificateResendEmailAddress(std::string{"sample"}, std::string{"sample"}, std::vector<std::string>{"sample"});
```

```json
{}
```

### certificateEmailHistory

Calls `GET /v1/certificates/{certificateId}/email/history`.

```cpp
auto response = client.certificates().certificateEmailHistory(std::string{"sample"});
```

```json
{}
```

### certificateCallbackDelete

Calls `DELETE /v1/certificates/{certificateId}/callback`.

```cpp
auto response = client.certificates().certificateCallbackDelete(std::string{"sample"});
```

```json
{}
```

### certificateCallbackGet

Calls `GET /v1/certificates/{certificateId}/callback`.

```cpp
auto response = client.certificates().certificateCallbackGet(std::string{"sample"});
```

```json
{}
```

### certificateCallbackReplace

Calls `PUT /v1/certificates/{certificateId}/callback`.

```cpp
auto response = client.certificates().certificateCallbackReplace(std::string{"sample"}, std::string{"sample"});
```

```json
{}
```

### certificateCancel

Calls `POST /v1/certificates/{certificateId}/cancel`.

```cpp
auto response = client.certificates().certificateCancel(std::string{"sample"});
```

```json
{}
```

### certificateDownload

Calls `GET /v1/certificates/{certificateId}/download`.

```cpp
auto response = client.certificates().certificateDownload(std::string{"sample"});
```

```json
{}
```

### certificateReissue

Calls `POST /v1/certificates/{certificateId}/reissue`.

```cpp
auto response = client.certificates().certificateReissue(std::string{"sample"}, std::string{"{\"sample\":true}"});
```

```json
{}
```

### certificateRenew

Calls `POST /v1/certificates/{certificateId}/renew`.

```cpp
auto response = client.certificates().certificateRenew(std::string{"sample"}, std::string{"{\"sample\":true}"});
```

```json
{}
```

### certificateRevoke

Calls `POST /v1/certificates/{certificateId}/revoke`.

```cpp
auto response = client.certificates().certificateRevoke(std::string{"sample"}, std::string{"{\"sample\":true}"});
```

```json
{}
```

### certificateSitesealGet

Calls `GET /v1/certificates/{certificateId}/siteSeal`.

```cpp
auto response = client.certificates().certificateSitesealGet(std::string{"sample"}, std::string{"sample"}, std::string{"sample"});
```

```json
{}
```

### certificateVerifydomaincontrol

Calls `POST /v1/certificates/{certificateId}/verifyDomainControl`.

```cpp
auto response = client.certificates().certificateVerifydomaincontrol(std::string{"sample"});
```

```json
{}
```

### certificateGetEntitlement

Calls `GET /v2/certificates`.

```cpp
auto response = client.certificates().certificateGetEntitlement(std::string{"sample"}, true);
```

```json
{}
```

### certificateCreateV2

Calls `POST /v2/certificates`.

```cpp
auto response = client.certificates().certificateCreateV2(std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

### certificateDownloadEntitlement

Calls `GET /v2/certificates/download`.

```cpp
auto response = client.certificates().certificateDownloadEntitlement(std::string{"sample"});
```

```json
{}
```

### getCustomerCertificatesByCustomerId

Calls `GET /v2/customers/{customerId}/certificates`.

```cpp
auto response = client.certificates().getCustomerCertificatesByCustomerId(std::string{"sample"}, std::int64_t{1}, std::int64_t{1});
```

```json
{}
```

### getCertificateDetailByCertIdentifier

Calls `GET /v2/customers/{customerId}/certificates/{certificateId}`.

```cpp
auto response = client.certificates().getCertificateDetailByCertIdentifier(std::string{"sample"}, std::string{"sample"});
```

```json
{}
```

### getDomainInformationByCertificateId

Calls `GET /v2/customers/{customerId}/certificates/{certificateId}/domainVerifications`.

```cpp
auto response = client.certificates().getDomainInformationByCertificateId(std::string{"sample"}, std::string{"sample"});
```

```json
{}
```

### getDomainDetailsByDomain

Calls `GET /v2/customers/{customerId}/certificates/{certificateId}/domainVerifications/{domain}`.

```cpp
auto response = client.certificates().getDomainDetailsByDomain(std::string{"sample"}, std::string{"sample"}, std::string{"sample"});
```

```json
{}
```

### getAcmeExternalAccountBinding

Calls `GET /v2/customers/{customerId}/certificates/acme/externalAccountBinding`.

```cpp
auto response = client.certificates().getAcmeExternalAccountBinding(std::string{"sample"});
```

```json
{}
```

### retrieveSslByDomainReseller

Calls `GET /v2/certificates/subscriptions/search`.

```cpp
auto response = client.certificates().retrieveSslByDomainReseller(std::int64_t{1}, std::int64_t{1}, std::string{"sample"}, std::vector<std::string>{"sample"}, std::string{"sample"}, std::string{"sample"});
```

```json
{}
```

### retrieveSslByDomainSubscriptionReseller

Calls `GET /v2/certificates/subscription/{guid}`.

```cpp
auto response = client.certificates().retrieveSslByDomainSubscriptionReseller(std::string{"sample"}, std::int64_t{1}, std::int64_t{1}, std::string{"sample"}, std::vector<std::string>{"sample"}, std::string{"sample"}, std::string{"sample"});
```

```json
{}
```

