#include <iostream>
#include <variant>
#include <vector>

struct Cow
{
    std::string name;
    void make_sound() { std::cout << name << ": MooooOOOooo\n"; }
};

struct Monkey
{
    std::string name;
    void make_sound() { std::cout << name << ": u-u-U-A-a-A\n"; }
};

struct Seagull
{
    std::string name;
    void make_sound() { std::cout << name << ": Ka-kaaaa\n"; }
};

using animal_variant = std::variant<Cow, Monkey, Seagull>;

int main()
{
    animal_variant var1 = Monkey{"Abu"};
    animal_variant var2 = Cow{"Molly"};
    animal_variant var3 = Seagull{"Gail"};
    std::vector<animal_variant> animal_vars{var1, var2, var3};

    for (auto& v: animal_vars)
    {
        std::visit([](auto arg) { arg.make_sound(); }, v);
    }
}
