#include <iostream>
#include <string>

bool has_punct(const std::string& pass)
{
    for (size_t i = 0; i < pass.size(); ++i)
    {
        if (std::ispunct(pass[i]))
            return true;
    }
    return false;
}

bool has_digit(const std::string& pass)
{
    for (size_t i = 0; i < pass.size(); ++i)
    {
        if (std::isdigit(pass[i]))
            return true;
    }
    return false;
}

bool has_lowercase(const std::string& pass)
{
    for (size_t i = 0; i < pass.size(); ++i)
    {
        if (std::islower(pass[i]))
            return true;
    }
    return false;
}

bool has_uppercase(const std::string& pass)
{
    for (size_t i = 0; i < pass.size(); ++i)
    {
        if (std::isupper(pass[i]))
            return true;
    }
    return false;
}

bool verify_password(const std::string& pass)
{
    if (pass.size() < 8)
    {
        std::cout << "Password too short!\n";
        return false;
    }
    if (!has_digit(pass))
    {
        std::cout << "No digits.\n";
        return false;
    }
    if (!has_punct(pass))
    {
        std::cout << "No special character!\n";
        return false;
    }
    if (!has_lowercase(pass))
    {
        std::cout << "No lowercase letter!\n";
        return false;
    }
    if (!has_uppercase(pass))
    {
        std::cout << "No uppercase letter!\n";
        return false;
    }
    return true;
}

int main()
{
    std::cout << "Enter password: ";
    std::string pass {};
    std::getline(std::cin >> std::ws, pass);
    if (verify_password(pass))
        std::cout << "Password is strong!\n";
    return 0;
}
