#ifndef TYPECHECK_HPP
#define TYPECHECK_HPP

#include <type_traits>

namespace ex1 {
    template <typename T, typename U>
    constexpr bool is_same_type(T, U) noexcept
    {
        return false;
    }

    template <typename T>
    constexpr bool is_same_type(T, T) noexcept
    {
        return true;
    }
}

namespace ex2 {
    template <typename T>
    constexpr bool can_decay() noexcept
    {
        bool res = std::is_same_v<std::decay_t<T>, T>;
        return !res;
    }
}

#endif
