# AbuseService

Abuse reporting and ticket lookup endpoints for phishing, malware, and related investigations.

## Accessor

```cpp
auto& service = client.abuse();
```

## Endpoints

### getTickets

Calls `GET /v1/abuse/tickets`.

```cpp
auto response = client.abuse().getTickets(std::string{"sample"}, true, std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::int64_t{1}, std::int64_t{1});
```

```json
{}
```

### createTicket

Calls `POST /v1/abuse/tickets`.

```cpp
auto response = client.abuse().createTicket(std::string{"{\"sample\":true}"});
```

```json
{}
```

### getTicketInfo

Calls `GET /v1/abuse/tickets/{ticketId}`.

```cpp
auto response = client.abuse().getTicketInfo(std::string{"sample"});
```

```json
{}
```

### getTicketsV2

Calls `GET /v2/abuse/tickets`.

```cpp
auto response = client.abuse().getTicketsV2(std::string{"sample"}, true, std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::string{"sample"}, std::int64_t{1}, std::int64_t{1});
```

```json
{}
```

### createTicketV2

Calls `POST /v2/abuse/tickets`.

```cpp
auto response = client.abuse().createTicketV2(std::string{"{\"sample\":true}"});
```

```json
{}
```

### getTicketInfoV2

Calls `GET /v2/abuse/tickets/{ticketId}`.

```cpp
auto response = client.abuse().getTicketInfoV2(std::string{"sample"});
```

```json
{}
```

