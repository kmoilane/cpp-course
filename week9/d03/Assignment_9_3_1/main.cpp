#include <iostream>
#include <string>


int main()
{
    std::string str{"testi stringi äöå 😒 𐍈 㗂 越"};

    for(auto it = str.begin(); it != str.end(); ++it)
    {
        std::cout << *it;
    }
    std::cout <<  '\n';
    for(const auto& c : str)
    {
        std::cout << c;
    }
    std::cout <<  '\n';
    for(const auto& c : str)
    {
        std::cout << static_cast<int>(c) << ' ';
    }
    std::cout <<  '\n';

    return 0;
}
