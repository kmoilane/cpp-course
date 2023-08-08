#include <iostream>
#include <cstdint>
#include <type_traits>

template <typename T>
void print_bits(const T& value)
{
    using decay_type = std::decay_t<T>;

    std::cout << "0b";
    for (int i = sizeof(decay_type) * 8 - 1; i >= 0; --i)
    {
        std::cout << ((value & (1 << i)) ? 1 : 0);
    }

    std::cout << '\n';
}

template <typename T>
bool nth_is_set(const T& value, int nth)
{
    return (value & (1 << nth));
}

template <typename T>
T byte_swap(const T& value)
{
    static_assert(std::is_integral_v<std::decay_t<T>>, "Type needs to be intergal!\n");
    using decay_type = std::decay_t<T>;
    size_t size = sizeof(decay_type);
    if (size == 1)
        return value;
    T result {0};
    for (size_t i = 0; i < size; i++)
    {
        result = result | ((value >> (i * 8)& 0xFF) << (size - 1 - i) * 8);
    }

    return result;
}

int main()
{
    uint8_t val = 42;
    print_bits(val);
    std::cout << std::boolalpha;
    for (int i = 0; i < 8; i++)
    {
        std::cout << i << " bit is set: " << nth_is_set(val, i) << '\n';
    }

    uint16_t a = 0xabcd;
    print_bits(a);
    uint16_t b = byte_swap(a);
    print_bits(b);
    return 0;
}
