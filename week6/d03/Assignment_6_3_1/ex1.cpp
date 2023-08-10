#include "includes/ex1.hpp"

int main()
{
    Static_class obj { Static_class::create() };
    obj.hello();
    return 0;
}
