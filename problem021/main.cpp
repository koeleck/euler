#include <iostream>

long int d(const long int n)
{
    long int sum = 0;
    for (long int i = 1; i <= n / 2; ++i) {
        if (n % i == 0)
            sum += i;
    }
    return sum;
}


int main()
{
    long int result = 0;
    for (long int i = 1; i < 10000; ++i) {
        const auto tmp0 = d(i);
        const auto tmp1 = d(tmp0);
        if (i == tmp1 && i != tmp0) {
            std::cout << "amicable: " << i << " -> " << tmp0 << '\n';
            result += i;
        }
    }
    std::cout << "result: " << result << '\n';
}
