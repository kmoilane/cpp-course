#include <iostream>
#include <cstdint>
#include <type_traits>
#include <vector>

constexpr static uint8_t IS_FUZZY            = 0b1;
constexpr static uint8_t IS_LARGE            = 0b10;
constexpr static uint8_t HAS_GOOGLY_EYES     = 0b100;
constexpr static uint8_t IS_CUTE             = 0b1000;
constexpr static uint8_t HAS_TEETH           = 0b10000;
constexpr static uint8_t IS_ABOUT_TO_EAT_YOU = 0b100000;
constexpr static uint8_t IS_FRIENDLY         = 0b1000000;
constexpr static uint8_t IS_SPIDER           = 0b10000000;

template <typename T>
void print_bits(const T& value)
{
    using decay_type = std::decay_t<T>;

    std::cout << "0b";
    for (int i = sizeof(decay_type) * 8 - 1; i >= 0; --i)
    {
        std::cout << ((value & (1ULL << i)) ? 1 : 0);
    }

    std::cout << '\n';
}

template <typename T>
bool nth_is_set(const T& value, int nth)
{
    return (value & (1 << nth));
}

template <typename T>
T byte_swap(const T& value)
{
    static_assert(std::is_integral_v<std::decay_t<T>>, "Type needs to be intergal!\n");
    using decay_type = std::decay_t<T>;
    size_t size = sizeof(decay_type);
    if (size == 1)
        return value;
    T result {0};
    for (size_t i = 0; i < size; i++)
    {
        result = result | ((value >> (i * 8)& 0xFF) << (size - 1 - i) * 8);
    }

    return result;
}

struct Flagset
{
    uint8_t flags;

    Flagset& operator=(uint8_t flag)
    {
        flags |= flag;
        return *this;
    }
    Flagset& operator|=(uint8_t flag)
    {
        flags |= flag;
        return *this;
    }
    bool operator^(uint8_t flag) const
    {
        return (flags ^ flag) == 0;
    }

    bool operator&(uint8_t flag) const
    {
        return (flags & flag) != 0;
    }
    friend std::ostream& operator<<(std::ostream& os, const Flagset& set)
    {
        if (set & IS_FUZZY)
            os << "IS_FUZZY | ";
        if (set & IS_LARGE)
            os << "IS_LARGE | ";
        if (set & HAS_GOOGLY_EYES)
            os << "HAS_GOOGLY_EYES | ";
        if (set & IS_CUTE)
            os << "IS_CUTE | ";
        if (set & HAS_TEETH)
            os << "HAS_TEETH | ";
        if (set & IS_ABOUT_TO_EAT_YOU)
            os << "IS_ABOUT_TO_EAT_YOU | ";
        if (set & IS_FRIENDLY)
            os << "IS_FRIENDLY | ";
        if (set & IS_SPIDER)
            os << "IS_SPIDER | ";
        os << '\n';
        return os;
    }
    static void possibly_bear(const Flagset& set)
    {
        if ((set ^ (IS_FUZZY | IS_LARGE | HAS_TEETH | IS_ABOUT_TO_EAT_YOU)) != 0)
        {
            std::cout << "I think it might be a bear... RUN!!!\n";
        }
        else
            std::cout << "Hmmm, I don't think it's a bear...\n";
    }
    static void somekind_of_spider(const Flagset& set)
    {
        if (set & IS_SPIDER)
            std::cout << "It seems to be somekind of a spider...\n";
        else
            std::cout << "I can tell you that it's not a spider!\n";
    }
    static void possibly_petable(const Flagset& set)
    {
        if (set & (IS_FUZZY | IS_CUTE | IS_FRIENDLY) && ((set & IS_ABOUT_TO_EAT_YOU) == 0))
        {
            std::cout << "It's fuzzy, cute and friendly and not about to eat you.\n";
            std::cout << "Therefore I think you can pet it!\n";
        }
        else
            std::cout << "I would think twice before trying to pet it!\n";
    }
};

int main()
{
    std::cout << "\033[1;34mExercise1:\033[0m\n";
    uint8_t val = 42;
    print_bits(val);
    std::cout << std::boolalpha;
    for (int i = 0; i < 8; i++)
    {
        std::cout << i << " bit is set: " << nth_is_set(val, i) << '\n';
    }

    std::cout << "\033[1;34mExercise2:\033[0m\n";
    std::cout << std::hex;
    uint32_t a = 0xabcdefda;
    std::cout << a << '\n';
    uint32_t b = byte_swap(a);
    std::cout << b << '\n';

    std::cout << "\033[1;34mExercise3:\033[0m\n";
    Flagset flagset1;
    std::cout << "flagset1: ";
    flagset1 = IS_FUZZY | IS_LARGE | HAS_TEETH | IS_ABOUT_TO_EAT_YOU;
    std::cout << flagset1;
    Flagset flagset2;
    std::cout << "flagset2: ";
    flagset2 = IS_FUZZY | IS_LARGE | HAS_GOOGLY_EYES | IS_CUTE;
    std::cout << flagset2;
    flagset2 |= IS_SPIDER;
    std::cout << "flagset2: ";
    std::cout << flagset2;
    
    std::cout << "\033[1;34mExercise4:\033[0m\n";
    std::cout << "flagset1: ";
    Flagset::possibly_bear(flagset1);
    std::cout << "flagset2: ";
    Flagset::possibly_bear(flagset2);
    std::cout << "flagset1: ";
    Flagset::somekind_of_spider(flagset1);
    std::cout << "flagset2: ";
    Flagset::somekind_of_spider(flagset2);
    Flagset::possibly_petable({IS_FUZZY | IS_CUTE | IS_FRIENDLY});
    Flagset::possibly_petable({IS_FUZZY | IS_CUTE | IS_FRIENDLY | IS_ABOUT_TO_EAT_YOU});
    return 0;
}
