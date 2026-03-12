# AnsService

Authoritative DNS record and nameserver management endpoints.

## Accessor

```cpp
auto& service = client.ans();
```

## Endpoints

### searchAnsName

Calls `GET /v1/agents`.

```cpp
auto response = client.ans().search(
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::int64_t{1},
    std::int64_t{1}
);
```

```json
{
  "agents": [
    {
      "agentId": "agt_001",
      "displayName": "Checkout Agent",
      "protocol": "MCP",
      "status": "ACTIVE"
    }
  ],
  "pagination": {
    "limit": 1,
    "offset": 1,
    "total": 1
  }
}
```

### registerAgent

Calls `POST /v1/agents/register`.

```cpp
auto response = client.ans().registerAgent(
    std::string{R"({"domain":"example.com"})"}
);
```

```json
{
  "agentId": "agt_001",
  "status": "ACTIVE",
  "displayName": "Checkout Agent",
  "endpoints": [
    {
      "url": "https://agent.example.com",
      "protocol": "MCP",
      "status": "ACTIVE"
    }
  ]
}
```

### resolveAnsName

Calls `POST /v1/agents/resolution`.

```cpp
auto response = client.ans().resolve(
    std::string{R"({"domain":"example.com"})"}
);
```

```json
{
  "agentId": "agt_001",
  "resolvedHost": "agent.example.com",
  "protocol": "MCP",
  "status": "ACTIVE"
}
```

### getAgent

Calls `GET /v1/agents/{agentId}`.

```cpp
auto response = client.ans().get(
    std::string{"example.com"}
);
```

```json
{
  "agentId": "agt_001",
  "displayName": "Checkout Agent",
  "protocol": "MCP",
  "status": "ACTIVE",
  "createdAt": "2026-03-11T12:00:00Z"
}
```

### validateRegistration

Calls `POST /v1/agents/{agentId}/verify-acme`.

```cpp
auto response = client.ans().verifyAcme(
    std::string{"example.com"}
);
```

```json
{
  "agentId": "agt_001",
  "acmeChallenge": "_acme-challenge.agent.example.com",
  "token": "acme-token-123",
  "status": "PENDING"
}
```

### verifyDnsRecords

Calls `POST /v1/agents/{agentId}/verify-dns`.

```cpp
auto response = client.ans().verifyDns(
    std::string{"example.com"}
);
```

```json
{
  "agentId": "agt_001",
  "dnsVerified": true,
  "verifiedAt": "2026-03-11T12:00:00Z"
}
```

### getAgentIdentityCertificateByAgentId

Calls `GET /v1/agents/{agentId}/certificates/identity`.

```cpp
auto response = client.ans().getIdentityCertificates(
    std::string{"example.com"}
);
```

```json
{
  "certificates": [
    {
      "id": "cert_identity_001",
      "type": "IDENTITY",
      "status": "ISSUED",
      "expiresAt": "2027-03-11T00:00:00Z"
    }
  ]
}
```

### submitAgentIdentityCsrByAgentId

Calls `POST /v1/agents/{agentId}/certificates/identity`.

```cpp
auto response = client.ans().submitIdentityCsr(
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"}
);
```

```json
{
  "csrId": "csr_identity_001",
  "status": "PENDING_VALIDATION",
  "submittedAt": "2026-03-11T12:00:00Z"
}
```

### getAgentServerCertificateByAgentId

Calls `GET /v1/agents/{agentId}/certificates/server`.

```cpp
auto response = client.ans().getServerCertificates(
    std::string{"example.com"}
);
```

```json
{
  "certificates": [
    {
      "id": "cert_server_001",
      "type": "SERVER",
      "status": "ISSUED",
      "expiresAt": "2027-03-11T00:00:00Z"
    }
  ]
}
```

### submitAgentServerCsrByAgentId

Calls `POST /v1/agents/{agentId}/certificates/server`.

```cpp
auto response = client.ans().submitServerCsr(
    std::string{"example.com"},
    std::string{R"({"domain":"example.com"})"}
);
```

```json
{
  "csrId": "csr_server_001",
  "status": "PENDING_VALIDATION",
  "submittedAt": "2026-03-11T12:00:00Z"
}
```

### getAgentCsrStatusByAgentId

Calls `GET /v1/agents/{agentId}/csrs/{csrId}/status`.

```cpp
auto response = client.ans().getCsrStatus(
    std::string{"example.com"},
    std::string{"example.com"}
);
```

```json
{
  "csrId": "csr_server_001",
  "status": "ISSUED",
  "updatedAt": "2026-03-11T12:05:00Z"
}
```

### getAgentEvents

Calls `GET /v1/agents/events`.

```cpp
auto response = client.ans().events(
    std::string{"123456"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::int64_t{1}
);
```

```json
{
  "events": [
    {
      "eventId": "evt_1001",
      "agentId": "agt_001",
      "type": "CERTIFICATE_ISSUED",
      "createdAt": "2026-03-11T12:05:00Z"
    }
  ]
}
```








