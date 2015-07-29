#include <iostream>
#include <array>
#include <algorithm>
#include <unordered_set>

unsigned long long int getValue(const std::array<unsigned int, 9>& digits, int start, int len)
{
    unsigned long long int result = 0;
    for (int i = start; i < start + len; ++i) {
        result = result * 10 + digits[static_cast<std::size_t>(i)];
    }
    return result;
}

int main()
{
    std::array<unsigned int, 9> digits{{1, 2, 3, 4, 5, 6, 7, 8, 9}};
    std::unordered_set<unsigned long long int> found;

    unsigned long long int result = 0;
    do {
        for (int len0 = 1; len0 <= 7; ++len0) {
            const auto val0 = getValue(digits, 0, len0);
            for (int len1 = 1; len1 <= 8 - len0; ++len1) {
                const auto val1 = getValue(digits, len0, len1);
                const auto ref = getValue(digits, len0 + len1, 9 - len0 - len1);
                const auto prod = val0 * val1;
                if (prod == ref && found.find(prod) == found.end()) {
                    found.emplace(prod);
                    std::cout << val0 << " x " << val1 << " = " << prod << '\n';
                    result += prod;
                }
            }
        }
    } while (std::next_permutation(digits.begin(), digits.end()));
    std::cout << "result: " << result << '\n';
}
