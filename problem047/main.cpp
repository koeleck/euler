#include <iostream>
#include <cmath>
#include <algorithm>
#include "../common/primes.h"

constexpr unsigned long long int m = 999999;
constexpr unsigned int num_primes = 4;
constexpr unsigned int num_consecutive = 4;

std::vector<unsigned long long int> primes = getPrimes(m);

bool check(unsigned long long int value)
{
    int count = 0;

    for (const auto prime : primes) {
        if (prime > value)
            break;

        bool f = false;
        while (value % prime == 0) {
            f = true;
            value /= prime;
        }
        if (f)
            ++count;
    }

    return count == num_primes;
}

int main()
{
    unsigned int count = 0;
    for (unsigned long long int i = 10; i < m; ++i) {
        if (check(i)) {
            ++count;
            if (count == num_consecutive) {
                std::cout << "result: " << (i - num_consecutive + 1) << '\n';
                return 0;
            }
        } else {
            count = 0;
        }
    }
}
