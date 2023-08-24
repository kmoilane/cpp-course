#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../includes/counter.hpp"
#include "includes/doctest.h"

TEST_CASE("Testing instance counter")
{
    SUBCASE("Testing default constructor")
    {
        Counter c1;
        Counter c2;
        Counter c3;
        CHECK(Counter::get_count() == 3);
    }
    SUBCASE("Testing move constructor")
    {
        Counter c1;
        Counter c2(std::move(c1));
        Counter c3;
        CHECK(Counter::get_count() == 2);
    }
    SUBCASE("Testing move assignment")
    {
        Counter c1;
        Counter c2 = std::move(c1);
        Counter c3;
        CHECK(Counter::get_count() == 2);
        {
            Counter c4;
            Counter c5;
            CHECK(Counter::get_count() == 4);
            {
                Counter c6(std::move(c4));
                CHECK(Counter::get_count() == 4);
            }
            CHECK(Counter::get_count() == 3);
        }
        CHECK(Counter::get_count() == 2);
    }
    SUBCASE("Testing that there's 0 instances left")
    {
        CHECK(Counter::get_count() == 0);
    }
}
