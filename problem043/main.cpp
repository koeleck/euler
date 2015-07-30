#include <iostream>
#include "../common/biginteger.h"

bool isPandigital(std::uint64_t num)
{
    if (num == 0)
        return false;
    unsigned int result = 0;

    while (num != 0) {
        const auto digit = num % 10;
        num /= 10;
        unsigned int mask = 1<<digit;
        if ((result & mask) != 0)
            return false;
        result |= mask;
    }
    return result == 0b1111111111u;
}

bool check(unsigned long int val)
{
    unsigned int div[] = {17, 13, 11, 7, 5, 3, 2};

    for (int i = 0; i < 7; ++i) {
        unsigned long int tmp = val % 1000;
        val /= 10;
        if (tmp % div[i] != 0)
            return false;
    }
    return true;
}

int main()
{
    BigInteger result(0ul);
    for (unsigned long int i = 1023456789; i <= 9876543210; ++i) {
        if (!isPandigital(i) || !check(i))
            continue;
        std::cout << i << '\n';
        result += i;
    }
    std::cout << "result: " << static_cast<std::string>(result) << '\n';
}
