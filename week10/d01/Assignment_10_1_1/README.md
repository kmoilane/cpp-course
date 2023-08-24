# Assignment_10_1_1

## Exercise 1

From the main thread, create two threads, one of which prints "Hello, "
and the other "world!\n".
Run your program a couple of times.

## Exercise 2

Create a function that adds an integer n times to a static global variable.
e.g. `void add(int increment int times);` Use a loop to do the increments.
Create 100 threads from the main() function to call the add-function.
Compare the result to straight-up calculation.

## Exercise 3

Repeat exercise 2, but use mutexes to lock the summation so only one thread
can do the increment at a time (check out std::lock_guard as well)

## Exercise 4

Repeat exercise 2, but use std::atomic type as your global sum type.
