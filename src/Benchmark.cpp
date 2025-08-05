#include "Benchmark.h"
#include <atomic>
#include <thread>
#include <iostream>

void runBenchmark(size_t num_messages) {
    LockFreeRingBuffer<Message> buffer(1024);  // 1024-sized ring buffer
    MessageDispatcher dispatcher;

    auto start_time = std::chrono::high_resolution_clock::now();

    // Simulate producers
    std::thread producer([&]() {
        for (size_t i = 0; i < num_messages; ++i) {
            OrderEntryMessage msg = {static_cast<int>(i), 100.0, 10};
            while (!buffer.enqueue(msg)) {
                std::this_thread::yield();  // Wait until there's space
            }
        }
    });

    // Simulate consumers
    std::atomic<size_t> processed_count{0};
    std::thread consumer([&]() {
        Message msg;
        while (processed_count < num_messages) {
            if (buffer.dequeue(msg)) {
                dispatcher.dispatch(msg);
                ++processed_count;
            }
        }
    });

    producer.join();
    consumer.join();

    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end_time - start_time;

    double messages_per_sec = num_messages / elapsed.count();
    std::cout << "Processed " << num_messages << " messages in " << elapsed.count() << " seconds.\n";
    std::cout << "Throughput: " << messages_per_sec << " messages/sec\n";
}
