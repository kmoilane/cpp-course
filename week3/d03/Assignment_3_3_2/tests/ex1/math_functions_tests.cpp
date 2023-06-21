#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "../../externals/doctest.h"
#include "../../includes/math_functions.h"

TEST_CASE("Testing addition function")
{
    CHECK(addition(-10, -10) == -20);
    CHECK(addition(10, -10) == 0);
    CHECK(addition(10, 10) == 20);
    CHECK(addition(-10, 10) == 0);
}

TEST_CASE("Testing substraction function")
{
    CHECK(substraction(-10, -10) == 0);
    CHECK(substraction(10, -10) == 20);
    CHECK(substraction(10, 10) == 0);
    CHECK(substraction(-10, 10) == -20);
}

TEST_CASE("Testing multiplication function")
{
    CHECK(multiplication(-10, -10) == 100);
    CHECK(multiplication(10, -10) == -100);
    CHECK(multiplication(10, 10) == 100);
    CHECK(multiplication(-10, 0) == 0);
}

TEST_CASE("Testing division function")
{
    CHECK(division(250, -10) == -25);
    CHECK(division(-10, -10) == 1);
    CHECK(division(10, 10) == 1);
    CHECK_THROWS(division(-10, 0));
}
