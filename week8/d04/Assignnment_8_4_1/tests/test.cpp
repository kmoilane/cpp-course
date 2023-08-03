#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "includes/doctest.h"
#include "../includes/ex1.hpp"

TEST_CASE("EX1 Tests")
{
    SUBCASE("Testing default constructor and destructor")
    {
        CHECK(1 == 1);
        {
            large_object l1;
            CHECK(object_storage[0].name == std::string("object number 0"));
            large_object l2;
            CHECK(object_storage[1].name == std::string("object number 1"));
            large_object l3;
            CHECK(object_storage[2].name == std::string("object number 2"));
            CHECK(object_storage.size() == 3);
        }
        CHECK(object_storage.size() == 0);
    }
    SUBCASE("Testing copy constructor")
    {
        large_object l1;
        CHECK(object_storage[0].name == std::string("object number 0"));
        large_object l2 = l1;
        CHECK(object_storage[1].name == std::string("object number 0"));
        large_object l3;
        CHECK(object_storage[2].name == std::string("object number 2"));
    }
}
