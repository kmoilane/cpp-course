#include <iostream>
#include <optional>
#include <expected>

class Optional
{
    public:
        static std::optional<Optional> create(char c)
        {
            if (c == 'a' || c == 'b' || c == 'c')
                return Optional(c);
            return {};
        }
        char letter;
    private:
        Optional(char c) : letter(c) {}
};

enum class Error
{
    underage,
    overage,
};

class Expected
{
    public:
        static std::expected<Expected, Error> create(int a)
        {
            if (a >= 18 && a < 100)
                return Expected(a);
            else if(a < 18)
                return std::unexpected(Error::underage);
            return std::unexpected(Error::overage);
        }
        int age {};
    private:
        Expected(int a) : age(a) {}
};

void expected_errors(Error error)
{
    switch (error)
    {
        case Error::overage:
            std::cout << "You're too old for this!\n";
            return;
        case Error::underage:
            std::cout << "You're too young for this!\n";
            return;
        default:
            std::cout << "Unexpected has happened!\n";
            return;
    }
}

int main()
{
    /*
    **  Exercise 1
    */
    auto test = Optional::create('d');

    if (!test.has_value())
    {
        std::cout << "You can create Optional type with only 'a', 'b' or 'c'\n";
    }
    else
        std::cout << test.value().letter << '\n';

    auto test1 = Optional::create('b');

    if (!test1.has_value())
    {
        std::cout << "You can create Some_class with only 'a', 'b', 'c'\n";
    }
    else
        std::cout << test1.value().letter << '\n';

    /*
    **  Exercise 2
    */
    auto test2 = Expected::create(17);
    if (!test2.has_value())
    {
        expected_errors(test2.error());
    }
    else
        std::cout << test2.value().age << '\n';

    auto test3 = Expected::create(21);
    if (!test3.has_value())
        expected_errors(test3.error());
    else
    {
        Expected type = test3.value();
        std::cout << type.age << '\n';
    }
    auto test4 = Expected::create(101);
    if (!test4.has_value())
        expected_errors(test4.error());
    else
    {
        Expected type = test4.value();
        std::cout << type.age << '\n';
    }

    return 0;
}
