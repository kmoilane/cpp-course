#include <iostream>

template <std::size_t N>
class Taker
{
    public:
        template <typename... Ts>
        Taker(Ts...) {}
        constexpr std::size_t get_arg_count() const
        {
            return arg_count;
        }

        template <typename... Ts>
        int sum(Ts... args)
        {
            static_assert(sizeof...(args) == arg_count, "Invalid amount of arguments");
            return ( args + ... );
        }
    private:
        static constexpr std::size_t arg_count {N};
};

/*
**  Deduction?
*/
template <typename... Ts>
Taker(Ts...) -> Taker<sizeof...(Ts)>;

int main()
{
    Taker taker(1, 5);
    std::cout << "Argument count: " << taker.get_arg_count() << '\n';
    std::cout << "4 + 4 = " << taker.sum(4, 4) << '\n';
    return 0;
}
