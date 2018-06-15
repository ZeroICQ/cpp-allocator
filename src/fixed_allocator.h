#pragma once

#include <vector>

namespace atl {

template <class T>
class allocator {
public:
    using value_type = T;

    allocator() noexcept;
    allocator(const allocator&) noexcept;
    template <class U>
    allocator(const allocator<U>&) noexcept;

    ~allocator();
    T* allocate(size_t n);
    void deallocate(T* p, size_t n);

private:
    static constexpr size_t MAX_MEMORY = 2147483648;//in bytes. now 2gb
    std::vector<T*> free_;
    std::vector<T*> allocated_;
    T* memory_block_;

};

template<class T>
allocator<T>::allocator() noexcept
{
    auto max_size = MAX_MEMORY / sizeof(T);
    memory_block_ = new T[]
}

template<class T>
allocator<T>::~allocator()
{
    delete[] memory_block_;
}

}//namespace atl