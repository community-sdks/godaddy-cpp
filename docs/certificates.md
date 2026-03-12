# CertificatesService

SSL certificate purchase, validation, lifecycle, and revocation endpoints.

## Accessor

```cpp
auto& service = client.certificates();
```

## Endpoints

### create

Calls `POST /v1/certificates`.

```cpp
auto response = client.certificates().create(
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "certificateId": "crt_123456",
  "status": "PENDING_ISSUANCE"
}
```

### validate

Calls `POST /v1/certificates/validate`.

```cpp
auto response = client.certificates().validate(
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "valid": false,
  "issues": [
    {
      "path": "dnsNames[0]",
      "message": "SAN entry is invalid"
    }
  ]
}
```

### get

Calls `GET /v1/certificates/{certificateId}`.

```cpp
auto response = client.certificates().get(
    std::string{"example.com"}
);
```

```json
{
  "certificateId": "crt_123456",
  "status": "PENDING_ISSUANCE"
}
```

### listActions

Calls `GET /v1/certificates/{certificateId}/actions`.

```cpp
auto response = client.certificates().listActions(
    std::string{"example.com"}
);
```

```json
{
  "certificateId": "crt_123456",
  "status": "ISSUED",
  "commonName": "example.com",
  "expires": "2027-03-11T00:00:00Z"
}
```

### resendEmail

Calls `POST /v1/certificates/{certificateId}/email/{emailId}/resend`.

```cpp
auto response = client.certificates().resendEmail(
    std::string{"example.com"},
    std::string{"example.com"}
);
```

```json
{
  "certificateId": "crt_123456",
  "status": "PENDING_ISSUANCE"
}
```

### addAlternateEmailAddress

Calls `POST /v1/certificates/{certificateId}/email/resend/{emailAddress}`.

```cpp
auto response = client.certificates().addAlternateEmailAddress(
    std::string{"example.com"},
    std::vector<std::string>{"example.com"}
);
```

```json
{
  "certificateId": "crt_123456",
  "status": "PENDING_ISSUANCE"
}
```

### resendEmailToAddress

Calls `POST /v1/certificates/{certificateId}/email/{emailId}/resend/{emailAddress}`.

```cpp
auto response = client.certificates().resendEmailToAddress(
    std::string{"example.com"},
    std::string{"example.com"},
    std::vector<std::string>{"example.com"}
);
```

```json
{
  "certificateId": "crt_123456",
  "status": "PENDING_ISSUANCE"
}
```

### getEmailHistory

Calls `GET /v1/certificates/{certificateId}/email/history`.

```cpp
auto response = client.certificates().getEmailHistory(
    std::string{"example.com"}
);
```

```json
{
  "history": [
    {
      "emailId": "mail_1",
      "emailAddress": "admin@example.com",
      "status": "SENT",
      "createdAt": "2026-03-11T12:00:00Z"
    }
  ]
}
```

### deleteCallback

Calls `DELETE /v1/certificates/{certificateId}/callback`.

```cpp
auto response = client.certificates().deleteCallback(
    std::string{"example.com"}
);
```

```json
{
  "callbackUrl": "https://example.com/callback",
  "enabled": true
}
```

### getCallback

Calls `GET /v1/certificates/{certificateId}/callback`.

```cpp
auto response = client.certificates().getCallback(
    std::string{"example.com"}
);
```

```json
{
  "callbackUrl": "https://example.com/callback",
  "enabled": true
}
```

### replaceCallback

Calls `PUT /v1/certificates/{certificateId}/callback`.

```cpp
auto response = client.certificates().replaceCallback(
    std::string{"example.com"},
    std::string{"example.com"}
);
```

```json
{
  "callbackUrl": "https://example.com/callback",
  "enabled": true
}
```

### cancel

Calls `POST /v1/certificates/{certificateId}/cancel`.

```cpp
auto response = client.certificates().cancel(
    std::string{"example.com"}
);
```

```json
{
  "certificateId": "crt_123456",
  "status": "PENDING_ISSUANCE"
}
```

### download

Calls `GET /v1/certificates/{certificateId}/download`.

```cpp
auto response = client.certificates().download(
    std::string{"example.com"}
);
```

```json
{
  "certificate": "-----BEGIN CERTIFICATE-----...",
  "privateKey": "-----BEGIN PRIVATE KEY-----...",
  "caBundle": "-----BEGIN CERTIFICATE-----..."
}
```

### reissue

Calls `POST /v1/certificates/{certificateId}/reissue`.

```cpp
auto response = client.certificates().reissue(
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"}
);
```

```json
{
  "certificateId": "crt_123456",
  "status": "PENDING_ISSUANCE"
}
```

### renew

Calls `POST /v1/certificates/{certificateId}/renew`.

```cpp
auto response = client.certificates().renew(
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"}
);
```

```json
{
  "certificateId": "crt_123456",
  "status": "PENDING_ISSUANCE"
}
```

### revoke

Calls `POST /v1/certificates/{certificateId}/revoke`.

```cpp
auto response = client.certificates().revoke(
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"}
);
```

```json
{
  "certificateId": "crt_123456",
  "status": "PENDING_ISSUANCE"
}
```

### getSiteSeal

