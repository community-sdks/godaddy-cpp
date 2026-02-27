#pragma once

#include "godaddy/service_base.hpp"

namespace godaddy {

class CountriesService final : public BaseService {
public:
    explicit CountriesService(ApiClient& client);
    Result getCountries(const Value& marketId);
    Result getCountry(const Value& countryKey, const Value& marketId);
};

}  // namespace godaddy
