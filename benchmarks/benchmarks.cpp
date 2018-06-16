#include <list>
#include "inc/benchmark.h"
#include "fixed_allocator.h"
#include "test_helper.h"

using atl::TestHelper;
using atl::LargeObject;

const size_t PUSH_AMOUNT = 10000000;//10^7
const size_t POP_AMOUNT  =  5000000;//half
const size_t PUSH_LARGE_AMOUNT = 20000;//10^4
const size_t POP_LARGE_AMOUNT  = 2400;//half

/*
* pushes
*/
static void BM_std_push_int(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::list<int> test_list;
        state.ResumeTiming();
        TestHelper::push_rnd_values(test_list, PUSH_AMOUNT);
    }
}

static void BM_atl_push_int(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::list<int, atl::allocator<int>> test_list;
        state.ResumeTiming();
        TestHelper::push_rnd_values(test_list, PUSH_AMOUNT);
    }
}

static void BM_std_push_string(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::list<std::string> test_list;
        state.ResumeTiming();
        TestHelper::push_rnd_values(test_list, PUSH_AMOUNT);
    }
}

static void BM_atl_push_string(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::list<std::string, atl::allocator<std::string>> test_list;
        state.ResumeTiming();

        TestHelper::push_rnd_values(test_list, PUSH_AMOUNT);
    }
}

static void BM_std_push_large(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::list<LargeObject> test_list;
        state.ResumeTiming();
        TestHelper::push_rnd_values(test_list, PUSH_LARGE_AMOUNT);
    }
}

static void BM_atl_push_large(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::list<LargeObject, atl::allocator<LargeObject>> test_list;
        state.ResumeTiming();

        TestHelper::push_rnd_values(test_list, PUSH_LARGE_AMOUNT);
    }
}

/*
 * popbacks
 */
static void BM_std_popback_int(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::list<int> test_list;
        TestHelper::push_rnd_values(test_list, PUSH_AMOUNT);
        state.ResumeTiming();

        TestHelper::pop_backs(test_list, PUSH_AMOUNT);
    }
}

static void BM_atl_popback_int(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::list<int, atl::allocator<int>> test_list;
        TestHelper::push_rnd_values(test_list, PUSH_AMOUNT);
        state.ResumeTiming();

        TestHelper::pop_backs(test_list, PUSH_AMOUNT);
    }
}

static void BM_std_popback_string(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::list<std::string> test_list;
        TestHelper::push_rnd_values(test_list, PUSH_AMOUNT);
        state.ResumeTiming();

        TestHelper::pop_backs(test_list, PUSH_AMOUNT);
    }
}

static void BM_atl_popback_string(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::list<std::string, atl::allocator<std::string>> test_list;
        TestHelper::push_rnd_values(test_list, PUSH_AMOUNT);
        state.ResumeTiming();

        TestHelper::pop_backs(test_list, PUSH_AMOUNT);
    }
}

static void BM_std_popback_large(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::list<LargeObject> test_list;
        TestHelper::push_rnd_values(test_list, PUSH_LARGE_AMOUNT);
        state.ResumeTiming();

        TestHelper::pop_backs(test_list, PUSH_LARGE_AMOUNT);
    }
}

static void BM_atl_popback_large(benchmark::State& state)
{
    for (auto _ : state) {
        state.PauseTiming();
        std::list<LargeObject, atl::allocator<LargeObject>> test_list;
        TestHelper::push_rnd_values(test_list, PUSH_LARGE_AMOUNT);
        state.ResumeTiming();

        TestHelper::pop_backs(test_list, PUSH_LARGE_AMOUNT);
    }
}

// Register the functions as a benchmark

//BENCHMARK(BM_std_push_int);
//BENCHMARK(BM_atl_push_int);
//
//BENCHMARK(BM_std_push_string);
//BENCHMARK(BM_atl_push_string);

BENCHMARK(BM_std_push_large);
BENCHMARK(BM_atl_push_large);

BENCHMARK(BM_std_popback_int);
BENCHMARK(BM_atl_popback_int);

BENCHMARK(BM_std_popback_string);
BENCHMARK(BM_atl_popback_string);

BENCHMARK(BM_std_popback_large);
BENCHMARK(BM_atl_popback_large);

BENCHMARK_MAIN();
//int main(int argc, char** argv)
//{
//    TestHelper::push_rnd_values(default_int_list);
//    TestHelper::push_rnd_values(default_string_list);
//
//    ::benchmark::Initialize(&argc, argv);
//    if (::benchmark::ReportUnrecognizedArguments(argc, argv)) return 1;
//    ::benchmark::RunSpecifiedBenchmarks();
//}
