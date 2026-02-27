#include "godaddy/http.hpp"

#include <sstream>

namespace godaddy {

std::string Request::full_url() const {
    if (query.empty()) return url;
    std::ostringstream stream;
    stream << url << "?";
    for (std::size_t index = 0; index < query.size(); ++index) {
        if (index > 0) stream << "&";
        stream << query[index].first << "=" << query[index].second;
    }
    return stream.str();
}

}  // namespace godaddy
