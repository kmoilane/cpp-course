#include <iostream>
#include <exception>
#include <stdexcept>
#include <string>


/*
**  Takes a string and loops through each character, throws an exception if
**  any chacater is not an alphabet
*/
void process_data(std::string& str)
{
    for (auto& c : str)
    {
        if (!isalpha(c))
            throw std::invalid_argument("string includes non-alphabet character");
    }
}

/*
**  Takes an integer and throws and exception if the int is negative
*/
void process_data(int i)
{
    if (i < 0)
        throw std::invalid_argument("Negative integer");
}

int main()
{
    int a { 5 };
    int b { 10 };
    std::string str1 { "Hastalavistababy" };
    std::string str2 { "Hastal4vistababy" };

    process_data(a);
    std::cout << a << " printed\n";
    process_data(str1);
    std::cout << str1 << " printed\n";
    process_data(b);
    std::cout << b << " printed\n";
    process_data(str2);

    return 0;
}
