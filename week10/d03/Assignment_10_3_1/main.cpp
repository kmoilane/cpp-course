#include <iostream>
#include <vector>
#include <memory>
#include <array>

constexpr size_t block_size = 100;

template <typename T>
class Mallocator
{
public:
    using value_type = T;
    using pointer = T*;

    Mallocator() = default;

    template <typename U>
    Mallocator(const Mallocator<U>&) noexcept {}

    pointer allocate(size_t n)
    {
        return new(block) T[n];
    }

    void deallocate(T* p, size_t n)
    {
        p->~T();
    }
private:
    static inline uint8_t block[block_size];
};

template <typename T, typename U>
bool operator==(const Mallocator<T>&, const Mallocator<U>&) {return true;}
template <typename T, typename U>
bool operator!=(const Mallocator<T>&, const Mallocator<U>&) {return false;}

int main() {
    using MyVector = std::vector<int, Mallocator<int>>;

    MyVector vec{1, 2, 3, 4, 5};
    std::cout << "Vector size: " << vec.size() << '\n';

    for (auto& elem : vec)
    {
        std::cout << elem << ", ";
    }

    std::cout << std::endl;

    return 0;
}
