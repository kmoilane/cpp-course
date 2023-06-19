/*
**  Create a program that uses static variables inside a function and
**  demonstrates their lifetime across multiple function calls. Discuss with
**  the students the lifetime and scope of static variables.
*/

#include <iostream>

void increment_and_print_static()
{
    static int year { 2023 };
    std::cout << year << '\n';
    ++year;
}
int main()
{
    increment_and_print_static();
    increment_and_print_static();
    increment_and_print_static();

    return 0;
}
/*
**  Static local variables will have static duration instead of an automatic.
**  Variable is now created at the start of the program,
**  and destroyed at the end of the program.
*/
