
#include <pthread.h>

#include <chrono>
#include <cstdio>

constexpr size_t
#if defined(__cpp_lib_hardware_interference_size)
    CACHE_LINE_SIZE = hardware_destructive_interference_size,
#else
    CACHE_LINE_SIZE = 64,
#endif
    MAX_THREADS = 8, MANY_ITERATIONS = 1000000000;

void* worker(void* arg)
{
    volatile int* counter = (int*)arg;
    for(int i = 0; i < MANY_ITERATIONS; i++) (*counter)++;
    return NULL;
}
void test1(int num_threads)
{
    auto begin = std::chrono::high_resolution_clock::now();

    pthread_t threads[MAX_THREADS];
    int counter[MAX_THREADS];

    for(int i = 0; i < num_threads; i++)
        pthread_create(&threads[i], NULL, &worker, &counter[i]);
    for(int i = 0; i < num_threads; i++) pthread_join(threads[i], NULL);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
}

struct padded_t
{
    int counter;
    char padding[CACHE_LINE_SIZE - sizeof(int)];
};
void test2(int num_threads)
{
    auto begin = std::chrono::high_resolution_clock::now();

    pthread_t threads[MAX_THREADS];
    padded_t counter[MAX_THREADS];

    for(int i = 0; i < num_threads; i++)
        pthread_create(&threads[i], NULL, &worker, &(counter[i].counter));
    for(int i = 0; i < num_threads; i++) pthread_join(threads[i], NULL);

    auto end = std::chrono::high_resolution_clock::now();
    auto elapsed =
        std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
    printf("Time measured: %.3f seconds.\n", elapsed.count() * 1e-9);
}

int main()
{
    test1(8);
    test2(8);
}