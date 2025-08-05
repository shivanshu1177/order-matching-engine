#include "MessageDispatcher.h"

void MessageDispatcher::dispatch(Message& msg) {
    if (std::holds_alternative<OrderEntryMessage>(msg)) {
        handleOrderEntry(std::get<OrderEntryMessage>(msg));
    } else if (std::holds_alternative<CancelMessage>(msg)) {
        handleCancel(std::get<CancelMessage>(msg));
    } else if (std::holds_alternative<ModifyMessage>(msg)) {
        handleModify(std::get<ModifyMessage>(msg));
    }
}

void MessageDispatcher::handleOrderEntry(const OrderEntryMessage& msg) {
    std::cout << "Handling Order Entry: " << msg.order_id << "\n";
}

void MessageDispatcher::handleCancel(const CancelMessage& msg) {
    std::cout << "Handling Cancel: " << msg.order_id << "\n";
}

void MessageDispatcher::handleModify(const ModifyMessage& msg) {
    std::cout << "Handling Modify: " << msg.order_id << "\n";
}
