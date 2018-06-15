#include "catch.hpp"
#include "fixed_allocator.h"

TEST_CASE("stub")
{
    atl::allocator<int> a;
    REQUIRE(true);
//    CHECK(false);
}
