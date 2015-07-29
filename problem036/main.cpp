#include <iostream>

#include "../common/digits.h"

bool isPalindromic(const int num, int base)
{
    if (num < 0)
        return false;
    int val = num;
    int tmp = 0;
    do {
        tmp = tmp * base + (val % base);
        val = val / base;
    } while (val != 0);
    return (tmp == num);
}

bool foo(const int num)
{
    return isPalindromic(num, 10) && isPalindromic(num, 2);
}

int main()
{
    constexpr int max = 1000000;

    long long int result = 0;
    for (int i = 1; i < max; ++i) {
        if (foo(i)) {
            std::cout << i << '\n';
            result += i;
        }
    }
    std::cout << "result: " << result << '\n';
}
