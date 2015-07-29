#ifndef EULER_COMMON_MATH_H
#define EULER_COMMON_MATH_H

#include <type_traits>
#include <cmath>
#include <cassert>

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

template <typename T>
T gcd(T a, T b)
{
    assert(a > static_cast<T>(0) && b > static_cast<T>(0));
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    return a;
}

template <typename T>
T factorial(T n)
{
    assert(n >= static_cast<T>(0));
    T result = 1;
    while (n > 1) {
        result *= n;
        --n;
    }
    return result;
}

#endif // EULER_COMMON_MATH_H
