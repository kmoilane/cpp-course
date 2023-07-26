# Assignment 7_3_1

## Exercise 1

Create a template class and overload its equality operator.

The overridden operator should `static_cast` its arguments to a type given
as a template parameter and do the comparison.

 

## Exercise 2

Create a new type of your own choosing, and use CRTP to give it the equality comparison
functionality from the result of exercise 1.

 

## Exercise 3

Create another template class and give it a function to print out its type
(e.g. by using typeid or some simple checker with type_traits, no need
to handle everything). Then inherit both this functionality and
the functionality created in ex 1. to your type.
