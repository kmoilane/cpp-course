#include <iostream>
#include <type_traits>
#include <string>
#include <algorithm>
#include <vector>
#include <list>

/*
**  Exercise 1
*/
template <typename T>
void print1(const T& last)
{
    std::cout << last << '\n';
}

template <typename T, typename... Ts>
void print1(const T& first, const Ts&... rest)
{
    std::cout << first << ", ";
    print1(rest...);
}

template <typename T, typename... Ts>
void print2(const T& first, const Ts&... rest)
{
    std::cout << first;
    if constexpr (sizeof...(rest) > 0)
    {
        std::cout << ", ";
        print2(rest...);
    }
    else
        std::cout << '\n';
}

int summa_summarum()
{
    return 0;
}

/*
**  Exercise 2
*/
template <typename T, typename... Ts>
int summa_summarum(const T& current, const Ts&... rest)
{
    static_assert((
        !std::is_same_v<std::decay_t<T>, char> || std::is_arithmetic_v<std::decay_t<T>>), "Not arithmetic type");

    if constexpr(sizeof...(rest) > 0)
    {
        return current + summa_summarum(rest...);
    }
    else
        return current;
}

/*
**  Exercise 3
*/
template <typename T, typename U>
constexpr bool same_types(const T&, const U&) noexcept
{
    return false;
}

template <typename T>
constexpr bool same_types(const T&, const T&) noexcept
{
    return true;
}

template <typename T, typename U, typename... Ts>
constexpr bool same_types(const T& first, const U& second, Ts... rest)
{
    if (same_types(first, second))
        return same_types(first, rest...); 
    return false;
}


/*
**  Exercise 4
*/
template <typename... Ts>
auto product_multiplied(Ts ... t)
{
    return ( t * ... * sizeof...(t) );
}

/*
**  Exercise 5
**  Takes arbitrary number of containers, concats them together and returns it
**  in the contianer that was first passed in.
*/
template <typename T, typename... Conts>
auto concat_containers(const T& first_cont, const Conts&... conts)
{
    std::decay_t<T> result;
    result.insert(result.end(), first_cont.begin(), first_cont.end());
    (result.insert(result.end(), conts.begin(), conts.end()), ...);
    return result;
}

int main()
{
    print1<int>(10, 4, 7, 32, 5);
    print2<int>(-10, -4, -7, -32, -5);
    std::cout << std::boolalpha;
    std::string test {"testi"};
    std::cout << summa_summarum(5, 10, 20, 1, 5, 5.66) << '\n';
    std::cout << same_types(5, 10, 20, 54) << '\n';
    std::cout << product_multiplied(2, 2) << '\n';
    std::vector<int> vec1{1, 2};
    std::list<int> list1{5, 8};
    std::vector<char> vec2{' ', 'e', 'i', ' ', 'k', 'a', 'a', 'd', 'u'};

    auto result = concat_containers(vec1, list1, test);
    auto result2 = concat_containers(test, vec2);

    for (const auto& val : result)
    {
        std::cout << val << " ";
    }
    std::cout << '\n';
    for (const auto& val : result2)
    {
        std::cout << val;
    }
    std::cout << '\n';
    return 0;
}
