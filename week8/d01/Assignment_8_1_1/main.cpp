#include <array>
#include <deque>
#include <iostream>
#include <list>
#include <vector>
#include <iterator>
#include <type_traits>
#include <map>

/*
**  Exercise 1
*/
void fun() {}

/*
** Exercise 3
*/
template <typename T>
bool container_is_contiguous(const T& container) {
    if (container.empty())
        return false;

    auto it1 = container.begin();
    auto it2 = std::next(it1);

    while (it2 != container.end())
    {
        if (&(*it2) - &(*it1) != 1)
        {
            return false;
        }
        ++it1;
        ++it2;
    }

    return true;
}

int main()
{
    /*
    **  Exercise 1
    */
    int test_int1;
    int test_int2;
    
    std::cout << "\033[1;34mEXERCISE 1\033[0m\n";
    std::cout << "Address of test_int1: " << &test_int1 << '\n';
    std::cout << "Address of test_int2: " << &test_int2 << '\n';
    std::cout << &test_int2 << " - " << &test_int1 << " = " << &test_int2 - &test_int1 << '\n';
    std::cout << "Address of fun(): " << reinterpret_cast<void*>(&fun) << '\n';

    /*
    **   Exercise 2
    */
    std::vector<char> chars{'h', 'e', 'l', 'l', 'o'};
    
    std::cout << "\033[1;34mEXERCISE 2\033[0m\n";
    std::cout << "Address of chars: " << &chars << '\n';
    for (size_t i = 0; i < chars.size(); i++)
    {
        std::cout << "Address of char["<<i<<"]: " << static_cast<void*>(&chars[i]) << '\n';
    }

    /*
    **  Exercise 3
    */
    std::vector<int> ints{21, 21, 1, 99, 1, 2, 2, 3, 4, 32, 4, 23, 23, 5};
    std::list<int> intsl(10);
    std::array<int, 1000000> arr;
    std::deque<int> deq(10000);
    std::map<int, char> map {{0, 'k'}, {1, 'a'}, {2, 'r'}, {3, 'r'}, {4, 'i'}};
    std::cout << "\033[1;34mEXERCISE 3\033[0m\n";
    std::cout << std::boolalpha;
    std::cout << "chars vector is contiguous: " << container_is_contiguous(chars) << '\n';
    std::cout << "ints vector is contiguous: " << container_is_contiguous(ints) << '\n';
    std::cout << "ints list is contiguous: " << container_is_contiguous(intsl) << '\n';
    std::cout << "int array is contiguous: " << container_is_contiguous(arr) << '\n';
    std::cout << "deque is contiguous: " << container_is_contiguous(deq) << '\n';
    std::cout << "map is contiguous: " << container_is_contiguous(map) << '\n';

    /*
    **  Exercise 4
    */
    std::vector<std::vector<int>> vect_vect(10);
    std::cout << "\033[1;34mEXERCISE 4\033[0m\n";
    std::cout << "vector of vector is contiguous: " << container_is_contiguous(vect_vect) << '\n';
    return 0;
}
