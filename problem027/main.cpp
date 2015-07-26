#include <iostream>
#include <algorithm>
#include "../common/primes.h"

const auto primes = getPrimes(1000000);
const auto primes_beg = primes.cbegin();
const auto primes_end = primes.cend();

bool isPrime(long int value)
{
    if (value < 2)
        return false;
    if (static_cast<unsigned long long int>(value) > primes.back()) {
        std::cerr << "need moar primes!!!\n";
        abort();
    }

    const auto it = std::lower_bound(primes_beg, primes_end, value);

    return (it != primes_end && *it == static_cast<unsigned long long int>(value));
}

int foo(const long int a, const long int b)
{
    int result = 0;

    for (long int n = 0; ; ++n) {
        const long int val = n * n + a * n + b;
        if (!isPrime(val))
            break;
        ++result;
    }

    return result;
}

int main()
{
    long int res_a = 0;
    long int res_b = 0;
    int res_max = 0;

    for (long int a = -999; a < 1000; ++a) {
        for (long int b = -999; b < 1000; ++b) {
            const auto n = foo(a, b);
            if (n > res_max) {
                res_max = n;
                res_a = a;
                res_b = b;
            }
        }
    }
    std::cout << "result: " << (res_a * res_b) << '\n';
}
