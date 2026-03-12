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
auto response = client.countries().getCountries(
    std::string{"example.com"}
);
```

```json
{
  "countryKey": "US",
  "label": "United States",
  "callingCode": "1"
}
```

### getCountry

Calls `GET /v1/countries/{countryKey}`.

```cpp
auto response = client.countries().getCountry(
    std::string{"example.com"},
    std::string{"example.com"}
);
```

```json
{
  "countryKey": "US",
  "label": "United States",
  "states": [
    {
      "stateKey": "AZ",
      "label": "Arizona"
    }
  ]
}
```





