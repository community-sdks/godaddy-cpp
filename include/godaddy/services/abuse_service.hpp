#pragma once

#include "godaddy/service_base.hpp"

namespace godaddy {

class AbuseService final : public BaseService {
public:
    explicit AbuseService(ApiClient& client);
    Result getTickets(const Value& typeValue = {}, const Value& closed = {}, const Value& sourceDomainOrIp = {}, const Value& target = {}, const Value& createdStart = {}, const Value& createdEnd = {}, const Value& limit = {}, const Value& offset = {});
    Result createTicket(const Value& body);
    Result getTicketInfo(const Value& ticketId);
    Result getTicketsV2(const Value& typeValue = {}, const Value& closed = {}, const Value& sourceDomainOrIp = {}, const Value& target = {}, const Value& createdStart = {}, const Value& createdEnd = {}, const Value& limit = {}, const Value& offset = {});
    Result createTicketV2(const Value& body);
    Result getTicketInfoV2(const Value& ticketId);
};

}  // namespace godaddy
