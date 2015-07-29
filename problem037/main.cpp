#include <iostream>
#include "../common/primes.h"
#include "../common/digits.h"

unsigned long long int getNumber(const std::vector<unsigned char>& digits,
                                 const std::size_t start, const std::size_t len)
{
    unsigned long long int result = 0;
    std::size_t i = len;
    while (i-- > 0) {
        result = result * 10 + digits[start + i];
    }
    return result;
}

int main()
{
    constexpr auto max = 1000000ull;
    const auto primes = getPrimes(max);

    unsigned long long int sum = 0;
    for (const auto prime : primes) {
        if (prime < 10)
            continue;
        auto digits = getDigits(prime);
        const auto size = digits.size();

        bool success = true;
        for (std::size_t i = 1; i < size; ++i) {
            const auto n0 = getNumber(digits, 0, i);
            if (!isPrime(primes, n0)) {
                success = false;
                break;
            }
            const auto n1 = getNumber(digits, i, size - i);
            if (!isPrime(primes, n1)) {
                success = false;
                break;
            }
        }
        if (success) {
            std::cout << prime << '\n';
            sum += prime;
        }
    }
    std::cout << "result: " << sum << '\n';
}
