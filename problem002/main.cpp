#include <iostream>

int main()
{
    unsigned int fib[2] = {1, 2};

    unsigned long long int sum = 0;
    while (fib[1] < 4000000) {
        if (fib[1] % 2 == 0)
            sum += fib[1];
        const auto tmp = fib[0] + fib[1];
        fib[0] = fib[1];
        fib[1] = tmp;
    }
    std::cout << "result: " << sum << '\n';
}
