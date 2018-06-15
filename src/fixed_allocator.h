#pragma once

namespace atl {

template <class T>
class allocator {
public:
    using value_type = T;

//    using propagate_on_container_move_assignment = std::true_type;
//    using is_always_equal = std::true_type;

    allocator() noexcept;
    allocator(const allocator&) noexcept;
    template <class U> allocator(const allocator<U>&) noexcept;

    ~allocator();
    T* allocate(size_t n);
    void deallocate(T* p, size_t n);
};

}//namespace atl