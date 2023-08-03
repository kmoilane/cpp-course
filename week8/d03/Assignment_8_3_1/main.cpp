#include "includes/heap_array.hpp"
#include <iostream>

int main()
{
    oma::Heap_array<int, 10> arr;

    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[9] = 10;
    std::cout << "Arr:\n";
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << ',';
    }
    std::cout << '\n';
    std::cout << "first element: " << *arr.begin() << '\n';
    std::cout << "last element: " << *(arr.end() - 1) << '\n';
    std::cout << "one past last element: " << *arr.end() << '\n';
    std::cout << "Size: " << arr.size() << '\n';
    oma::Heap_array arr1 = arr;

    std::cout << "\nArr1:\n";
    for (size_t i = 0; i < arr1.size(); i++)
    {
        std::cout << arr1[i] << ',';
    }
    std::cout << '\n';
    std::cout << "first element: " << *arr1.begin() << '\n';
    std::cout << "last element: " << *(arr1.end() - 1) << '\n';
    std::cout << "one past last element: " << *arr1.end() << '\n';
    std::cout << "Size: " << arr1.size() << '\n';

    oma::Heap_array arr2 = std::move(arr);
    std::cout << "\nArr2:\n";
    for (size_t i = 0; i < arr2.size(); i++)
    {
        std::cout << arr2[i] << ',';
    }
    std::cout << '\n';
    std::cout << "first element: " << *arr2.begin() << '\n';
    std::cout << "last element: " << *(arr2.end() - 1) << '\n';
    std::cout << "one past last element: " << *arr2.end() << '\n';
    std::cout << "Size: " << arr2.size() << '\n';

    oma::Heap_array<int, 0> arr3;
    std::cout << "\nArr3:\n";
    for (size_t i = 0; i < arr3.size(); i++)
    {
        std::cout << arr3[i] << ',';
    }

    std::cout << "first element address: " << arr3.begin() << '\n';
    std::cout << "one before first element address: " << (arr3.end() - 1) << '\n';
    std::cout << "one before last element address: " << (arr3.begin() - 1) << '\n';
    std::cout << "one past last element address: " << arr3.end() << '\n';
    std::cout << "Size: " << arr3.size() << '\n';

    oma::Heap_array<int, 3> arr4 {5, 3, 6};

    std::cout << "\nArr4:\n";
    for (size_t i = 0; i < arr4.size(); i++)
    {
        std::cout << arr4[i] << ',';
    }
    std::cout << '\n';
    std::cout << "first element address: " << arr4.begin() << '\n';
    std::cout << "last element address: " << (arr4.end() - 1) << '\n';
    std::cout << "one before first element address: " << (arr4.begin() - 1) << '\n';
    std::cout << "one past last element address: " << arr4.end() << '\n';
    std::cout << "Size: " << arr4.size() << '\n';

    std::cout << "\nchanging arr1[0] to 99.\n";
    arr1[0] = 99;
    std::cout << "Swapping arr1 and arr2\n";
    oma::Heap_array<int, 10>::swap(arr1, arr2);
    std::cout << "\nArr1:\n";
    for (auto it = arr1.begin(); it != arr1.end(); it++)
    {
        std::cout << *it << ',';
    }
    std::cout << '\n';

    std::cout << "\nArr2:\n";
    for (auto& element : arr2)
    {
        std::cout << element << ',';
    }
    std::cout << '\n';

    std::cout << std::boolalpha;
    std::cout << "Arr 1 & Arr 2 are not equal: " << (arr1 != arr2) << '\n';
    std::cout << "\nChanging arr2[0] to 1. Now they should be equal..\n";
    arr2[0] = 1;
    std::cout << "Arr 1 & Arr 2 are equal: " << (arr1 == arr2) << '\n';
    std::cout << "Max size for a Heap_array: " << arr.max_size() << '\n';

    return 0;
}
