#include <iostream>
#include <functional>
#include <typeinfo>
#include <tuple>

template <typename R, typename... Args>
struct Caller
{
    Caller(R(*)(Args... args)){}
    using return_type = R;
    static constexpr size_t arg_count = sizeof...(Args);
    using arg_types = std::tuple<Args...>;
    template <std::size_t N>
    using Nth = typename std::tuple_element<N, Tuple>::type;
    using First = Nth<0>;
    using Last  = Nth<arg_count - 1>;

};

struct Point2D
{
    int x;
    int y;
};

struct Point3D
{
    int x;
    int y;
    int z;
};

int sum(int a, int b)
{
    return a + b;
}

double double_sum(double a, double b)
{
    return a + b;
}

Point2D point_2d(int x, int y)
{
    return {x, y};
}

Point3D point_3d(int x, double y, float z)
{
    return {x, static_cast<int>(y), static_cast<int>(z)};
}

int main()
{
    Caller calls(point_3d);

    size_t argc = calls.arg_count;
    std::cout << "Return type: " << typeid(typename decltype(calls)::return_type).name() << '\n';
    std::cout << "Argument count: " << argc << '\n';
    return 0;
}
