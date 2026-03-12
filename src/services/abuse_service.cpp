#include "godaddy/services/abuse_service.hpp"

namespace godaddy {

AbuseService::AbuseService(ApiClient& client) : BaseService(client, "abuse") {}

Result AbuseService::getTickets(const Value& typeValue, const Value& closed, const Value& sourceDomainOrIp, const Value& target, const Value& createdStart, const Value& createdEnd, const Value& limit, const Value& offset) {
    return call(
        "GET",
        "/v1/abuse/tickets",
        {},
        {{"type", typeValue}, {"closed", closed}, {"sourceDomainOrIp", sourceDomainOrIp}, {"target", target}, {"createdStart", createdStart}, {"createdEnd", createdEnd}, {"limit", limit}, {"offset", offset}},
        {},
        Value{}
    );
}

Result AbuseService::createTicket(const Value& body) {
    return call(
        "POST",
        "/v1/abuse/tickets",
        {},
        {},
        {},
        body
    );
}

Result AbuseService::getTicketInfo(const Value& ticketId) {
    return call(
        "GET",
        "/v1/abuse/tickets/{ticketId}",
        {{"ticketId", ticketId}},
        {},
        {},
        Value{}
    );
}

Result AbuseService::getTicketsV2(const Value& typeValue, const Value& closed, const Value& sourceDomainOrIp, const Value& target, const Value& createdStart, const Value& createdEnd, const Value& limit, const Value& offset) {
    return call(
        "GET",
        "/v2/abuse/tickets",
        {},
        {{"type", typeValue}, {"closed", closed}, {"sourceDomainOrIp", sourceDomainOrIp}, {"target", target}, {"createdStart", createdStart}, {"createdEnd", createdEnd}, {"limit", limit}, {"offset", offset}},
        {},
        Value{}
    );
}

Result AbuseService::createTicketV2(const Value& body) {
    return call(
        "POST",
        "/v2/abuse/tickets",
        {},
        {},
        {},
        body
    );
}

Result AbuseService::getTicketInfoV2(const Value& ticketId) {
    return call(
        "GET",
        "/v2/abuse/tickets/{ticketId}",
        {{"ticketId", ticketId}},
        {},
        {},
        Value{}
    );
}

}  // namespace godaddy
