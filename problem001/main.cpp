#include <iostream>
#include "../common/range.h"

int main()
{
    int sum = 0;
    for (const auto i : range(0, 1000))
        if ((i % 3 == 0) || (i % 5 == 0))
            sum += i;
    std::cout << "result: " << sum << '\n';
}
