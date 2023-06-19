/*  
**  Write a program that declares a variable inside a function and
**  prints its value. Discuss with the students where the variable
**  can be accessed and explain the concept of local scope.
*/

#include <iostream>

void declare_and_print_variable()
{ //Beginning of the local scope for this function
    int val {}; //val's lifetime begins and it's accessible from this point

    val = 20;
    std::cout << val << std::endl;
} //End of the local scope and end of val's lifetime, no longer accessible

// val can't be accessed here

int main()
{//main functions local scope
    // val can't be accessed here
    // but this function is in global scope so we can call it here
    declare_and_print_variable();

    return 0;
} // <- end of main functions local scope
