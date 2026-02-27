#include "godaddy/http.hpp"

namespace godaddy {

Response HttpTransport::send(const Request&) {
    return Response{200, {{"content-type", "application/json"}}, "{}"};
}

}  // namespace godaddy
