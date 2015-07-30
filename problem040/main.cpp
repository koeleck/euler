#include <iostream>
#include <string>
#include <sstream>

std::string createNumber(const int min_num_digits)
{

    std::ostringstream out;

    int digit = 1;
    int prefix = 0;
    for (int i = 0; i < min_num_digits; ++i) {
        if (prefix > 0)
            out << prefix;
        out << digit++;
        if (digit == 10) {
            digit = 0;
            ++prefix;
        }
    }

    return out.str();
}

int main()
{
    const auto num = createNumber(1000000);

    auto getDigit = [&num] (unsigned long int d) -> int
    {
        return static_cast<int>(num[d - 1] - '0');
    };

    int result = 1;
    for (unsigned long int d = 1; d <= 1000000; d *= 10)
        result *= getDigit(d);

    std::cout << "result: " << result << '\n';
}
