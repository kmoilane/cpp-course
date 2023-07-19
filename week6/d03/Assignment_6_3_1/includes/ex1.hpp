#ifndef EX1_HPP
#define EX1_HPP

#include <iostream>

class Static_class {
    public:
        static Static_class create();
        void hello() {std::cout << "Hello\n"; };

    private:
        Static_class() = default;
};

Static_class Static_class::create()
{
    Static_class obj;
    return obj;
}

#endif
