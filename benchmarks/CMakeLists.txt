link_directories(lib)

add_executable(benchmarks benchmarks.cpp)

find_package(Threads)

target_link_libraries(benchmarks benchmark ${CMAKE_THREAD_LIBS_INIT} allocator)


if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(benchmarks PRIVATE -g3 -O0 -coverage)
    set_target_properties(benchmarks  PROPERTIES LINK_FLAGS " ${LINK_FLAGS} -coverage")
endif()
