link_directories(lib)

add_executable(benchmarks benchmarks.cpp)

find_package(Threads)

get_property(tests_include_dir TARGET allocator_tests PROPERTY INTERFACE_INCLUDE_DIRECTORIES)

target_link_libraries(benchmarks benchmark ${CMAKE_THREAD_LIBS_INIT} allocator)

target_include_directories(benchmarks PRIVATE ${tests_include_dir})

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(benchmarks PRIVATE -g3 -O0 -coverage -falign-functions)
    set_target_properties(benchmarks  PROPERTIES LINK_FLAGS " ${LINK_FLAGS} -coverage -falign-functions")
endif()
