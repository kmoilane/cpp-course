#ifndef UTF8_HPP
#define UTF8_HPP

#include <string>

namespace utf8
{

class Utf8Iterator
{
    public:
        using value_type        = std::string::value_type;
        using iterator          = std::string::iterator;
        using const_iterator    = std::string::const_iterator;
        using reference         = std::string::reference;
        using const_reference   = std::string::const_reference;
        using pointer           = std::string::pointer;

        Utf8Iterator() = default;
        Utf8Iterator(const std::string::pointer& it) : mptr(&(*it)) {}
        Utf8Iterator(const std::string::iterator& it) : mptr(&(*it)) {}
        Utf8Iterator(const iterator& it) : mptr(&(*it)) {}
        //Utf8Iterator(const const_iterator& it) : mptr(&(*it)) {}
        value_type operator*() { return *mptr; }
        Utf8Iterator operator++() { ++mptr; return *this; }
        Utf8Iterator operator=(const Utf8Iterator& rhs) { mptr = rhs.mptr; return *this; }
        const bool operator!=(const Utf8Iterator& rhs) const { return mptr != rhs.mptr;}
        const bool operator==(const Utf8Iterator& rhs) const { return mptr == rhs.mptr; }
    private:
        pointer mptr;
        
};

class Utf8String
{
    public:
        using iterator = Utf8Iterator;
        explicit Utf8String(const std::string& str) : utf8_str(str) {}
        //iterator begin() const { return iterator(utf8_str.begin()); }
        //iterator end() const { return iterator(utf8_str.end()); }

    std::size_t size() const
    {
        std::size_t count = 0;
        for (Utf8Iterator it = begin(); it != end(); ++it)
        {
            ++count;
        }
        return count;
    }

    private:
        const std::string& utf8_str;
};

}

#endif
