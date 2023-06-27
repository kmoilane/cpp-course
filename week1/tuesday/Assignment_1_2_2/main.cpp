#include <iostream>
#include <string>

bool has_punct(std::string pass)
{
    for (size_t i = 0; i < pass.size(); ++i)
    {
        if (std::ispunct(static_cast<unsigned char>(pass[i])))
            return true;
    }
    return false;
}

bool has_digit(std::string pass)
{
    for (size_t i = 0; i < pass.size(); ++i)
    {
        if (std::isdigit(static_cast<unsigned char>(pass[i])))
            return true;
    }
    return false;
}

bool has_lowercase(std::string pass)
{
    for (size_t i = 0; i < pass.size(); ++i)
    {
        if (std::islower(static_cast<unsigned char>(pass[i])))
            return true;
    }
    return false;
}

bool has_uppercase(std::string pass)
{
    for (size_t i = 0; i < pass.size(); ++i)
    {
        if (std::isupper(static_cast<unsigned char>(pass[i])))
            return true;
    }
    return false;
}

bool verify_password(std::string pass)
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
