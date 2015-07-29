#include <iostream>
#include "../common/digits.h"
#include "../common/primes.h"

int main()
{
    constexpr unsigned long int max = 1000000;
    const auto primes = getPrimes(max);

    int result = 0;
    for (auto prime : primes) {
        if (prime >= max)
            break;

        auto digits = getDigits(prime);
        bool success = true;

        for (std::size_t i = 0; i < digits.size() - 1; ++i) {
            std::rotate(digits.begin(), digits.begin() + 1, digits.end());

            unsigned int val = digitsToNum<unsigned int>(digits);

            if (!isPrime(primes, val)) {
                success = false;
                break;
            }
        }
        if (success) {
            ++result;
            std::cout << prime << '\n';
        }
    }
    std::cout << "result: " << result << '\n';
}
