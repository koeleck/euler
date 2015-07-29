#ifndef EULER_COMMON_MATH_H
#define EULER_COMMON_MATH_H

#include <type_traits>
#include <cmath>

template <typename T, typename P>
typename std::enable_if<std::is_integral<P>::value, T>::type
pow(T base, P exp)
{
    T result = static_cast<T>(1);
    if (exp < static_cast<P>(0)) {
        exp = -exp;
        base = static_cast<T>(1) / base;
    }
    for (P i = static_cast<P>(0); i < exp; ++i)
        result *= base;
    return result;
}

#endif // EULER_COMMON_MATH_H
