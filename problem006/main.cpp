#include <iostream>

int main()
{
    unsigned long long sum0 = 0;
    unsigned long long sum1 = 0;
    for (unsigned long long i = 1; i <= 100; ++i) {
        sum0 += i * i;
        sum1 += i;
    }

    std::cout << "result: " << (sum1 * sum1 - sum0) << '\n';
}
