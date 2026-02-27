# ShoppersService

Shopper profile, account, and delegated access endpoints.

## Accessor

```cpp
auto& service = client.shoppers();
```

## Endpoints

### createSubaccount

Calls `POST /v1/shoppers/subaccount`.

```cpp
auto response = client.shoppers().createSubaccount(std::string{"{\"sample\":true}"});
```

```json
{}
```

### get

Calls `GET /v1/shoppers/{shopperId}`.

```cpp
auto response = client.shoppers().get(std::string{"{\"sample\":true}"}, std::vector<std::string>{"sample"});
```

```json
{}
```

### update

Calls `POST /v1/shoppers/{shopperId}`.

```cpp
auto response = client.shoppers().update(std::string{"{\"sample\":true}"}, std::string{"{\"sample\":true}"});
```

```json
{}
```

### delete

Calls `DELETE /v1/shoppers/{shopperId}`.

```cpp
auto response = client.shoppers().delete(std::string{"{\"sample\":true}"}, std::string{"sample"});
```

```json
{}
```

### getStatus

Calls `GET /v1/shoppers/{shopperId}/status`.

```cpp
auto response = client.shoppers().getStatus(std::string{"{\"sample\":true}"}, std::string{"sample"});
```

```json
{}
```

### changePassword

Calls `PUT /v1/shoppers/{shopperId}/factors/password`.

```cpp
auto response = client.shoppers().changePassword(std::string{"{\"sample\":true}"}, std::string{"{\"sample\":true}"});
```

```json
{}
```

