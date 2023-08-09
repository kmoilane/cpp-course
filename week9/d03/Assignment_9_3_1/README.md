# Assignment_9_3_1

## Exercise 1

Use iterator-based for loop to go through a string and print individual
characters. What happens when there's a character outside of ASCII charset?
(try with e.g. emoji, åäö, etc.)

Also print out the character as integers (to see the value of bytes beneath)

## Exercise 2

Most of the time we are dealing with unicode (more specifically UTF-8) strings.
It is the most common way to encode text, and almost everything
except Windows uses it.

Launch up our trusted reference again read through the [Iterator
requirements](https://en.cppreference.com/w/cpp/named_req/Iterator), we are
going to implement our own. Also familiarise yourself a bit with
[UTF8-encoding](https://en.wikipedia.org/wiki/UTF-8).
Wikipedia is enough for us this time around unless you want to dive deeper
yourself.

## Exercise 3

So, what we want is a way to traverse individual unicode codepoints of an
`std::string` (so we get ä, ö, å, 🍍 etc., as one codepoint).

Create a type that wraps a pointer of type `std::string::pointer`.
This will be our starting point of our iterator.  Then, at first, implement a
simple increment and dereference operators and conversion constructors
from `std::string::iterator`.

Try to iterate through elements of `std::string` with your own iterator, and
verify that the functionality at this point is equivalent to
the `std::string::iterator`.

## Exercise 4

We can use `char32_t` as our unicode codepoint type (that is what is was designed
for). Make sure dereferencing our iterator uses that type.

Then reimplement the increment operator so incrementing it moves to the next
unicode codepoint instead of next byte.  (Use wikipedia and google to your
advantage here, it's fine if you can find a ready-made implementation for
checking unicode length etc., and use that as a helper.  The wikipedia article
is enough to know all there needs to be, but it might be useful to search other
sources as well.)

## Exercise 5

Reimplement the dereferencing operator so it reads the entire codepoint,
and returns its value.

## Exercise 6 (Optional, but recommended)

Write unit tests for your iterator.

## Exercise 7 (Optional)

Write an adapter class that wraps std::string (storing a reference to it), and
rewrite its `begin()`, `end()` and `size()` to use your own iterator instead of the
default one that comes with `std::string`

If you got this far, brilliantly done!  Writing iterators + adaptors like this
can be used to implement a lot of useful stuff.  And some nice stuff like
functionality similar to python's `enumerate` in ranged-for loops.  It's extremely
useful, but a bit more rarely used technique.
