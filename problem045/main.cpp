#include <iostream>
#include <vector>


std::vector<unsigned long long int> computeTriangleNumbers(const unsigned long long int max)
{
    std::vector<unsigned long long int> result{1};

    unsigned long long int cur = 1;
    for (unsigned long int n = 1; cur < max; ++n) {
        cur = cur + n + 1;
        result.emplace_back(cur);
    }

    return result;
}

std::vector<unsigned long long int> computePentagonalNumbers(const unsigned long long int max)
{
    std::vector<unsigned long long int> result{1};

    unsigned long long int cur = 1;
    for (unsigned long int n = 1; cur < max; ++n) {
        cur = cur + 3 * n + 1;
        result.emplace_back(cur);
    }

    return result;
}

std::vector<unsigned long long int> computeHexagonalNumbers(const unsigned long long int max)
{
    std::vector<unsigned long long int> result{1};

    unsigned long long int cur = 1;
    for (unsigned long int n = 1; cur < max; ++n) {
        cur = cur + 4 * n + 1;
        result.emplace_back(cur);
    }

    return result;
}

bool hasNumber(const std::vector<unsigned long long int>& numbers, const unsigned long long int n)
{
    const auto it = std::lower_bound(numbers.begin(), numbers.end(), n);
    if (it == numbers.end()) {
        std::cerr << "need more numbers\n";
        return false;
    }
    return *it == n;
}

int main()
{
    constexpr unsigned long long int m = 99999999999;
    const auto tri = computeTriangleNumbers(m);
    const auto pent = computePentagonalNumbers(m);
    const auto hex = computeHexagonalNumbers(m);

    auto it = std::lower_bound(tri.begin(), tri.end(), 40755);
    for (++it; it != tri.end(); ++it) {
        const auto t = *it;
        if (hasNumber(pent, t) && hasNumber(hex, t)) {
            std::cout << "result: " << t << '\n';
            return 0;
        }
    }
}
