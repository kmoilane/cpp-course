#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "cfile.hpp"
#include <iostream>

enum class Tag {
    robot,
    human,
    alien,
};

class Entity {
    public:
        static Entity   create(const std::string& str);
        void set_union(const int value);
        void set_union(const char value);
        void set_union(const std::string value);
        void set_union(const double value);
        void print_union_type() const noexcept;
        void print_union_value() const noexcept;

        int& get_id();
        char& get_letter();
        double& get_wavelength();
        Tag& current_type();

        const int& get_id() const;
        const char& get_letter() const;
        const double& get_wavelength() const;
        const Tag& current_type() const;

        friend std::ostream& operator<<(std::ostream& os, const Entity& e);

    private:
        explicit Entity(int val)     : id(val), tag(Tag::robot) {}
        explicit Entity(char val)    : letter(val), tag(Tag::human) {}
        explicit Entity(double val)  : wavelength(val), tag(Tag::alien) {}
        union {
            int         id;
            char        letter;
            double      wavelength;
        };
        Tag             tag;
};
void print_entities(std::vector<Entity> entities);
std::vector<Entity> read_entities(std::string file_name);
#endif
