#include <list>
#include "catch.hpp"
#include "fixed_allocator.h"
#include "test_helper.h"

using atl::TestHelper;

TEST_CASE("create list<int>")
{
    std::list<int> std_list;
    std::list<int, atl::allocator<int>> atl_list;

    TestHelper::push_rnd_values(std_list);
    TestHelper::push_rnd_values(atl_list);
    REQUIRE(TestHelper::is_same(atl_list, std_list));
}

TEST_CASE("create list<string>")
{
    std::list<std::string> std_list;
    std::list<std::string, atl::allocator<std::string>> atl_list;

    TestHelper::push_rnd_values(std_list);
    TestHelper::push_rnd_values(atl_list);
    REQUIRE(TestHelper::is_same(atl_list, std_list));
}

TEST_CASE("popfronts")
{
    std::list<std::string> std_list;
    std::list<std::string, atl::allocator<std::string>> atl_list;

    TestHelper::push_rnd_values(std_list);
    TestHelper::push_rnd_values(atl_list);

    TestHelper::pop_backs(std_list, 900);
    TestHelper::pop_backs(atl_list, 900);
    REQUIRE(TestHelper::is_same(atl_list, std_list));
}
