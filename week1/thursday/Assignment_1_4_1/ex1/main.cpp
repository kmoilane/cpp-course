/*
**  Write a C++ program that capitalizes the first letter of the string
**  and sets the rest as lowercase letters. Use the following main function
**  and write a function that passes the assertions.
*/

#include <iostream>
#include <cassert>
#include <string>
#include <cctype>

std::string capitalize_string(std::string str)
{
    std::string return_str {};
    for (size_t i = 0; i < str.size(); ++i)
    {
        if ((i == 0 && isalpha(str[i])) ||
        (i > 0 && isspace(str[i - 1]) && isalpha(str[i])))
            return_str += static_cast<char>(toupper(str[i]));
        else if (isalpha(str[i]))
            return_str += static_cast<char>(tolower(str[i]));
        else
            return_str += str[i];
    }

    return return_str;
}

int main() {
    assert("The String Challenge" ==
    capitalize_string("the string challenge"));
    std::cout << "Test 1 passed" << std::endl;
    assert("This Is An Example, Should Work!" ==
    capitalize_string("THIS IS an ExamplE, should wORk!"));
    std::cout << "Test 2 passed" << std::endl;
}
