#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../externals/doctest.h"
#include "../includes/string_utility.h"

TEST_CASE("Testing reverse_string")
{
    CHECK(reverse_string("hello there!") == "!ereht olleh");
    CHECK(reverse_string("123456789") == "987654321");
}

TEST_CASE("Testing string_to_upper")
{
    CHECK(string_to_upper("hello there!") == "HELLO THERE!");
    CHECK(string_to_upper("123456789") == "123456789");
    CHECK(string_to_upper("HELLO THERE!") == "HELLO THERE!");
    CHECK(string_to_upper("Hello theRE!") == "HELLO THERE!");
}

TEST_CASE("Testing string_to_lower")
{
    CHECK(string_to_lower("hello there!") == "hello there!");
    CHECK(string_to_lower("123456789") == "123456789");
    CHECK(string_to_lower("heLLo therE!") == "hello there!");
    CHECK(string_to_lower("HELLO THERE!") == "hello there!");
}

TEST_CASE("Testing string_is_palindrome")
{
    CHECK(string_is_palindrome("saippuakivikauppias") == true);
    CHECK(string_is_palindrome("saippuapullokauppias") == false);
}
