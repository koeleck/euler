#include <iostream>
#include "../common/biginteger.h"

int main()
{
    constexpr int base = 2;
    constexpr int exp = 1000;

    BigInteger num = pow(base, exp);
    BigInteger sum;
    std::cout << "num: " << static_cast<std::string>(num) << '\n';
    do {
        auto result = div(num, 10);
        sum += result.rem;
        num = std::move(result.quot);
        if (num == 0ul)
            break;
    } while (true);
    std::cout << "result: " << static_cast<std::string>(sum) << '\n';
}
