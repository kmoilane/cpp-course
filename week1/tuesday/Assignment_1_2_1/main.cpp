#include <iostream>
#include <string>

/*
**  This function takes a string as an argument, and returns reversed version
**  of the string.
*/
std::string reverseString(std::string str)
{
    std::string revStr {};
    for (int i = str.size(); i >= 0; --i)
    {
        revStr += str[i];
    }

    return revStr;
}

int main()
{
    std::cout << "Enter a string:\n";
    std::string str;
    std::getline(std::cin >> std::ws, str);
    std::cout << "You entered:\n" << str << "\nWhich in reverse is: \n"
        << reverseString(str) << '\n';

        return 0;
}
