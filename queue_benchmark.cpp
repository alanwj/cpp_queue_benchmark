#include <benchmark/benchmark.h>

#include <list>
#include <queue>

#include "two_stack_queue.h"

template <class Queue>
void BM_Queue(benchmark::State& state) {
  Queue q;
  const int kMax = state.range(0);
  for (auto _ : state) {
    for (int i = 0; i < kMax; ++i) {
      q.push(i);
    }
    for (int i = 0; i < kMax; ++i) {
      q.pop();
    }
  }
}

template <class Queue>
void BM_QueueEarlyPop(benchmark::State& state) {
  Queue q;
  const int kMax = state.range(0);
  for (auto _ : state) {
    for (int i = 0; i < kMax; ++i) {
      q.push(i);
      q.pop();
    }
  }
}

inline constexpr int kMinRange = 1 << 11;
inline constexpr int kMaxRange = 1 << 20;

using StdQueueWithDeque = std::queue<int>;
using StdQueueWithList = std::queue<int, std::list<int>>;

BENCHMARK(BM_Queue<StdQueueWithList>)->Range(kMinRange, kMaxRange);
BENCHMARK(BM_Queue<StdQueueWithDeque>)->Range(kMinRange, kMaxRange);
BENCHMARK(BM_Queue<TwoStackQueue<int>>)->Range(kMinRange, kMaxRange);

BENCHMARK(BM_QueueEarlyPop<StdQueueWithList>)->Range(kMinRange, kMaxRange);
BENCHMARK(BM_QueueEarlyPop<StdQueueWithDeque>)->Range(kMinRange, kMaxRange);
BENCHMARK(BM_QueueEarlyPop<TwoStackQueue<int>>)->Range(kMinRange, kMaxRange);

BENCHMARK_MAIN();
