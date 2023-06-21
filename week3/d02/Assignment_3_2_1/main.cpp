#include <iostream>
#include <vector>
#include <algorithm>

/*
**  Swaps the strings
*/
void string_swap(std::string& s1, std::string& s2)
{
    std::string temp {};
    temp = s1;
    s1 = s2;
    s2 = temp;
}

/*
**  Recursively calls itself to create every possible permutation of given
**  strings vector. Swaps the strings and after recursion comes back, swaps the
**  strings back so that it can check other options. When one permutation is
**  completed: start == end, it prints every string from that permutation.
**  string[0] is starting point, so we assign start to 1 and never swap 0th
**  place.
*/
void generate_permutations(std::vector<std::string>& strings, int start, int end)
{
    if (start == end)
    {
        std::cout << "Route: ";
        for (const std::string& str : strings)
        {
            std::cout << str << " ";
        }
        std::cout << '\n';
    }
    else
    {
        for (int i = start; i <= end; ++i)
        {
            string_swap(strings[start], strings[i]);
            generate_permutations(strings, start + 1, end);
            string_swap(strings[start], strings[i]);
        }
    }
}

/*
**  Creates a copy of the strings vector and calls generate_permutations
*/
void print_routes(const std::vector<std::string>& strings)
{
    std::vector<std::string> permuted_strings = strings;
    generate_permutations(permuted_strings, 1, permuted_strings.size() - 1);
}

int main()
{
    std::vector<std::string> ports { "Panama", "New York", "Amsterdam",
        "Helsinki", "Durban" };
    print_routes(ports);
    return 0;
}
