#include "includes/order.h"

/*
**  Loops through all the states, prints the state and then updates it.
**  Stops the loop when we get to delivered state.
*/
int main()
{
    Order new_order;
    
    while (true)
    {
        new_order.print_status();
        new_order.update_status();
        if (new_order.status == Order_status::delivered)
        {
            new_order.print_status();
            break ;
        }
    }
    return 0;
}
