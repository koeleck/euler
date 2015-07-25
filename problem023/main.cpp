#include <iostream>
#include <vector>
#include <algorithm>

constexpr unsigned long int MAX = 28124;

bool isAbundant(const unsigned long int num)
{
    unsigned long int res = 1;
    for (unsigned long int i = 2; i <= num / 2; ++i)
        if (num % i == 0)
            res += i;
    return num < res;
}

bool check(const unsigned long int num, const std::vector<unsigned long int>& abundant)
{
    const auto begin = abundant.begin();
    const auto end = abundant.end();
    const auto size = abundant.size();
    for (std::size_t i = 0; i < size; ++i) {
        if (abundant[i] >= num)
            break;
        const auto rem = num - abundant[i];
        const auto it = std::lower_bound(begin + static_cast<long>(i), end, rem);
        if (it != end && *it == rem)
            return false;
    }
    return true;
}

int main()
{
    std::vector<unsigned long int> abundant;
    for (unsigned long int i = 12; i < MAX; ++i)
        if (isAbundant(i))
            abundant.emplace_back(i);

    unsigned long int result = 0;
    for (unsigned long int i = 1; i < MAX; ++i)
        if (check(i, abundant))
            result += i;
    std::cout << "result: " << result << '\n';
}
