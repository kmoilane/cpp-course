#include <iostream>
#include <type_traits>

template <typename Derived>
struct Ex1 {};

template <typename Derived>
struct Ex3 {
    void print_type()
    {
        std::cout << "Type: " << typeid(Derived).name() << '\n';
    }
};

struct Ex2 : Ex1<Ex2>, Ex3<Ex2>
{
    public:
        Ex2() noexcept = default;

        Ex2(int val) noexcept : data(val) {}

        bool operator<(const Ex2& other) const
        {
            return data < other.data;
        }
        friend std::ostream& operator<<(std::ostream& os, const Ex2& ex2);
    private:
        int data;
};

/*
**  Ex2 operator<< overlaod to print the data
*/
std::ostream& operator<<(std::ostream& os, const Ex2& ex2)
{
    os << ex2.data;
    return os;     
}

/*
**  Ex1 operator overloads
*/
template <typename Derived>
bool operator==(const Ex1<Derived>& lhs, const Ex1<Derived>& rhs) noexcept
{
    return !(static_cast<const Derived&>(rhs) <
            static_cast<const Derived&>(lhs)) &&
            !(static_cast<const Derived&>(lhs) <
            static_cast<const Derived&>(rhs));
}

template <typename Derived>
bool operator!=(const Ex1<Derived>& lhs, const Ex1<Derived>& rhs) noexcept
{
    return static_cast<const Derived&>(rhs) < static_cast<const Derived&>(lhs) ||
            static_cast<const Derived&>(lhs) < static_cast<const Derived&>(rhs);
}

template <typename Derived>
bool operator>(const Ex1<Derived>& lhs, const Ex1<Derived>& rhs) noexcept
{
    return static_cast<const Derived&>(rhs) < static_cast<const Derived&>(lhs);
}

template <typename Derived>
bool operator>=(const Ex1<Derived>& lhs, const Ex1<Derived>& rhs) noexcept
{
    return static_cast<const Derived&>(rhs) <
            static_cast<const Derived&>(lhs) ||
            (!(static_cast<const Derived&>(lhs) <
            static_cast<const Derived&>(rhs)) &&
            !(static_cast<const Derived&>(rhs) <
            static_cast<const Derived&>(lhs)));
}

template <typename Derived>
bool operator<=(const Ex1<Derived>& lhs, const Ex1<Derived>& rhs) noexcept
{
    return static_cast<const Derived&>(lhs) <
            static_cast<const Derived&>(rhs) ||
            (!(static_cast<const Derived&>(lhs) <
            static_cast<const Derived&>(rhs)) &&
            !(static_cast<const Derived&>(rhs) <
            static_cast<const Derived&>(lhs)));
}

/*
**  End of Ex1 operator overloads
*/

int main()
{
    Ex2 test1 {1};
    Ex2 test2 {2};
    Ex2 test3 {2};
    Ex2 test4 {3};
    std::cout << std::boolalpha;
    std::cout << test1 << " == " << test2 << " = " << (test1 == test2) << '\n';
    std::cout << test2 << " == " << test3 << " = " << (test2 == test3) << '\n';
    std::cout << test1 << " < " << test2 << " = " << (test1 < test2) << '\n';
    std::cout << test2 << " > " << test1 << " = " << (test2 > test1) << '\n';
    std::cout << test2 << " >= " << test3 << " = " << (test2 >= test3) << '\n';
    std::cout << test1 << " >= " << test2 << " = " << (test1 >= test2) << '\n';
    std::cout << test2 << " <= " << test3 << " = " << (test2 <= test3) << '\n';
    std::cout << test2 << " <= " << test1 << " = " << (test2 <= test1) << '\n';
    test4.print_type();

    return 0;
}
