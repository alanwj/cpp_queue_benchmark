Benchmark Comparision of Queue Implementations
===

This project benchmarks the performance of several options for C++ queue implementations.

Currently, the following implementations are benchmarked:

1. `std::queue` with `std::list` as the underlying container.
1. `std::queue` with `std::deque` as the underlying container.
1. A queue implementation built from two stacks.

Building and Running
--------------------

    cmake -DCMAKE_BUILD_TYPE=Release -S . -B build
    cmake --build build
    build/queue_benchmark

Benchmark results (example run, specific results will depend on C++ implemenation and machine)
---


    ---------------------------------------------------------------------------------------
    Benchmark                                             Time             CPU   Iterations
    ---------------------------------------------------------------------------------------
    BM_Queue<StdQueueWithList>/2048                   34652 ns        34251 ns        20658
    BM_Queue<StdQueueWithList>/4096                   72881 ns        72160 ns        10339
    BM_Queue<StdQueueWithList>/32768                 572084 ns       557907 ns         1222
    BM_Queue<StdQueueWithList>/262144               4736662 ns      4704747 ns          153
    BM_Queue<StdQueueWithList>/1048576             19262911 ns     19028862 ns           37
    BM_Queue<StdQueueWithDeque>/2048                   4719 ns         4662 ns       154254
    BM_Queue<StdQueueWithDeque>/4096                   9119 ns         9053 ns        77505
    BM_Queue<StdQueueWithDeque>/32768                 69428 ns        68942 ns        10129
    BM_Queue<StdQueueWithDeque>/262144               566811 ns       560024 ns         1243
    BM_Queue<StdQueueWithDeque>/1048576             2319454 ns      2306335 ns          309
    BM_Queue<TwoStackQueue<int>>/2048                  5129 ns         5008 ns       141247
    BM_Queue<TwoStackQueue<int>>/4096                 10005 ns         9936 ns        71147
    BM_Queue<TwoStackQueue<int>>/32768                85165 ns        84456 ns         8351
    BM_Queue<TwoStackQueue<int>>/262144              680539 ns       674943 ns         1034
    BM_Queue<TwoStackQueue<int>>/1048576            2963400 ns      2941548 ns          248
    BM_QueueEarlyPop<StdQueueWithList>/2048           26787 ns        26572 ns        26369
    BM_QueueEarlyPop<StdQueueWithList>/4096           55923 ns        55412 ns        13349
    BM_QueueEarlyPop<StdQueueWithList>/32768         436164 ns       432681 ns         1651
    BM_QueueEarlyPop<StdQueueWithList>/262144       3427965 ns      3404879 ns          207
    BM_QueueEarlyPop<StdQueueWithList>/1048576     14128757 ns     14019423 ns           51
    BM_QueueEarlyPop<StdQueueWithDeque>/2048           3054 ns         3024 ns       233425
    BM_QueueEarlyPop<StdQueueWithDeque>/4096           6162 ns         6090 ns       117109
    BM_QueueEarlyPop<StdQueueWithDeque>/32768         48486 ns        48155 ns        14499
    BM_QueueEarlyPop<StdQueueWithDeque>/262144       414441 ns       411464 ns         1823
    BM_QueueEarlyPop<StdQueueWithDeque>/1048576     1553564 ns      1541426 ns          456
    BM_QueueEarlyPop<TwoStackQueue<int>>/2048          5487 ns         5436 ns       129838
    BM_QueueEarlyPop<TwoStackQueue<int>>/4096         11133 ns        10994 ns        64777
    BM_QueueEarlyPop<TwoStackQueue<int>>/32768        87737 ns        87021 ns         7979
    BM_QueueEarlyPop<TwoStackQueue<int>>/262144      709287 ns       705000 ns         1008
    BM_QueueEarlyPop<TwoStackQueue<int>>/1048576    2831711 ns      2804940 ns          247
