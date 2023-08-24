#include <atomic>
#include <chrono>
#include <iostream>
#include <mutex>
#include <string>
#include <thread>
#include <vector>

static std::atomic_bool quit { false };
static std::mutex log_mutex;

void log_msg(std::vector<std::string>& log)
{
    std::scoped_lock log_lock{log_mutex};
    log.push_back(std::string("Timed logging message..."));
}

void ui_loop(std::vector<std::string>& log)
{
    std::jthread log_thread(log_msg, std::ref(log));
    log_thread.join();
    while (true)
    {
        std::cout << "Reading input...\n";
        std::string input;
        std::cin >> input;
        std::scoped_lock log_lock{log_mutex};
        log.push_back(input);
        if (input == "quit")
        {
            quit = true;
            return;
        }
        else if (input == "log")
        {
            for (const auto& line : log)
                std::cout << line << '\n';
            std::cout << std::endl;
        }
    }
}


int main()
{
    using namespace std::chrono_literals;

    std::vector<std::string> log;
    std::jthread ui_thread(ui_loop, std::ref(log));
    while (!quit)
    {
        log_msg(log);
        std::this_thread::sleep_for(1000ms);
    }
    return 0;
}
