/*
**  Write a program that declares a variable inside a block and prints
**  its value inside and outside the block. Discuss with the students the
**  scope of variables declared inside blocks.
*/

#include <iostream>


int main()
{
    {
        int i {4};
        std::cout << i << std::endl;
    }
    //i out of scope
    // std::cout << i << std::endl; // this would cause compiler error

    return 0;
}
