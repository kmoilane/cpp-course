# Assignment 7_2_2

## Exercise 1

Take a look at C function printf and especially its format specifiers
(https://alvinalexander.com/programming/printf-format-cheat-sheet/)

Create a template function with a signature that is something like

`template <typename... Ts>`

`void safe_printf(const std::string& fmt, Ts... args);`

that checks that the arguments given to the printf are of correct type.

Links to an external site.
## Exercise 2

We can use either static_assert of requires (c++20) to force a certain number
of parameters for a variadic function.  Create a class where the constructor
takes any number of arguments and store that number in class template parameters
or a constexpr static class member or a template parameter using default
(or you can save the parameter pack itself if you want, but that is tricky,
so consider it completely optional brain-teaser).

- Create function to return the number of arguments the constructor was called
with
- Create an another function that requires, at compile-time, the exact
number of arguments the constructor was called with
 

## Exercise 3 (optional)

We created a type for a 2D grid, think about ways this grid could be
generalised to arbitrary dimenions using variadics.  You can try this out
if you want to, but don't get discouraged if you don't get it to work.
It's not the easiest thing to do.

