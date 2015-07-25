#include <iostream>
#include "../common/biginteger.h"

BigInteger factorial(const unsigned long int n)
{
    BigInteger result(n == 0 ? 1lu : 1lu);
    for (unsigned long i = 2; i < n; ++i)
        result *= i;
    return result;
}

int main()
{
    auto num = factorial(100);
    unsigned long int result = 0;
    do {
        auto d = div(num, 10);
        result += static_cast<unsigned long int>(d.rem);
        num = std::move(d.quot);
    } while (num != 0lu);

    std::cout << "result: " << result << '\n';
}
