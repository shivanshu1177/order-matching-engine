#include "LockFreeRingBuffer.h"

template <typename T>
LockFreeRingBuffer<T>::LockFreeRingBuffer(size_t size)
    : size_(size), buffer_(size), head_(0), tail_(0) {
    assert((size_ & (size_ - 1)) == 0 && "Size must be a power of 2");
}

template <typename T>
bool LockFreeRingBuffer<T>::enqueue(const T& item) {
    const auto next = (head_ + 1) & (size_ - 1);  // Wrap around
    if (next == tail_.load(std::memory_order_acquire)) {
        return false;  // Buffer is full
    }
    buffer_[head_] = item;
    head_ = next;
    return true;
}

template <typename T>
bool LockFreeRingBuffer<T>::dequeue(T& item) {
    if (tail_ == head_) {
        return false;  // Buffer is empty
    }
    item = buffer_[tail_];
    tail_ = (tail_ + 1) & (size_ - 1);  // Wrap around
    return true;
}

// Explicit template instantiation for commonly used types
template class LockFreeRingBuffer<std::variant<OrderEntryMessage, CancelMessage, ModifyMessage>>;
