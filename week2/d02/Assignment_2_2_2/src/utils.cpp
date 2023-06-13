#include "../includes/utils.h"
#include <iostream>
#include <string>

void print_help()
{
    std::cout << "\nHow to use Calculator:\n";
    std::cout << "Usage: ./Calculator --operation value value\n";
    std::cout << "Operations:\n";
    std::cout << "  --sum a b\t\t[Calculatess the sum of a and b]\n";
    std::cout << "  --division a b\t[Calculatess the division of a and b]\n";
    std::cout << "  --multiply a b\t[Calculatess the multiplication of a and b]\n";
    std::cout << "  --substract a b\t[Calculatess the substraction of a and b]\n";
    std::cout << "  --encrypt string key\t[Encrypts the string with key value. key is integer]\n";
    std::cout << "  --decrypt string key\t[Decrypts the string of two integers]\n";
}

void print_sum(int a, int b)
{
    std::cout << a << '+' << b << " = " << a+b << '\n';
}

void print_substraction(int a, int b)
{
    std::cout << a << '-' << b << " = " << a-b << '\n';
}

void print_multiplication(int a, int b)
{
    std::cout << a << '*' << b << " = " << a*b << '\n';
}

void print_division(int a, int b)
{
    if (b == 0)
        std::cout << "\nYou dumb dumb\n";
    else
        std::cout << a << '/' << b << " = " << a / static_cast<double>(b) << '\n';
}

void encrypt(std::string str, int key)
{
    std::cout << "Encrypting " << str << " with " << key << '\n';
    for (char& c : str)
    {
        if (c >= 'A' && c <= 'Z')
            c = ((c - 'A' + key) % 26 + 'A');
        else if (c >= 'a' && c <= 'z')
            c = ((c - 'a' + key) % 26 + 'a');
    }
    std::cout << str << '\n';
}

void decrypt(std::string str, int key)
{
    std::cout << "Decrypting " << str << " with " << key << '\n';
    for (char& c : str)
    {
        if (c >= 'A' && c <= 'Z')
            c = ((c - 'A' - key + 26) % 26 + 'A');
        else if (c >= 'a' && c <= 'z')
            c = ((c - 'a' - key + 26) % 26 + 'a');
    }
    std::cout << str << '\n';
}
