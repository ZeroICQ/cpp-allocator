#pragma once

//#include <vector>
#include <cstring>
#include <array>

namespace atl {

template <class T>
class allocator {
public:
    using value_type = T;

    allocator() noexcept;
    allocator(const allocator&) noexcept;

    ~allocator();
    T* allocate(size_t n);
    void deallocate(T* pointer, size_t n);

private:
    static constexpr size_t MAX_MEMORY = 536870912;//in bytes. now 500MB
    size_t memory_used_;
    size_t max_size_;
    T* memory_block_;

    T** free_;
    size_t free_size_;
    size_t curr_free_ = 0;
};

template<class T>
allocator<T>::allocator() noexcept
{
    max_size_ = MAX_MEMORY / sizeof(T);
    memory_used_ = max_size_ * sizeof(T);
    //ASK: this vs malloc
    memory_block_ = reinterpret_cast<T*>(new char[memory_used_]);

    free_ = new T*[max_size_];

    for (size_t i = 0; i < max_size_; i++) {
        free_[i] = memory_block_ + i;
    }

    free_size_ = max_size_;
}

template<class T>
allocator<T>::allocator(const allocator& other) noexcept
{
    delete[] memory_block_;
    delete[] free_;

    max_size_    = other.max_size_;
    memory_used_ = other.memory_used_;
    free_size_   = other.free_size_;

    memory_block_ = reinterpret_cast<T*>(new char[memory_used_]);
    free_ = new T*[max_size_];

    std::memcpy(memory_block_, other.memory_block_, memory_used_);
    std::memcpy(free_, other.free_, free_size_);
}

template<class T>
allocator<T>::~allocator()
{
    delete[] memory_block_;
    delete[] free_;
}

template<class T>
T* allocator<T>::allocate(size_t n)
{
    if (n > 1 || curr_free_  == max_size_) {
        throw std::bad_alloc();
    }

    return free_[curr_free_++];
}

template<class T>
void allocator<T>::deallocate(T* pointer, size_t n)
{
    assert(0 <= n && n <= 1);
    if (n == 0) {
        return;
    }
    free_[--curr_free_] = pointer;
}

}//namespace atl
