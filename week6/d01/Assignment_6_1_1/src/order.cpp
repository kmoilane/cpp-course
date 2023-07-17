#include "../includes/order.h"
#include <iostream>

/*
**  Prints the current state
*/
void Order::print_status() const
{
    std::cout << "Current state: ";

    switch(Order::status) {
        case Order_status::ordered : {
            std::cout << "ordered\n";
            break;
        }
        case Order_status::processing : {
            std::cout << "processing\n";
            break ;
        }
        case Order_status::processed : {
            std::cout << "processed\n";
            break;
        }
        case Order_status::delivered : {
            std::cout << "delivered\n";
            break ;
        }
    }
}

/*
**  Goes through the order status and assigns the next state
*/
void Order::update_status()
{
    switch(status) {
        case Order_status::ordered : {
            status = Order_status::processing;
            break;
        }
        case Order_status::processing : {
            status = Order_status::processed;
            break ;
        }
        case Order_status::processed : {
            status = Order_status::delivered;
            break;
        }
        case Order_status::delivered : {
            break ;
        }
    }
}
