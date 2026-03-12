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
auto response = client.abuse().getTickets(
    std::string{"example.com"},
    true,
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::int64_t{1},
    std::int64_t{1}
);
```

```json
{
  "ticketIds": [
    "TCK-100001"
  ],
  "pagination": {
    "total": 1,
    "start": 0,
    "limit": 25
  }
}
```

### createTicket

Calls `POST /v1/abuse/tickets`.

```cpp
auto response = client.abuse().createTicket(
    std::string{R"({"domain":"example.com"})"}
);
```

```json
{
  "ticketId": "TCK-100001"
}
```

### getTicketInfo

Calls `GET /v1/abuse/tickets/{ticketId}`.

```cpp
auto response = client.abuse().getTicketInfo(
    std::string{"example.com"}
);
```

```json
{
  "ticketId": "TCK-100001",
  "type": "PHISHING",
  "source": "203.0.113.10",
  "target": "example.com",
  "closed": false,
  "notes": [
    {
      "message": "Initial report",
      "createdAt": "2026-03-11T12:00:00Z"
    }
  ]
}
```

### getTicketsV2

Calls `GET /v2/abuse/tickets`.

```cpp
auto response = client.abuse().getTicketsV2(
    std::string{"example.com"},
    true,
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::string{"example.com"},
    std::int64_t{1},
    std::int64_t{1}
);
```

```json
{
  "ticketIds": [
    "TCK-100001"
  ],
  "pagination": {
    "total": 1,
    "start": 0,
    "limit": 25
  }
}
```

### createTicketV2

Calls `POST /v2/abuse/tickets`.

```cpp
auto response = client.abuse().createTicketV2(
    std::string{R"({"domain":"example.com"})"}
);
```

```json
{
  "ticketId": "TCK-100001"
}
```

### getTicketInfoV2

Calls `GET /v2/abuse/tickets/{ticketId}`.

```cpp
auto response = client.abuse().getTicketInfoV2(
    std::string{"example.com"}
);
```

```json
{
  "ticketId": "TCK-100001",
  "type": "PHISHING",
  "source": "203.0.113.10",
  "target": "example.com",
  "closed": false,
  "notes": [
    {
      "message": "Initial report",
      "createdAt": "2026-03-11T12:00:00Z"
    }
  ]
}
```





