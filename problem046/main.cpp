#include <iostream>
#include <cmath>
#include <algorithm>
#include "../common/primes.h"

std::vector<unsigned long long int> primes;

bool check(const unsigned long long int value)
{
    const auto start = std::lower_bound(primes.begin(), primes.end(), value);
    auto it = std::vector<unsigned long long int>::reverse_iterator(start);

    for (; it != primes.rend(); ++it) {
        const auto prime = *it;
        auto rem = value - prime;
        if (rem % 2 != 0)
            continue;
        rem /= 2;
        const auto o = static_cast<unsigned long long int>(std::round(std::sqrt(rem)));
        if (o*o == rem)
            return true;
    }
    return false;
}

int main()
{
    constexpr unsigned long long int m = 9999999;
    primes = getPrimes(m);

    const std::size_t s = primes.size();
    unsigned long long int p0;
    unsigned long long int p1 = primes[0];
    unsigned int next = 1;

    do {
        p0 = p1;
        p1 = primes[next++];
        for (unsigned long long int i = p0 + 2; i < p1; i += 2) {
            if (!check(i)) {
                std::cout << "result: " << i << '\n';
                return 0;
            }
        }
    } while (next < s);
    std::cout << "not found!\n";
}
