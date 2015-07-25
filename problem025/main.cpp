#include <iostream>
#include "../common/biginteger.h"


int main()
{
    constexpr int num_digits = 1000;
    BigInteger fac = pow(10, num_digits - 1);
    BigInteger v0(1lu);
    BigInteger v1(1lu);

    unsigned long int idx = 2;
    do {
        BigInteger tmp = v0 + v1;
        v0 = std::move(v1);
        v1 = std::move(tmp);
        ++idx;
    } while ((v1 / fac) == 0lu);

    std::cout << "result: " << idx << "\n -> " << static_cast<std::string>(v1) << '\n';
}
