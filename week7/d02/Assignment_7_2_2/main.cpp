#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>


template <typename... Ts>
bool validate_specifiers(std::vector<char> specifiers, Ts... args)
{
    if (specifiers.size() != sizeof...(args))
        return false;
    for (char c : specifiers)
    {
        if (c != 'c' || c != 'd' || c != 'e' || c != 'f' || c != 'i' || c != 'o'
            || c != 's' || c != 'u' || c != 'x')
        {
            return false;
        }
    }
    return true;
}


template <typename T, typename... Ts>
void safe_printf(const std::string& fmt, char c, const T& first, Ts... rest)
{
    switch (c)
    {
        case 'i':
        {
            if (std::is_same_v<std::decay_t<T>, int>)
            {
                std::cout << first;
                safe_printf(fmt.substr(2), fmt[1], rest...);
                break ;
            }
            else
                throw std::runtime_error("Invalid argument");
        }
        case 's':
        {
            if (std::is_same_v<std::decay_t<T>, const char*>)
            {
                std::cout << first;
                safe_printf(fmt.substr(2), fmt[1], rest...);
                break ;
            }
            else
                throw std::runtime_error("Invalid argument");
        }
        case 'c':
        {
            if (std::is_same_v<std::decay_t<T>, char>)
            {
                std::cout << first;
                safe_printf(fmt.substr(2), fmt[1], rest...);
                break ;
            }
            else
                throw std::runtime_error("Invalid argument");
        }
        default:
            throw std::runtime_error("Invalid specifier");
    }
}

template <typename... Ts>
void safe_printf(const std::string& fmt, Ts... args)
{
    for (std::size_t i = 0; i < fmt.size(); ++i)
    {
        if ((fmt[i] == '%' && i + 1 < fmt.size()) &&
            (fmt[i+1] == 'i' || fmt[i+1] == 's' || fmt[i+1] == 'c'))
        {
            safe_printf(fmt.substr(0, i), fmt[i+1], args...);
            return ;
        }
        else
            std::cout << fmt[i];
    }
}

int main()
{
    safe_printf("testing %i + %c", 10, 'K');
    return 0;
}
