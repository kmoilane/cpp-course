#ifndef EX1_HPP
#define EX1_HPP

#include <vector>
#include <iostream>

/*
** A common pattern is to store elements contiguous in memory, and then just
** store a handle to the stored element with the class actually used.
** This way objects of similar type can be stored contiguously, and we can avoid
** some cache trashing.
*/

// We have a class for the actual data we store, usually not directly accessible
struct object_data
{
    std::string name {};
};

/*
** and the storage in a vector. This usually is a bit less obvious than a static
** global variable, but it'll do here.
*/
static std::vector<object_data> object_storage {};

// And then the publicly available class we actually use to access the data
class large_object
{
    public:
        large_object();
        ~large_object();
        /* default the copy constructor, since the class is basically just the handle anyways*/
        large_object(const large_object& other);

    private:
        /*
        ** int is often used as a handle, so negative values can be used to denote
        ** errors. std::size_t is another often seen choice, but we aren't going
        ** to create more than INT_MAX elements in our container here.
        */
        int handle {};
};

// Implementations
large_object::large_object()
{
    int next_handle = object_storage.size();
    // create new default-initialised value in the container
    // and set our handle to match the index
    object_storage.push_back({std::string("object number ") + std::to_string(next_handle)});
    handle = next_handle;
}
large_object::~large_object()
{
    // delete the handle'th element from the storage
    object_storage.erase(object_storage.begin() + handle);
};

large_object::large_object(const large_object& other)
{
    object_storage.push_back({std::string("object number ") + std::to_string(other.handle)});
}

#endif
