#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

static std::atomic_int sum{0};
static std::mutex sum_mutex;

void world()
{
    std::cout << "world!\n";
}


void hello()
{
    std::cout << "Hello, ";
}

void add(int increment, int times)
{
    for (int i = 0; i < times; i++)
    {
        sum += increment;
    }
}

void increment_sum(int increment, int times)
{
    std::scoped_lock sum_lock{sum_mutex};
    for (int i = 0; i < times; i++)
        sum += increment;
}


int main()
{
    /*
    **  Exercise 1
    */
    std::thread t1(hello);
    std::thread t2(world);

    t1.join();
    t2.join();

    /*
    **  Exercise 2
    */
    std::vector<std::thread> tvect;
    int straight_up {0};

    for (int i = 0; i < 100; i++)
    {
        tvect.push_back(std::thread(add, 2, 2));
        straight_up += 4;
    }
    for (auto& thread : tvect)
        thread.join();

    std::cout << "100 * (2 * 2) = " << straight_up << '\n';
    std::cout << "threads got: " << sum << '\n';

    /*
    **  Exercise 3
    */
    sum = 0;
    straight_up = 0;
    std::vector<std::jthread> tvect2;

    for (int i = 0; i < 100; i++)
    {
        tvect2.push_back(std::jthread(add, 4, 4));
        straight_up += (4 * 4);
    }
    for (auto& thread : tvect2)
        thread.join();

    std::cout << "100 * (4 * 4) = " << straight_up << '\n';
    std::cout << "threads got: " << sum << '\n';

    return 0;
}
