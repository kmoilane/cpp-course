#include "includes/utils.h"
#include <iostream>

int main()
{
    int i = 0;
    while (true)
    {
        std::cout << i << '\n';
        i++;
        if (i == 1000)
            return 0;
    }
}
