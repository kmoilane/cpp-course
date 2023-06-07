/*
**  Write a program that dynamically allocates memory for an array inside a
**  function. Pass the array to another function and print its values.
**  Remember to deallocate the memory at the end. Discuss with the students
**  the concept of dynamic memory allocation and how it affects the
**  lifetime of variables.
*/

#include <iostream>

void dump_arr(int* arr)
{
    int i { 0 };
    while (arr[i])
    {
        std::cout << arr[i] << '\n';
        ++i;
    }
}

int main()
{
    int *arr { new int[5]{ 1, 2, 3, 4, 5 } };

    dump_arr(arr);

    delete [] arr;

    return 0;
}

/*
https://stackoverflow.com/questions/2672085/what-is-the-difference-between-static-and-dynamic-arrays-in-c
"Static arrays are created on the stack, and have automatic storage duration:
you don't need to manually manage memory, but they get destroyed when the
function they're in ends. They necessarily have a fixed size at compile time:"

// AND

"Arrays created with operator new[] have dynamic storage duration and are stored
on the heap (technically the "free store").
They can have any size during runtime, but you need to allocate and free
them yourself since they're not part of the stack frame"
*/
