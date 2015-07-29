#ifndef EULER_COMMON_SIEVE_H
#define EULER_COMMON_SIEVE_H

#include <vector>
#include <algorithm>

#if defined(DEBUG)
#include <iostream>
#endif // DEBUG

std::vector<unsigned long long> getPrimes(unsigned long long to);

bool isPrime(const std::vector<unsigned long long int>& primes, unsigned long long int num)
{
    const auto it = std::lower_bound(primes.begin(), primes.end(), num);
#if defined(DEBUG)
    if (it == primes.end())
        std::cerr << "need more primes!\n";
#endif // DEBUG
    return (it != primes.end()) && (*it == num);
}

#endif // EULER_COMMON_SIEVE_H
