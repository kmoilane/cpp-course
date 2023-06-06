#include <iostream>
#include <string>

/*
**  This function takes a string as an argument, and returns reversed version
**  of the string.
*/
std::string reverse_string(std::string str)
{
    std::string rev_str {};
    for (int i = str.size(); i >= 0; --i)
        rev_str += str[i];

    return rev_str;
}

int main()
{
    std::cout << "Enter a string:\n";
    std::string str;
    std::getline(std::cin >> std::ws, str);
    std::cout << "You entered:\n" << str << "\nWhich in reverse is: \n"
        << reverse_string(str) << '\n';

    return 0;
}
