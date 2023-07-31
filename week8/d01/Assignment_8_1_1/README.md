# Assignment 8_1_1

## Exercise 1

Create a stack variable of any fundamental type in main()
function (so just an usual declaration). Then print out its memory address.

Create a function in the same program and do the same.
Compute the difference between the addresses and print that out too.

## Exercise 2

std::vector uses heap memory internally to store its contents. 
Create an std::vector, throw in some elements and print out the address
of the vector itself and all of its elements. Think about what you see. 
Is the vector's position in the memory same as its contents? Why?

## Exercise 3

Elements being contiguous in memory is an important concept.
This means they are located in the memory one after another.

Create a (template) function that takes a container as its input, and checks
if the elements in the container are next to each other.

Create few container types (list, vector, array, deque) and check if this holds
true. Try it with different counts of elements
(e.g. with 1000, 1000000, 100000000 elements)

## Exercise 4

Check if std::vector of std::vectors is contiguous.
