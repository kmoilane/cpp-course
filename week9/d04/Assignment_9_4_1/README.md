# Assignment_9_4_1

## Exercise 1

In exercise 6.1.2 we created a tagged union of our own.
Reimplement the same using a `std::variant` instead.
Use full name instead of the initial this time around.

## Exercise 2

In Ex. 7.4.1 we created a animals using virtual inheritance.
Recreate the same animals without using virtual, and then create
a `std::variant` of the animals and fill a vector with those.

Look at documentation of `std::visit`,
https://en.cppreference.com/w/cpp/utility/variant/visitLinks to an external site.

- Using the "void visitor", call the demonstration function of each animal entry.
- Using one of the type-matching visitors, print some text relating to the
  animal matched
