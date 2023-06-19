/*
**  Create a program with two functions: main() and calculate().
**  Inside the calculate() function, declare a variable and assign a
**  value to it. Print the value of the variable in both functions.
**  Discuss with the students the difference between local and global scope.
*/

#include <iostream>

void calculate()
{
    int val {};

    val = 23;
    std::cout << val << std::endl;
}

int main()
{
    calculate(); // This works fine
    
    //std::cout << val << std::endl; // This causes compile error, since val is
                                    // out of scope and is not accessible here
    return 0;
}

/*
**  Global scope grants access to variables inside the whole file, local only
**  in the block it lives in
*/
