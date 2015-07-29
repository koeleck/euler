#ifndef EULER_COMMON_FRACTION_H
#define EULER_COMMON_FRACTION_H

#include "misc.h"

struct fraction
{
    fraction() {}
    fraction(int num, int denom) noexcept : numerator{num}, denominator{denom} {}
    int numerator;
    int denominator;
};

bool operator==(const fraction& f0, const fraction& f1) noexcept
{
    return static_cast<unsigned long long int>(f0.numerator) * static_cast<unsigned long long int>(f1.denominator) ==
           static_cast<unsigned long long int>(f1.numerator) * static_cast<unsigned long long int>(f0.denominator);
}


fraction simplify(const fraction& frac)
{
    fraction result = frac;

    do {
        const auto v = gcd(result.numerator, result.denominator);
        if (v == 1)
            break;
        result.numerator /= v;
        result.denominator /= v;
    } while (true);
    return result;
}


#endif // EULER_COMMON_FRACTION_H
