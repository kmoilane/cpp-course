#include <iostream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <vector>

/*
**  End condition for the get_arg_types when there's no arguments left
*/
void get_arg_types(const std::string& str) { return ; }

/*
**  Recursive function taht fills std::string reference with detected specifiers
*/
template <typename T, typename... Ts>
void get_arg_types(std::string& str, const T& val, const Ts&... rest)
{
    if (std::is_same_v<std::decay_t<T>, int>)
        str.push_back('i');
    else if (std::is_same_v<std::decay_t<T>, const char*>)
        str.push_back('s');
    else if (std::is_same_v<std::decay_t<T>, char>)
        str.push_back('c');
    else
        throw std::invalid_argument("Invalid argument type");
    
    get_arg_types(str, rest...);
}

template <typename... Ts>
void safe_printf(const std::string& fmt, Ts... args)
{
    std::string specifiers;
    std::string arg_types;
    get_arg_types(arg_types, args...);
    for (std::size_t i = 0; i < fmt.size(); ++i)
    {
        if ((fmt[i] == '%' && i + 1 < fmt.size()))
        {
            specifiers.push_back(fmt[i+1]);
        }
    }
    
    if (specifiers.size() != arg_types.size())
        throw std::runtime_error("Error: Different amount of args and specifiers");
    
    for (std::size_t i = 0; i < specifiers.size(); i++)
    {
        if (specifiers[i] != arg_types[i])
            throw std::runtime_error("Error: Invalid argument type");
    }

    std::printf(fmt.c_str(), args...);
}

int main()
{
    std::printf("testing %i + %c\n%s%s\n", 10, 'K', "Hello", " there");
    try {
        safe_printf("testing %i + %c\n%s%s\n", 10, 'K', "Hello", " there");
    }
    catch (std::exception& e){
        std::cout << e.what() << '\n';
    }
    return 0;
}
