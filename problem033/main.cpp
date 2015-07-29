#include <iostream>
#include <array>
#include "../common/misc.h"
#include "../common/fraction.h"

std::array<int, 2> getDigits(int value)
{
    return std::array<int, 2>{{value / 10, value % 10}};
}

bool foo(const fraction& frac, fraction& result)
{
    const auto num = getDigits(frac.numerator);
    const auto denom = getDigits(frac.denominator);

    for (std::size_t i = 0; i < 2; ++i) {
        for (std::size_t j = 0; j < 2; ++j) {
            if (num[i] == denom[j]) {
                const fraction f(num[i ^ 0x01], denom[j ^ 0x01]);
                if (f == frac) {
                    result = f;
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    fraction result(1, 1);
    for (int denominator = 11; denominator < 100; ++denominator) {
        if (denominator % 10 == 0)
            continue;
        for (int numerator = 10; numerator < denominator; ++numerator) {
            if (numerator % 10 == 0)
                continue;
            const fraction frac(numerator, denominator);
            fraction t;
            if (foo(frac, t)) {
                std::cout << frac.numerator << "/" << frac.denominator << " = "
                        << t.numerator << "/" << t.denominator << '\n';
                result.numerator *= t.numerator;
                result.denominator *= t.denominator;
            }
        }
    }
    const auto s = simplify(result);
    std::cout << result.numerator << '/' << result.denominator  << " -> " << s.numerator << '/' << s.denominator << '\n';
}
