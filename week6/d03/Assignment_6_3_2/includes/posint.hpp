#ifndef POSINT_HPP
#define POSINT_HPP
#include <iostream>
#include <stdexcept>
#include <limits.h>

class Posint {
    public:
        Posint() = default;
        Posint(int val);
        Posint(const Posint& b) : value(b.value) {};
        
        Posint operator+(const Posint& rhs);
        Posint operator-(const Posint& rhs);

        void print_value() { std::cout << value; }
        const int& get_value() const noexcept;
        friend Posint add(const Posint& num1, const Posint& num2);
        friend Posint substract(const Posint& num1, const Posint& num2);

    private:
        int value {0};
};


#endif
