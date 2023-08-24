#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <vector>
#include <memory>
#include <iostream>


class Animal
{
    public:
        Animal() = default;
        Animal(std::string name_) : name(name_){};
        virtual std::string who() const { return name; }
        virtual std::string make_sound() const { return "Glunks"; }
        virtual bool safe_to_pet() const { return false; }
        virtual bool has_fur() const { return false; }
        virtual bool has_scales() const { return false; }
        virtual std::string animal_class() const { return "General animal"; }
        virtual std::string latin_name() const { return "Animalia"; }
        virtual ~Animal() = default;
        
        template <typename T>
        inline static void animal_info(const T& good_boy)
        {
            std::cout << std::boolalpha;
            std::cout << "I'm " << good_boy.who() << '\n';
            std::cout << good_boy.who() << " says " << good_boy.make_sound() << '\n';
            std::cout << "Safe to pet? " << good_boy.safe_to_pet() << '\n';
            std::cout << "Has fur? " << good_boy.has_fur() << '\n';
            std::cout << "Has scales? " << good_boy.has_scales() << '\n';
            std::cout << "Animal class: " << good_boy.animal_class() << '\n';
            std::cout << "Latin name: " << good_boy.latin_name() << '\n';
        }
        
        template <typename T>
        inline static void add_animal(const T& animal)
        {
            animals.emplace_back(std::make_unique<T>(animal));
        }

        inline static void print_animals()
        {
            for (auto& animal : animals)
            {
                animal_info(*animal);
                std::cout << '\n';
            }
        }

    private:
        std::string name {""};
        inline static std::vector<std::unique_ptr<Animal>> animals;

};

class Dog : public Animal
{
    public:
        Dog(std::string name_) : name(name_) {}
        std::string who() const final { return name; }
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
        Lion(std::string name_) : name(name_) {}
        std::string who() const final { return name; }
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
        Alligator(std::string name_) : name(name_) {}
        std::string who() const final { return name; }
        std::string make_sound()const  final { return "Grrrrrr"; };
        std::string animal_class() const final { return "Reptile"; }
        std::string latin_name() const final { return "Alligator mississippiensis"; }
        bool has_scales() const final { return true; }

    private:
        std::string name {"Alligator"};
};


#endif
