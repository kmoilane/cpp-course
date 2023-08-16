# Assignment_10_3_1

## Exercise 1

Sometimes it's possible to bypass some of limitations (e.g. if only dynamic
memory allocation is forbidden) by instead using statically allocated memory.

Look at [Allocator requirements](https://en.cppreference.com/w/cpp/named_req/Allocator)

- Statically allocate a block of memory
(e.g. by creating std::array, or uint8_t[SIZE] block).
- Create an allocator that uses the placement new to construct objects to
the memory from the static block, and manually call the destructor when deconstructing.

Try to use your allocator with std::vector.

If you can't finish this task, just post how far you got.
It's not as easy as it might first seem.

## Exercise 2 (Optional)

Create unit tests for your allocator
