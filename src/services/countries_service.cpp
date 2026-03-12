#include "godaddy/services/countries_service.hpp"

namespace godaddy {

CountriesService::CountriesService(ApiClient& client) : BaseService(client, "countries") {}

Result CountriesService::getCountries(const Value& marketId) {
    return call(
        "GET",
        "/v1/countries",
        {},
        {{"marketId", marketId}},
        {},
        Value{}
    );
}

Result CountriesService::getCountry(const Value& countryKey, const Value& marketId) {
    return call(
        "GET",
        "/v1/countries/{countryKey}",
        {{"countryKey", countryKey}},
        {{"marketId", marketId}},
        {},
        Value{}
    );
}

}  // namespace godaddy
