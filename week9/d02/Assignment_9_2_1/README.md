# Assignment_9_2_1

## Exercise 1

Create a function to check if nth bit is set in an value.

## Exercise 2

Create a template function to swap byte order of the value it is given,
regardless of its size.  It should work at least for unsigned integer types.
Use static_assert with the type_traits header to make sure only integral
types are accepted.

## Exercise 3

Create a set of flags for 8 different options.
You may make the options up yourself or use the following

```c++
constexpr static uint8_t IS_FUZZY            = 0b1;
constexpr static uint8_t IS_LARGE            = 0b10;
constexpr static uint8_t HAS_GOOGLY_EYES     = 0b100;
constexpr static uint8_t IS_CUTE             = 0b1000;
constexpr static uint8_t HAS_TEETH           = 0b10000;
constexpr static uint8_t IS_ABOUT_TO_EAT_YOU = 0b100000;
constexpr static uint8_t IS_FRIENDLY         = 0b1000000;
constexpr static uint8_t IS_SPIDER           = 0b10000000;
```

Create a function to print out set options given a set of flags in
human-readable form. You can use a type of your own or uint8_t directly
(it is smart to create at least a type alias though)

## Exercise 4

Create another function to check for certain combinations of the set flags,
and print out something special for those.  There are 256 options in the
8-bit bitset, so don't worry about covering every case,
just a couple of them will do.

## Exercise 5

Bitmasking is a technique to mark locations of certain values.
We now want to create a bitmask from a string input.

Create a program, where you let user input a string
(either read it from command line or use I/O functions, it doesn't matter
as long as the string is given by the end-user)
You may assign a max size for the string.

Go through bytes in the string, and for each character of the string, mark
the bit set if the character represents a comma.

Print out the resulting bits.

e.g. ( "123,43,55" would produce a value of 0b1001000, as fourth and seventh
character is a comma)
