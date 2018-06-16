#pragma once


#include <list>
#include <random>
#include "fixed_allocator.h"

namespace atl{

class TestHelper
{
public:
    TestHelper() = delete;
    template <class T>
    static bool is_same(const std::list<T, atl::allocator<T>>& atl_list, const std::list<T>& std_list);
    template <class T>
    static void copy(std::list<T, atl::allocator<T>>& atl_list, const std::list<T>& std_list);
    //fill
    template <class Alloc>
    static void push_rnd_values(std::list<int, Alloc> &list, size_t n = 1000);
    template <class Alloc>
    static void push_rnd_values(std::list<std::string, Alloc>& list, size_t n = 1000,
                                size_t min_length = 3, size_t max_length = 100);
    //operations
    template <class Alloc>
    static void pop_backs(std::list<std::string, Alloc>& list, size_t n = 1);

private:
    static const int SEED = 123;
};

template<class T>
bool TestHelper::is_same(const std::list<T, atl::allocator<T>>& atl_list, const std::list<T>& std_list)
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

template<class T>
void TestHelper::copy(std::list<T, atl::allocator<T>>& atl_list, const std::list<T>& std_list)
{
    for (auto it = std_list.begin(); it != std_list.end(); it++) {
        atl_list.push_back(*it);
    }
}


template <class Alloc>
void TestHelper::push_rnd_values(std::list<int, Alloc>& list, size_t n)
{
    std::srand(SEED);

    for (size_t i = 0; i < n; i++) {
        int val = std::rand();
        list.push_back(val);
    }
}

template <class Alloc>
void TestHelper::push_rnd_values(std::list<std::string, Alloc>& list, size_t n, size_t min_length, size_t max_length)
{
    std::srand(SEED);
    static const char alphanum[] = "0123456789"
                                   "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                                   "abcdefghijklmnopqrstuvwxyz";
    for (size_t i = 0; i < n; i++) {
        size_t string_length = (rand() % (max_length - min_length)) + min_length;

        std::string rnd_string;
        rnd_string.reserve(string_length);

        for (size_t j = 0; j < string_length; j++) {
            auto rnd_char = alphanum[rand() % (sizeof(alphanum) - 1)];
            rnd_string.push_back(rnd_char);
        }
        list.push_back(rnd_string);
    }
}

template<class Alloc>
void TestHelper::pop_backs(std::list<std::string, Alloc>& list, size_t n)
{
    n = std::min(n, list.size());
    for (size_t i = 0; i < n; i++) {
        list.pop_back();
    }
}

}//namespace atl
