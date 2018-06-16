include(CodeCoverage)

SET(GCC_COMPILE_FLAGS "-Wall -pedantic")
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${GCC_COMPILE_FLAGS}")

get_property(allocator_include_dir TARGET allocator PROPERTY INTERFACE_INCLUDE_DIRECTORIES)

include_directories(inc ${allocator_include_dir})

set(TEST_SRC
        catch.cpp
        allocator_tests.cpp
        )

add_executable(allocator_tests ${TEST_SRC})

target_include_directories(allocator_tests INTERFACE .)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    target_compile_options(allocator_tests PRIVATE -g3 -O0 -coverage -fsanitize=address)
    set_target_properties(allocator_tests  PROPERTIES LINK_FLAGS "${LINK_FLAGS} -coverage -fsanitize=address")
endif()

SETUP_TARGET_FOR_COVERAGE(
        NAME coverage                    # New target name
        EXECUTABLE bin/allocator_tests   # Executable in PROJECT_BINARY_DIR
        DEPENDENCIES allocator
)
