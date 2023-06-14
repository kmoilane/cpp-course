#include "../includes/utils.h"
#include <cassert>
#include <iostream>
#include <string>

/*
**  Prints the help messages if input is not correct
*/
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

void print_sum(double a, double b)
{
    std::cout << a << " + " << b << " = " << a+b << '\n';
}

void print_substraction(double a, double b)
{
    std::cout << a << " - " << b << " = " << a-b << '\n';
}

void print_multiplication(double a, double b)
{
    std::cout << a << " * " << b << " = " << a*b << '\n';
}

void print_division(double a, double b)
{
    assert(b != 0 && "Division by 0 is not defined!\n");
    std::cout << a << " / " << b << " = " << a / b << '\n';
}


/*
**  Encrypts str with Caesars Cipher. Key is the amount of rotations
*/
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

/*
**  Decrypts str with Caesars Cipher. Key is the amount of rotations
*/
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
