#include "includes/iterator.hpp"
#include "includes/utf8.hpp"
#include <iostream>
#include <string>


int main()
{
    std::string utf8String{"u8äöå🍍"}; // UTF-8 encoded string
    utf8::Utf8String normstr{"Testing string using ascii characters\n"};
    
    //utf8::Utf8Iterator begin0(normstr.begin());
    //utf8::Utf8Iterator end0(normstr.end());

/*
    for (utf8::Utf8Iterator it = begin0; it != end0; ++it) {
        std::cout << *it;
    }
*/
    utf8::Utf8Iterator begin(&(*utf8String.begin()));
    utf8::Utf8Iterator end(&(*utf8String.end()));


    for (utf8::Utf8Iterator it = begin; it != end; ++it) {
        std::cout << "Codepoint: " << *it << '\n';
    }

    Utf8Iterator begin1(utf8String.begin());
    Utf8Iterator end1(utf8String.end());
    
    for (Utf8Iterator it = begin1; it != end1; ++it) {
        std::cout << "Codepoint: " << *it << '\n';
    }

    return 0;
}
