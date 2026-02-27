# CountriesService

Country and market metadata endpoints used across purchase flows.

## Accessor

```cpp
auto& service = client.countries();
```

## Endpoints

### getCountries

Calls `GET /v1/countries`.

```cpp
auto response = client.countries().getCountries(std::string{"sample"});
```

```json
{}
```

### getCountry

Calls `GET /v1/countries/{countryKey}`.

```cpp
auto response = client.countries().getCountry(std::string{"sample"}, std::string{"sample"});
```

```json
{}
```

