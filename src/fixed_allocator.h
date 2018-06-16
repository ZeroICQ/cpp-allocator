#pragma once

#include <vector>
#include <assert.h>

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
    void deallocate(T* pointer, size_t n);

private:
    static constexpr size_t MAX_MEMORY = 104857600;//in bytes. now 100mb
    size_t memory_used_;
    size_t max_size_;
    T* memory_block_;

    std::vector<T*> free_;
};

template<class T>
allocator<T>::allocator() noexcept
{
    max_size_ = MAX_MEMORY / sizeof(T);
    memory_used_ = max_size_ * sizeof(T);
    //ASK: this vs malloc
    memory_block_ = reinterpret_cast<T*>(new char[memory_used_]);

    free_.reserve(max_size_);

    for (size_t i = 0; i < max_size_; i++) {
        free_.push_back(memory_block_ + i);
    }
}

template<class T>
allocator<T>::~allocator()
{
    delete[] memory_block_;
}

template<class T>
T* allocator<T>::allocate(size_t n)
{
    if (n > 1 || free_.empty()) {
        throw std::bad_alloc();
    }

    T* pointer_to_allocated_memory = free_.back();
    free_.pop_back();
    return  pointer_to_allocated_memory;
}

template<class T>
void allocator<T>::deallocate(T* pointer, size_t n)
{
    assert(0 <= n && n <= 1);
    if (n == 0) {
        return;
    }
    free_.push_back(pointer);
}

}//namespace atl
