#include <iostream>

bool isPalindrome(const unsigned long int value)
{
    unsigned long int tmp = value;
    unsigned long int test = 0;

    while (tmp > 0) {
        test = test * 10 + (tmp % 10);
        tmp /= 10;
    }
    return test == value;
}

int main()
{
    unsigned long result = 0;
    for (unsigned long i = 100; i < 1000; ++i) {
        for (unsigned long j = i; j < 1000; ++j) {
            const auto val = i * j;
            if (isPalindrome(val) && val > result)
                result = val;
        }
    }
    std::cout << "result: " << result << '\n';
}

