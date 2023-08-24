#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include <string>

const unsigned char kFirstBitMask = 128; // 1000000
const unsigned char kSecondBitMask = 64; // 0100000
const unsigned char kThirdBitMask = 32; // 0010000
const unsigned char kFourthBitMask = 16; // 0001000
const unsigned char kFifthBitMask = 8; // 0000100

class Utf8Iterator
{
public:
    using value_type        = char32_t;
    using difference_type   = std::ptrdiff_t;
    using pointer           = value_type*;
    using reference         = value_type&;
    using iterator_category = std::forward_iterator_tag;

    Utf8Iterator() = default;
    Utf8Iterator(const std::string::iterator& it) : utf8_iterator(it) {}

    value_type operator*() const
    {
        char32_t code_point = 0;

        char first_byte = *utf8_iterator;
    
        if(first_byte & kFirstBitMask) // This means the first byte has a value greater than 127, and so is beyond the ASCII range.
        {
            if(first_byte & kThirdBitMask) // This means that the first byte has a value greater than 191, and so it must be at least a three-octet code point.
            {
                if(first_byte & kFourthBitMask) // This means that the first byte has a value greater than 224, and so it must be a four-octet code point.
                {
                    code_point = (first_byte & 0x07) << 18;
                    char second_byte = *(utf8_iterator + 1);
                    code_point +=  (second_byte & 0x3f) << 12;
                    char third_byte = *(utf8_iterator + 2);
                    code_point +=  (third_byte & 0x3f) << 6;;
                    char fourth_byte = *(utf8_iterator + 3);
                    code_point += (fourth_byte & 0x3f);
                }
                else
                {
                    code_point = (first_byte & 0x0f) << 12;
                    char second_byte = *(utf8_iterator + 1);
                    code_point += (second_byte & 0x3f) << 6;
                    char third_byte = *(utf8_iterator + 2);
                    code_point +=  (third_byte & 0x3f);
                }
            }
            else
            {
                code_point = (first_byte & 0x1f) << 6;
                char second_byte = *(utf8_iterator + 1);
                code_point +=  (second_byte & 0x3f);
            }
        }
        else
        {
            code_point = first_byte;
        }
    
        return code_point;
    }
    Utf8Iterator& operator++()
    {
        char first_byte = *utf8_iterator;
        std::string::difference_type offset = 1;
        if (first_byte & kFirstBitMask)
        {
            if (first_byte & kThirdBitMask)
            {
                if (first_byte  & kFourthBitMask)
                    offset = 4;
                else
                    offset = 3;
            }
            else
                offset = 2;
        }
        utf8_iterator += offset;
        return *this;
    }
    Utf8Iterator operator++(int) { Utf8Iterator tmp = *this; ++(*this); return tmp; }
    Utf8Iterator& operator--()
    {
        --utf8_iterator;
        if(*utf8_iterator & kFifthBitMask)
        {
            --utf8_iterator;
            if((*utf8_iterator & kSecondBitMask) == 0)
            {
                --utf8_iterator;
                if((*utf8_iterator & kSecondBitMask) == 0)
                    --utf8_iterator;
            }
        }
        return *this;
    }
    Utf8Iterator operator--(int) { Utf8Iterator tmp = *this; --(*this); return tmp; }
    bool operator==(const Utf8Iterator& rhs)        const { return utf8_iterator == rhs.utf8_iterator; }
    bool operator!=(const Utf8Iterator& rhs)        const { return utf8_iterator != rhs.utf8_iterator; }
    bool operator==(std::string::iterator rhs)      const { return utf8_iterator ==  rhs; }
    bool operator!=(std::string::iterator rhs)      const { return utf8_iterator !=  rhs; }
    bool operator!=(std::string::const_iterator rhs) const { return utf8_iterator !=  rhs; }
    bool operator==(std::string::const_iterator rhs) const { return utf8_iterator ==  rhs; }

private:
    std::string::iterator utf8_iterator;
};

#endif
