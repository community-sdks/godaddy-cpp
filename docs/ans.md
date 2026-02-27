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
auto response = client.ans().searchAnsName(std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::int64_t{1}, std::int64_t{1});
```

```json
{}
```

### registerAgent

Calls `POST /v1/agents/register`.

```cpp
auto response = client.ans().registerAgent(std::string{"{\"sample\":true}"});
```

```json
{}
```

### resolveAnsName

Calls `POST /v1/agents/resolution`.

```cpp
auto response = client.ans().resolveAnsName(std::string{"{\"sample\":true}"});
```

```json
{}
```

### getAgent

Calls `GET /v1/agents/{agentId}`.

```cpp
auto response = client.ans().getAgent(std::string{"sample"});
```

```json
{}
```

### validateRegistration

Calls `POST /v1/agents/{agentId}/verify-acme`.

```cpp
auto response = client.ans().validateRegistration(std::string{"sample"});
```

```json
{}
```

### verifyDnsRecords

Calls `POST /v1/agents/{agentId}/verify-dns`.

```cpp
auto response = client.ans().verifyDnsRecords(std::string{"sample"});
```

```json
{}
```

### getAgentIdentityCertificateByAgentId

Calls `GET /v1/agents/{agentId}/certificates/identity`.

```cpp
auto response = client.ans().getAgentIdentityCertificateByAgentId(std::string{"sample"});
```

```json
{}
```

### submitAgentIdentityCsrByAgentId

Calls `POST /v1/agents/{agentId}/certificates/identity`.

```cpp
auto response = client.ans().submitAgentIdentityCsrByAgentId(std::string{"sample"}, std::string{"{\"sample\":true}"});
```

```json
{}
```

### getAgentServerCertificateByAgentId

Calls `GET /v1/agents/{agentId}/certificates/server`.

```cpp
auto response = client.ans().getAgentServerCertificateByAgentId(std::string{"sample"});
```

```json
{}
```

### submitAgentServerCsrByAgentId

Calls `POST /v1/agents/{agentId}/certificates/server`.

```cpp
auto response = client.ans().submitAgentServerCsrByAgentId(std::string{"sample"}, std::string{"{\"sample\":true}"});
```

```json
{}
```

### getAgentCsrStatusByAgentId

Calls `GET /v1/agents/{agentId}/csrs/{csrId}/status`.

```cpp
auto response = client.ans().getAgentCsrStatusByAgentId(std::string{"sample"}, std::string{"sample"});
```

```json
{}
```

### getAgentEvents

Calls `GET /v1/agents/events`.

```cpp
auto response = client.ans().getAgentEvents(std::string{"header-value"}, std::string{"sample"}, std::string{"sample"}, std::int64_t{1});
```

```json
{}
```

