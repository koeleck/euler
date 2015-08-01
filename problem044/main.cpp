#include <iostream>
#include <limits>
#include <algorithm>
#include <vector>

std::vector<unsigned long long int> numbers;

void createNumbers(unsigned int count)
{
    numbers.reserve(count);
    numbers.emplace_back(1);

    for (unsigned long long int n = 1; n < count; ++n) {
        const auto tmp = numbers.back();
        numbers.emplace_back(tmp + 3 * n + 1);
        if (numbers.back() < tmp) {
            std::cerr << "fuck!\n";
            abort();
        }
    }
}

bool isPentagonal(unsigned long long int value)
{
    const auto it = std::lower_bound(numbers.begin(), numbers.end(), value);
    if (it == numbers.end())
        return false;
    if (*it > numbers.back()) {
        std::cerr << "need more numbers!\n";
        return false;
    }
    return *it == value;
}

int main()
{
    constexpr unsigned int num_numbers = 9999;
    createNumbers(num_numbers);

    unsigned long long int result = std::numeric_limits<unsigned long long int>::max();
    for (unsigned int i = 0; i < num_numbers - 1; ++i) {
        for (unsigned int j = i + 1; j < num_numbers; ++j) {
            const auto n0 = numbers[i];
            const auto n1 = numbers[j];
            if (isPentagonal(n0 + n1)) {
                const auto diff = n1 - n0;
                if (diff > result)
                    continue;
                if (isPentagonal(diff))
                    result = diff;
            }
        }
    }
    std::cout << "result: " << result << '\n';
}
