#ifndef TYPECHECK_HPP
#define TYPECHECK_HPP

namespace ex1 {
    template <typename T, typename U>
    constexpr bool is_same_type(const T&, const U&) noexcept
    {
        return false;
    }

    template <typename T>
    constexpr bool is_same_type(const T&, const T&) noexcept
    {
        return true;
    }
}

#endif
