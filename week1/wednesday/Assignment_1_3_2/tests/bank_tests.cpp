#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "includes/doctest.h"
#include "../includes/structs.h"
#include "../includes/bank.h"

TEST_CASE("Testing ask_amount")
{
    CHECK(ask_amount() == -1);
    CHECK(ask_amount());
}
