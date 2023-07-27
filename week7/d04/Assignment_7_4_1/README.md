# Assignment 7.4.1

## Exercise 1

Create a virtual base class animal.

Animal should have a virtual member function make_sound() that returns a string.
You can either make this pure virtual or give a generic animal sound message.

In addition create a couple of classes deriving the animal class and override
the make_sound() function.

Pay attention to const-ness, virtual-ness, and use final and override
qualifiers where necessary.

## Exercise 2

Create couple of other functions for the animal base class for the animals to
do. These should be abstract, but not pure virtual.  Make up your own, but you
could use e.g. bool is_fluffy() const.  The point here is just to have a couple
of functions not every derived animal has.

## Exercise 3

Create a free function that takes animal reference as a parameter,
and demonstrates the functions of the object.

## Exercise 4

Try adding a name member field for the animal class.
It should be empty string as a default for animals, 
then each animal type should have its own suitable default value.

## Exercise 5

Try creating an std::vector of animal type. Add different animals as
elements of the vector, and then use a loop to iterate through the vector and
call your demonstration function.  What do you notice?  (We'll fix this later)
