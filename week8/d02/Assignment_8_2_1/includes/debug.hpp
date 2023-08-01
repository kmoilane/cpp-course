#ifndef DEBUG_HPP
#define DEBUG_HPP

#include <iostream>

template <bool console>
class Debug
{
    public:
        Debug() 
        {
            constructor_count++;
            if (console)
                std::cout << "Default constructor called!\n";
        }
        Debug(const Debug&)
        {
            copy_count++;
            if (console)
                std::cout << "Copy constructor called!\n";
        }
        Debug(const Debug&&)
        {
            move_count++;
            if (console)
                std::cout << "Move constructor called!\n";
        }
        ~Debug()
        {
            destructor_count++;
            if (console)
                std::cout << "Destructor called!\n";
        }
        inline static int constructor_count {0};
        inline static int destructor_count {0};
        inline static int move_count {0};
        inline static int copy_count {0};
    private:
};

#endif
