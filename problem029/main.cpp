#include <iostream>
#include <vector>
#include <algorithm>
#include "../common/biginteger.h"

int main()
{
    constexpr unsigned long int max = 100;
    std::vector<BigInteger> num;

    num.reserve((max - 1) * (max - 1));
    for (unsigned long int a = 2; a <= max; ++a) {
        for (unsigned long int b = 2; b <= max; ++b) {
            num.emplace_back(pow(a, b));
        }
    }

    std::sort(num.begin(), num.end());
    num.erase(std::unique(num.begin(), num.end()), num.end());

    std::cout << "result: " << num.size() << '\n';
}
