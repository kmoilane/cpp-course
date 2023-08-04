#ifndef POSINT_HPP
#define POSINT_HPP
#include <cstdlib>
#include <stdexcept>
#include <limits.h>

class Posint {
    public:
        Posint() = default;

        Posint(int val);

        Posint(const Posint& b) : value(b.value) {};

        Posint operator+(const Posint& rhs);

        Posint operator-(const Posint& rhs);

        void print_value();

        const int& get_value() const noexcept;

    private:
        int value {0};
};

/*
**  Exercise 3: count instances 
*/
class Counter {
    public:
        Counter() { ++instance_count; }
        Counter(const Counter& obj) {}
        ~Counter() { --instance_count; }
        static size_t get_count() {return instance_count;}

    private:
        inline static size_t instance_count;
};

#endif
