#include "inc/benchmark.h"

static void BM_Test(benchmark::State& state) {
    for (auto _ : state)
        std::string empty_string;
}


// Register the functions as a benchmark

BENCHMARK(BM_Test);

BENCHMARK_MAIN();
//int main(int argc, char** argv)
//{
//    large_default_vector = atl::get_default_vector(atl::SIZE_LARGE);
//    medium_default_vector = atl::get_default_vector(atl::SIZE_MEDIUM);
//    small_default_vector = atl::get_default_vector(atl::SIZE_SMALL);
//    super_large_default_vector = atl::get_default_vector(atl::SIZE_SUPER_LARGE);
//
//    ::benchmark::Initialize(&argc, argv);
//    if (::benchmark::ReportUnrecognizedArguments(argc, argv)) return 1;
//    ::benchmark::RunSpecifiedBenchmarks();
//}
