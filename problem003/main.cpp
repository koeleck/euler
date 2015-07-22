#include "../common/sieve.h"
#include <iostream>
#include <chrono>
#include <deque>

int main()
{
    const auto start = std::chrono::high_resolution_clock::now();
    std::deque<unsigned long long int> primes{2, 3, 5, 7, 9, 11};
    for (unsigned long long int i = 13; i > 11; i += 2) {
        for (const auto& el : primes)
            if (i % el == 0)
                continue;
        primes.emplace_back(i);
        //if (primes.size() % 100 == 0)
        //    std::cout << "primes found: " << primes.size() << '\n';
    }
    const auto end = std::chrono::high_resolution_clock::now();
    std::cout << "took " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms\n";
}
