/*
**  Create a program that declares a variable inside a function and modifies
**  its value inside an if statement. Print the value of the variable
**  before and after the if statement. Discuss with the students the concept
**  of scope and how it affects variable modifications.
*/

#include <iostream>

int main()
{
    int val {}; // val's lifetime begins
    val = 99;
    std::cout << val << std::endl;  // This is fine, since val is in scope

    if(true)
        val = -99;  // Fine as well since val also reaches this scope

    std::cout << val << std::endl;  // Val is now modified and and still ok
    
    return 0; // val's lifetime ends after this
}
