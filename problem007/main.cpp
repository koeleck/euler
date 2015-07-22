#include "../common/primes.h"
#include <iostream>

int main()
{
    const auto primes = getPrimes(4000000);
    if (primes.size() < 10001) {
        std::cerr << "need more primes\n";
        return 1;
    }
    std::cout << "result: " << primes[10000] << '\n';
}
