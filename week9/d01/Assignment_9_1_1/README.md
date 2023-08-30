# Assignment_9_1_1

## Exercise 1

Create a table of functions (std::vector is fine).  Then read user input from
command line, standard input or a file (your choice), where user determines
which function in the array to call.

## Exercise 2

Use std::unordered_map<char, std::function<...>> to map a character to a
function. Fill the map with operations '+', '-', '*' and '/'.

Then read a line such as

1 + 1

and parse the line to call the right function with the right parameters.
(You could e.g. use spaces as separators for left value, operator, right value,
there are plenty of ways to parse it)

This is basically a improved way to handle the usual "make a calculator"
exercise. Try adding your own operators to do other stuff as well.

## (Optional) Exercise 3

Think about how far could you push the calculator?  How could you add variables
e.g. a = 453?
