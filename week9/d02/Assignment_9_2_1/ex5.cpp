#include <iostream>
#include <string>
#include <cstdint>
#include <string.h>

template <typename T>
void print_bits(const T& value)
{
    using decay_type = std::decay_t<T>;

    std::cout << "0b";
    for (int i = sizeof(decay_type) * 8 - 1; i >= 0; --i)
    {
        std::cout << ((value & (1ULL << i)) ? 1 : 0);
        if (i % 8 == 0)
            std::cout << ' ';
    }

    std::cout << '\n';
}

int main(int argc, char* argv[])
{
    if (argc != 2)
    {
        std::cout << "This program takes a string as a parameter!\n";
        return 1;
    }
    if (strlen(argv[1]) > 64)
    {
        std::cout << "\033[1;31mWARNING! \033[0m\n";
        std::cout << "String is over 64 characters, so it will not be masked completely!\n";
    }
    uint64_t mask {0};

    for (int i = 0; argv[1][i] && i < 64; i++)
    {
        if (argv[1][i] == ',')
            mask |= (1ULL << i);
    }
    print_bits(mask);

    return 0;
}
