#ifndef COUNTER_HPP
#define COUNTER_HPP

#include <iostream>

class Counter {
    public:
        Counter() { ++instance_count; }
        Counter(const Counter& other) = delete;
        Counter(Counter&& other)
        {
            other.is_moved = true;
        }
        ~Counter()
        { 
            if (!is_moved)
                --instance_count;
        }
        static size_t get_count() {return instance_count;}

    private:
        inline static size_t instance_count;
        bool is_moved { false };

};

#endif
