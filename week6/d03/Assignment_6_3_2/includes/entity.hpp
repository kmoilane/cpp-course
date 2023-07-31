#ifndef ENTITY_HPP
#define ENTITY_HPP

enum class Tag {
    robot,
    human,
    alien,
};

class Entity {
    public:
        void            set_union(const int value);
        void            set_union(const char value);
        void            set_union(const double value);
        void            print_union_type() const noexcept;
        void            print_union_value() const noexcept;

        int&            get_id();
        char&           get_letter();
        double&         get_wavelength();
        Tag&            current_type();

        const int&      get_id() const;
        const char&     get_letter() const;
        const double&   get_wavelength() const;
        const Tag&      current_type() const;

    private:
        union {
            int         id;
            char        letter;
            double      wavelength;
        };
        Tag             tag;
};

#endif
