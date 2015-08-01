#include <iostream>
#include <cmath>
#include "../common/primes.h"

std::vector<unsigned long long int> primes;

bool check(unsigned long long int value)
{
    for (const auto prime : primes) {
        if (prime > value)
            break;

        const auto rem = value - prime / 2;

        const auto o = std::sqrt(rem);

        if (prime + 2 * o * o == value)
            return true;
    }
    return true;
}

int main()
{
    constexpr unsigned long long int m = 9999999;
    primes = getPrimes(m);

    const std::size_t s = primes.size();
    unsigned long long int p0 = primes[0];
    unsigned long long int p1 = primes[1];
    unsigned int next = 2;

    do {
        for (unsigned long long int i = p0 + 2; i < p1; i += 2) {
            if (!check(i)) {
                std::cout << "result: " << i << '\n';
                return 0;
            }
        }
        p0 = p1;
        p1 = primes[next++];
    } while (next < s);
    std::cout << "not found!\n";
}
