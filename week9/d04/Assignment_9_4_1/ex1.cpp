#include <iostream>
#include <variant>
#include <string>

struct Human
{
    char letter;
};

struct Robot
{
    int id;
};

struct Alien
{
    double wavelen;
};

using my_variant = std::variant<Human, Robot, Alien>;

void print_variant(my_variant variant)
{
    if (std::holds_alternative<Human>(variant))
        std::cout << "Human : " << std::get<Human>(variant).letter << '\n';
    else if (std::holds_alternative<Robot>(variant))
        std::cout << "Robot : " << std::get<Robot>(variant).id << '\n';
    else if (std::holds_alternative<Alien>(variant))
        std::cout << "Alien : " << std::get<Alien>(variant).wavelen << '\n';
}

int main()
{
    my_variant variant;
    
    variant = Human{'h'};
    print_variant(variant);
    variant = Alien{42.42};
    print_variant(variant);
    variant = Robot{42};
    print_variant(variant);

    return 0;
}
