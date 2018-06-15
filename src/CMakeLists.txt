add_library(allocator INTERFACE)

TARGET_INCLUDE_DIRECTORIES(allocator INTERFACE .)

#if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#    target_compile_options(vector PRIVATE -g3 -O0 -coverage)
#    set_target_properties(vector  PROPERTIES LINK_FLAGS "${LINK_FLAGS} -coverage")
#endif()
