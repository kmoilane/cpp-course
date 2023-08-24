#include <future>
#include <iostream>
#include <numeric>
#include <thread>
#include <vector>

void compare_vect(const std::vector<int>& axel, std::vector<int>& veloc)
{
    for (int i = 0; i < axel.size() - 1; ++i)
    {
        for (int j = i + 1; j < axel.size(); ++j)
        {
            if (axel[i] < axel[j])
            {
                veloc[i]++;
                veloc[j]--;
            }
            else if(axel[i] > axel[j])
            {
                veloc[i]--;
                veloc[j]++;
            }
        }
    }
}

void update(std::vector<int>& axel, std::vector<int>& veloc)
{
    for (int i = 0; i < axel.size(); ++i)
    {
        axel[i] += veloc[i];
    }
}

void period(std::vector<int>& axel, std::vector<int>& veloc, std::promise<int> count_promise)
{
    int step {0};
    do
    {
        compare_vect(axel, veloc);
        update(axel, veloc);
        step++;
    } while (veloc != std::vector<int>{0, 0, 0, 0, 0});
    count_promise.set_value(step);
}

constexpr auto lcm(auto x, auto... xs)
{
    return ((x = std::lcm(x, xs)), ...);
}

int main()
{
    std::vector<int> x_vect{0, -10, 6042, -42, 0};
    std::vector<int> y_vect{5, 7, 4, 55, -54189072};
    std::vector<int> z_vect{2, -94, 8, 92, 0};

    std::vector<int> x_velocity{0, 0, 0, 0, 0};
    std::vector<int> y_velocity{0, 0, 0, 0, 0};
    std::vector<int> z_velocity{0, 0, 0, 0, 0};

    std::promise<int> x_promise;
    std::promise<int> y_promise;
    std::promise<int> z_promise;

    std::future<int> x_future = x_promise.get_future();
    std::future<int> y_future = y_promise.get_future();
    std::future<int> z_future = z_promise.get_future();

    std::jthread x_thread(period, std::ref(x_vect), std::ref(x_velocity), std::move(x_promise));
    std::jthread y_thread(period, std::ref(y_vect), std::ref(y_velocity), std::move(y_promise));
    std::jthread z_thread(period, std::ref(z_vect), std::ref(z_velocity), std::move(z_promise));

    int x_steps = x_future.get() * 2;
    int y_steps = y_future.get() * 2;
    int z_steps = z_future.get() * 2;

    std::cout << lcm(x_steps, y_steps, z_steps);

    return 0;
}
