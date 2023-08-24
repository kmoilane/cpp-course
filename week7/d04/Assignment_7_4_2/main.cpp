#include "includes/ui.hpp"
#include <iostream>

void do_something(int& val)
{
    return;
}

int main()
{
    Button btn;
    std::cout << "cursor: " << btn.cursor << '\n';
    btn.on_hover();
    std::cout << "cursor (on hover): " << btn.cursor << '\n';

    std::cout << "border color: " << btn.border.color << '\n';
    btn.on_focus();
    std::cout << "border color (on focus): " << btn.border.color << '\n';

    std::cout << "Position: " << btn.get_position() << '\n';
    btn.move({20, 20});
    std::cout << "Position (after move): " << btn.get_position() << '\n';

    btn.print_children();
    btn.add_child("magic");
    std::cout << "\nAdded magic as a child\n";
    btn.print_children();
    btn.remove_child("magic");
    std::cout << "\nRemoved magic\n";
    btn.print_children();
    return 0;
}
