#ifndef EX1_HPP
#define EX1_HPP

#include <iostream>

namespace myspace
{
    void hello() { std::cout << "hello from myspace\n"; }
}

class Myclass
{
    public:
        static void hello() { std::cout << "hello from Myclass\n"; }
    private:
};

#endif
