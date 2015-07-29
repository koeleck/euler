#include <iostream>
#include <limits>

#include "../common/math.h"

int main()
{
    constexpr int exp = 5;
    constexpr auto max = 200000;
    using value_type = unsigned long int;
    value_type result = 0;
    for (value_type i = 2; i < max; ++i) {
        auto value = i;
        value_type sum = 0;
        do {
            const auto digit = value % 10;
            value = value / 10;
            sum += pow(digit, exp);
            if (sum > i)
                break;
        } while (value != 0);
        if (value == 0 && sum == i) {
            result += i;
            std::cout << "found: " << i << '\n';
        }
    }

    std::cout << "result: " << result << '\n';
}
