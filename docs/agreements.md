# AgreementsService

Agreement retrieval endpoints for legal terms and consent workflows.

## Accessor

```cpp
auto& service = client.agreements();
```

## Endpoints

### get

Calls `GET /v1/agreements`.

```cpp
auto response = client.agreements().get(
    std::vector<std::string>{"example.com"},
    std::string{"123456"},
    std::string{"123456"}
);
```

```json
{
  "agreementKey": "DNRA",
  "title": "Domain Name Registration Agreement",
  "url": "https://www.godaddy.com/legal/agreements/domain-registration"
}
```





