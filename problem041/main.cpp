#include <iostream>
#include "../common/primes.h"

bool isPandigital(std::uint64_t num)
{
    if (num == 0)
        return false;
    unsigned int result = 0;

    int num_digits = 0;
    while (num != 0) {
        ++num_digits;
        const auto digit = num % 10;
        if (digit == 0)
            return false;
        num /= 10;
        unsigned int mask = 1<<(digit - 1);
        if ((result & mask) != 0)
            return false;
        result |= mask;
    }
    unsigned int check_mask = 1;
    for (int i = 1; i < num_digits; ++i)
        check_mask |= 1<<i;
    return result == check_mask;
}

int main()
{
    const auto primes = getPrimes(987654321);

    unsigned long long int max = 0;
    for (const auto prime : primes) {
        if (isPandigital(prime)) {
            std::cout << prime << '\n';
            max = prime;
        }
    }
    std::cout << "result: " << max << '\n';
}
