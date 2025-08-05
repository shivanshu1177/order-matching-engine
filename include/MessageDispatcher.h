#ifndef MESSAGEDISPATCHER_H
#define MESSAGEDISPATCHER_H

#include <variant>
#include <iostream>
#include <span>

enum class MessageType {
    OrderEntry,
    Cancel,
    Modify
};

struct OrderEntryMessage {
    int order_id;
    double price;
    int quantity;
};

struct CancelMessage {
    int order_id;
};

struct ModifyMessage {
    int order_id;
    double new_price;
    int new_quantity;
};

using Message = std::variant<OrderEntryMessage, CancelMessage, ModifyMessage>;

class MessageDispatcher {
public:
    void dispatch(Message& msg);
private:
    void handleOrderEntry(const OrderEntryMessage& msg);
    void handleCancel(const CancelMessage& msg);
    void handleModify(const ModifyMessage& msg);
};

#endif // MESSAGEDISPATCHER_H