Calls `GET /v1/certificates/{certificateId}/siteSeal`.

```cpp
auto response = client.certificates().getSiteSeal(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"}
);
```

```json
{
  "html": "<div>Site Seal</div>"
}
```

### verifyDomainControl

Calls `POST /v1/certificates/{certificateId}/verifyDomainControl`.

```cpp
auto response = client.certificates().verifyDomainControl(
    std::string{"example.com"}
);
```

```json
{
  "certificateId": "crt_123456",
  "status": "PENDING_ISSUANCE"
}
```

### getByEntitlement

Calls `GET /v2/certificates`.

```cpp
auto response = client.certificates().getByEntitlement(
    std::string{"example.com"},
    true
);
```

```json
{
  "certificates": [
    {
      "certificateId": "crt_123456",
      "commonName": "example.com",
      "status": "ISSUED",
      "expires": "2027-03-11T00:00:00Z"
    }
  ],
  "pagination": {
    "total": 1,
    "start": 0,
    "limit": 25
  }
}
```

### createForEntitlement

Calls `POST /v2/certificates`.

```cpp
auto response = client.certificates().createForEntitlement(
    std::string{R"({"domain":"example.com"})"},
    std::string{"123456"}
);
```

```json
{
  "certificateId": "crt_123456",
  "status": "PENDING_ISSUANCE"
}
```

### downloadByEntitlement

Calls `GET /v2/certificates/download`.

```cpp
auto response = client.certificates().downloadByEntitlement(
    std::string{"example.com"}
);
```

```json
{
  "certificate": "-----BEGIN CERTIFICATE-----...",
  "privateKey": "-----BEGIN PRIVATE KEY-----...",
  "caBundle": "-----BEGIN CERTIFICATE-----..."
}
```

### listCustomerCertificates

Calls `GET /v2/customers/{customerId}/certificates`.

```cpp
auto response = client.certificates().listCustomerCertificates(
    std::string{"example.com"},
    std::int64_t{1},
    std::int64_t{1}
);
```

```json
{
  "certificates": [
    {
      "certificateId": "crt_123456",
      "commonName": "example.com",
      "status": "ISSUED",
      "expires": "2027-03-11T00:00:00Z"
    }
  ],
  "pagination": {
    "total": 1,
    "start": 0,
    "limit": 25
  }
}
```

### getCustomerCertificate

Calls `GET /v2/customers/{customerId}/certificates/{certificateId}`.

```cpp
auto response = client.certificates().getCustomerCertificate(
    std::string{"example.com"},
    std::string{"example.com"}
);
```

```json
{
  "certificateId": "crt_123456",
  "status": "PENDING_ISSUANCE"
}
```

### listDomainVerifications

Calls `GET /v2/customers/{customerId}/certificates/{certificateId}/domainVerifications`.

```cpp
auto response = client.certificates().listDomainVerifications(
    std::string{"example.com"},
    std::string{"example.com"}
);
```

```json
{
  "certificates": [
    {
      "certificateId": "crt_123456",
      "commonName": "example.com",
      "status": "ISSUED",
      "expires": "2027-03-11T00:00:00Z"
    }
  ],
  "pagination": {
    "total": 1,
    "start": 0,
    "limit": 25
  }
}
```

### getDomainVerificationDetails

Calls `GET /v2/customers/{customerId}/certificates/{certificateId}/domainVerifications/{domain}`.

```cpp
auto response = client.certificates().getDomainVerificationDetails(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"}
);
```

```json
{
  "domain": "example.com",
  "method": "DNS",
  "status": "PENDING",
  "token": "_acme-challenge",
  "value": "token-value"
}
```

### getAcmeExternalAccountBinding

Calls `GET /v2/customers/{customerId}/certificates/acme/externalAccountBinding`.

```cpp
auto response = client.certificates().getAcmeExternalAccountBinding(
    std::string{"example.com"}
);
```

```json
{
  "kid": "kid_123",
  "hmacKey": "hmac_abc"
}
```

### searchSubscriptionsByDomain

Calls `GET /v2/certificates/subscriptions/search`.

```cpp
auto response = client.certificates().searchSubscriptionsByDomain(
    std::int64_t{1},
    std::int64_t{1},
    std::string{"example.com"},
    std::vector<std::string>{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"}
);
```

```json
{
  "certificates": [
    {
      "certificateId": "crt_123456",
      "commonName": "example.com",
      "status": "ISSUED",
      "expires": "2027-03-11T00:00:00Z"
    }
  ],
  "pagination": {
    "total": 1,
    "start": 0,
    "limit": 25
  }
}
```

### listSubscriptionCertificates

Calls `GET /v2/certificates/subscription/{guid}`.

```cpp
auto response = client.certificates().listSubscriptionCertificates(
    std::string{"example.com"},
    std::int64_t{1},
    std::int64_t{1},
    std::string{"example.com"},
    std::vector<std::string>{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"}
);
```

```json
{
  "certificates": [
    {
      "certificateId": "crt_123456",
      "commonName": "example.com",
      "status": "ISSUED",
      "expires": "2027-03-11T00:00:00Z"
    }
  ],
  "pagination": {
    "total": 1,
    "start": 0,
    "limit": 25
  }
}
```






