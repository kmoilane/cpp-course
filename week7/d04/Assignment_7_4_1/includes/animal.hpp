#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>

class Animal
{
    public:
        virtual std::string what() const { return name; }
        virtual std::string make_sound() const = 0;
        virtual bool safe_to_pet() const { return false; }
        virtual bool has_fur() const { return false; }
        virtual bool has_scales() const { return false; }
        virtual std::string animal_class() const = 0;
        virtual std::string latin_name() const { return "Animalia"; }
        virtual ~Animal() = default;
        
    private:
        std::string name {""};

};

class Dog : public Animal
{
    public:
        std::string what() const final { return name; }
        std::string make_sound() const final { return std::string{"Woof woof"}; }
        bool safe_to_pet() const final { return true; }
        std::string animal_class() const final { return "Mammal"; }
        std::string latin_name() const final { return  "Canis lupus familiaris"; }
        bool has_fur() const final { return true; }

    private:
        std::string name {"Dog"};
};

class Lion : public Animal
{
    public:
        std::string what() const final { return name; }
        std::string make_sound() const final { return std::string{"RRROAAARGH"}; }
        std::string animal_class() const final { return "Mammal"; }
        std::string latin_name() const final { return  "Panthera leo"; }
        bool has_fur() const final { return true; }

    private:
        std::string name {"Lion"};
};

class Alligator : public Animal
{
    public:
        std::string what() const final { return name; }
        std::string make_sound()const  final { return "Grrrrrr"; };
        std::string animal_class() const final { return "Reptile"; }
        std::string latin_name() const final { return "Alligator mississippiensis"; }
        bool has_scales() const final { return true; }

    private:
        std::string name {"Alligator"};
};

#endif
