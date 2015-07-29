#include <iostream>
#include <algorithm>
#include <cstdint>
#include <vector>


std::uint64_t concat(const std::uint64_t n0, const std::uint32_t n1)
{
    std::uint64_t fac = 1;
    std::uint32_t tmp = n1;
    while (tmp != 0) {
        tmp /= 10;
        fac *= 10;
    }
    return n0 * fac + n1;
}

enum BlaBlaBla
{
    PANDIGITAL,
    DIGITS_MISSING,
    FUCK
};
BlaBlaBla isPandigital(std::uint64_t num)
{
    unsigned int result = 0;

    while (num != 0) {
        const auto digit = num % 10;
        num /= 10;
        unsigned int mask = 1<<digit;
        if ((digit == 0) || ((result & mask) != 0))
            return FUCK;
        result |= mask;
    }
    return (result == 0b1111111110u) ? PANDIGITAL : DIGITS_MISSING;
}

std::uint64_t concat(const std::vector<std::uint32_t>& nums)
{
    std::uint64_t result = 0;
    for (const auto n : nums)
        result = concat(result, n);
    return result;
}

int main()
{
    std::vector<std::uint32_t> prods;
    constexpr int max = 987654321;

    std::uint64_t result = 0;
    for (int i = 1; i <= max; ++i) {
        prods.emplace_back(i);
        for (int n = 2; ; ++n) {
            prods.emplace_back(n * i);
            const auto num = concat(prods);
            const auto res = isPandigital(num);
            if (res == PANDIGITAL) {
                result = std::max(result, num);
            } else if (res == FUCK) {
                break;
            }
        }

        prods.clear();
    }
    std::cout << "result: " << result << '\n';
}
