# SubscriptionsService

Subscription listing and management endpoints for recurring products.

## Accessor

```cpp
auto& service = client.subscriptions();
```

## Endpoints

### list

Calls `GET /v1/subscriptions`.

```cpp
auto response = client.subscriptions().list(std::string{"header-value"}, std::string{"header-value"}, std::string{"header-value"}, std::vector<std::string>{"sample"}, std::vector<std::string>{"sample"}, std::int64_t{1}, std::int64_t{1}, std::string{"sample"});
```

```json
{}
```

### productGroups

Calls `GET /v1/subscriptions/productGroups`.

```cpp
auto response = client.subscriptions().productGroups(std::string{"header-value"}, std::string{"header-value"});
```

```json
{}
```

### cancel

Calls `DELETE /v1/subscriptions/{subscriptionId}`.

```cpp
auto response = client.subscriptions().cancel(std::string{"{\"sample\":true}"}, std::string{"header-value"}, std::string{"header-value"});
```

```json
{}
```

### get

Calls `GET /v1/subscriptions/{subscriptionId}`.

```cpp
auto response = client.subscriptions().get(std::string{"{\"sample\":true}"}, std::string{"header-value"}, std::string{"header-value"});
```

```json
{}
```

### update

Calls `PATCH /v1/subscriptions/{subscriptionId}`.

```cpp
auto response = client.subscriptions().update(std::string{"{\"sample\":true}"}, std::string{"header-value"}, std::string{"{\"sample\":true}"}, std::string{"header-value"});
```

```json
{}
```

