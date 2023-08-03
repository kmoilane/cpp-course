#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "includes/doctest.h"
#include "../includes/heap_array.hpp"

TEST_CASE("Heap_array tests")
{
    SUBCASE("Testing default constructor and basic functions")
    {
        oma::Heap_array<int, 10> arr;
        CHECK(arr.size() == 10);
        CHECK(arr.begin() + arr.size() == arr.end());
        CHECK(arr.end() - arr.size() == arr.begin());
    }
    SUBCASE("Testing default constructor with initializer list")
    {
        oma::Heap_array<int, 5> arr{10, 11, 10, 11, 10};
        CHECK(arr[0] == 10);
        CHECK(arr[1] == 11);
        CHECK(arr[2] == 10);
        CHECK(arr[3] == 11);
        CHECK(arr[4] == 10);
    }
    SUBCASE("Testing copy constructor and assignment")
    {
        oma::Heap_array<char, 4> arr{'t', 'e', 's', 't'};
        oma::Heap_array<char, 4> arr1{'f', 'f', 'f', 'f'};
        CHECK(arr[0] == 't');
        CHECK(arr1[0] == 'f');
        arr1 = arr;
        CHECK(arr1[0] == 't');
        CHECK(arr1[1] == 'e');
        CHECK(arr1[2] == 's');
        CHECK(arr1[3] == 't');
        arr = {'l', 'm', 'a', 'o'};
        oma::Heap_array<char, 4> arr2(arr);
        CHECK(arr2[0] == 'l');
        CHECK(arr2[1] == 'm');
        CHECK(arr2[2] == 'a');
        CHECK(arr2[3] == 'o');
    }
    SUBCASE("Testing move constructor and assignment")
    {
        oma::Heap_array<char, 4> arr{'t', 'e', 's', 't'};
        oma::Heap_array<char, 4> arr1(std::move(arr));
        CHECK(arr1[0] == 't');
        CHECK(arr1[1] == 'e');
        CHECK(arr1[2] == 's');
        CHECK(arr1[3] == 't');
        oma::Heap_array<char, 4> arr2{'l', 'l', 'k', 'k'};
        arr2 = std::move(arr1);
        CHECK(arr2[0] == 't');
        CHECK(arr2[1] == 'e');
        CHECK(arr2[2] == 's');
        CHECK(arr2[3] == 't');
    }
    SUBCASE("Testing == and != and swap")
    {
        oma::Heap_array<int, 2> arr{99, 98};
        oma::Heap_array<int, 2> arr1(arr);
        CHECK((arr == arr1) == true);
        CHECK((arr != arr1) == false);
        arr[1] = 99;
        CHECK(arr[1] == 99);
        CHECK(arr1[1] != 99);
        arr.swap(arr1);
        CHECK(arr[1] != 99);
        CHECK(arr1[1] == 99);
    }
}
