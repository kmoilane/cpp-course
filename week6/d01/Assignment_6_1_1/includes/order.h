#ifndef ORDER_H
#define ORDER_H

enum class Order_status {
    ordered,
    processing,
    processed,
    delivered,
};

struct Order {
    Order_status status = Order_status::ordered;
    void print_status() const;
    void update_status();
};

#endif
