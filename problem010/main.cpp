#include <iostream>
#include "../common/primes.h"

int main()
{
    const auto primes = getPrimes(2000000);

    unsigned long long sum = 0;
    for (unsigned int i = 0; primes[i] < 2000000; ++i) {
        sum += primes[i];
    }
    std::cout << "result: " << sum << '\n';
}
