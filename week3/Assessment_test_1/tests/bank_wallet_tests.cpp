#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "includes/doctest.h"
#include "../includes/structs.h"
#include "../includes/utils.h"
#include "../includes/transactions.h"
#include <limits>

TEST_CASE("Testing input validation")
{
    CHECK(validate_int_option(1, 1, 2) == true);
    CHECK(validate_int_option(2, 1, 2) == true);
    CHECK(validate_int_option(0, 1, 2) == false);
    CHECK(validate_int_option(3, 1, 2) == false);
}

TEST_CASE("Testing deposit validation")
{
    CHECK(validate_deposit(-100, 200) == false);
    CHECK(validate_deposit(std::numeric_limits<double>::max(), 200) == false);
    CHECK(validate_deposit(0, 200) == false);
    CHECK(validate_deposit(100000000000000, 0) == true);
    CHECK(validate_deposit(std::numeric_limits<double>::max(), -10) == false);
}

TEST_CASE("Testing withdraw validation")
{
    CHECK(validate_withdraw(-100, 200) == false);
    CHECK(validate_withdraw(400, 200) == false);
    CHECK(validate_withdraw(0, 200) == false);
    CHECK(validate_withdraw(100000000000000, 0) == false);

}

TEST_CASE("Testing withdrawal")
{
    CHECK(addition(300, 65.5) == 365.5);
    CHECK(substraction(300, 65.5) == 234.5);
}
