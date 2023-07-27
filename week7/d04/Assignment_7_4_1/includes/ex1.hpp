#ifndef EX1_HPP
#define EX1_HPP

#include <iostream>
#include <string>

class Animal
{
    public:
        virtual std::string make_sound() = 0;
        virtual ~Animal() {}
    private:

};

class Dog : Animal
{
    public:
        std::string make_sound() final
        {
            return std::string{"Woof woof"};
        }
    private:
};

class Lion : Animal
{
    public:
        std::string make_sound() final
        {
            return std::string{"RRROAAARGH"};
        }
    private:
};

#endif
