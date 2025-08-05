# Order Matching Engine in C++

This project implements a high-performance order matching engine using a lock-free ring buffer in C++17. The system supports multi-producer, single-consumer scenarios, and is optimized for high-throughput and low-latency processing of market orders.

## Features:
- Lock-free ring buffer for efficient message queuing
- Message dispatcher with compile-time routing using `if constexpr`
- Benchmarking setup for measuring throughput and latency

## Getting Started

### Prerequisites
- CMake 3.10 or later
- A C++17 compatible compiler

### Build Instructions

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/order-matching-engine.git
    cd order-matching-engine
    ```

2. Create a build directory:
    ```bash
    mkdir build
    cd build
    ```

3. Run CMake and build:
    ```bash
    cmake ..
    make
    ```

4. Run the benchmark:
    ```bash
    ./OrderMatchingEngine
    ```

### Example Output
Processed 1000000 messages in 9.3845 seconds.
Throughput: 106561.7 messages/sec