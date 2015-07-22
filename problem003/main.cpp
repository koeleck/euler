#include "../common/primes.h"
#include <iostream>

int main()
{
    const auto primes = getPrimes(4000000);

    const unsigned long long num = 600851475143;

    unsigned long long res = 0;
    for (const auto prime : primes) {
        if (num % prime == 0) {
            res = prime;
        }
    }

    std::cout << "result: " << res << '\n';
}
