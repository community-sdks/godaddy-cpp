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
auto response = client.agreements().get(std::vector<std::string>{"sample"}, std::string{"header-value"}, std::string{"header-value"});
```

```json
{}
```

