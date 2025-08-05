#ifndef LOCKFREERINGBUFFER_H
#define LOCKFREERINGBUFFER_H

#include <vector>
#include <atomic>
#include <cassert>

template <typename T>
class LockFreeRingBuffer {
public:
    explicit LockFreeRingBuffer(size_t size);
    bool enqueue(const T& item);
    bool dequeue(T& item);

private:
    const size_t size_;
    std::vector<T> buffer_;
    std::atomic<size_t> head_;
    std::atomic<size_t> tail_;
};

#include "LockFreeRingBuffer.cpp"  // Include the implementation
#endif // LOCKFREERINGBUFFER_H
