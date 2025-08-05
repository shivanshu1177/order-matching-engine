#ifndef BENCHMARK_H
#define BENCHMARK_H

#include <chrono>
#include "LockFreeRingBuffer.h"
#include "MessageDispatcher.h"

void runBenchmark(size_t num_messages);

#endif // BENCHMARK_H