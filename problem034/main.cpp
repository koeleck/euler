#include <iostream>

#include "../common/misc.h"
#include "../common/digits.h"

int main()
{
    unsigned int result = 0;
    for (unsigned int i = 3; i < 999999; ++i) {
        unsigned int sum = 0;
        for (const auto d : digits(i)) {
            sum += factorial(d);
            if (sum > i)
                break;
        }
        if (sum == i) {
            std::cout << i << '\n';
            result += i;
        }
    }
    std::cout << "result: " << result << '\n';
}
