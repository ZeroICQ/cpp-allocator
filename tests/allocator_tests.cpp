#include <list>
#include "catch.hpp"
#include "fixed_allocator.h"

template <class T>
bool is_same(const std::list<T, atl::allocator<T>>& atl_list, const std::list<T>& std_list)
{
    if (atl_list.size() != std_list.size()) {
        return false;
    }

    auto it_a = atl_list.begin();
    auto it_s = std_list.begin();

    for (;it_a != atl_list.end(); it_a++, it_s++) {
        if (*it_a != *it_s) {
            return false;
        }
    }
    return true;
}

template <class T>
void copy(std::list<T, atl::allocator<T>>& atl_list, const std::list<T> std_list)
{
    for (auto it = std_list.begin(); it != std_list.end(); it++) {
        atl_list.push_back(*it);
    }
}

TEST_CASE("test int")
{
    std::list<int> std_list = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::list<int, atl::allocator<int>> alloc_list;
    copy(alloc_list, std_list);
    REQUIRE(is_same(alloc_list, std_list));
}
