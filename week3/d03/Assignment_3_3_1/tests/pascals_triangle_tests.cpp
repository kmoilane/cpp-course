#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../externals/doctest.h"
#include "../includes/pascals_triangle.h"

TEST_CASE("Testing factorial function")
{
    CHECK(factorial(2) == 2);
    CHECK(factorial(0) == 1);
    CHECK(factorial(3) == 6);
    CHECK(factorial(-2) == 1);
}
