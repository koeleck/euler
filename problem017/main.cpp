#include <iostream>
#include <cassert>
#include <string>

constexpr const char* numerals[] = {
    "zero", "one", "two", "three",
    "four", "five", "six", "seven", "eight", "nine",
    "ten", "eleven", "twelve", "thirteen", "fourteen",
    "fifteen", "sixteen", "seventeen", "eighteen",
    "nineteen", "twenty", "thirty", "forty", "fifty",
    "sixty", "seventy", "eighty", "ninety"};


void toStringHelper(std::string& result, const int value, const bool isBig = false)
{
    assert(value < 1000000);
    auto num = value;
    if (num >= 1000) {
        toStringHelper(result, value / 1000, false);
        result.append(" thousand");

        num %= 1000;
        if (num != 0) {
            result.push_back(' ');
            toStringHelper(result, num, true);
        }
    } else if (num > 99) {
        result.append(numerals[num / 100]);
        result.append(" hundred");
        num %= 100;
        if (num != 0) {
            result.push_back(' ');
            toStringHelper(result, num, true);
        }
    } else if (num > 20) {
        if (isBig)
            result.append("and ");
        result.append(numerals[20 + (num - 20) / 10]);
        const auto rem = num % 10;
        if (rem != 0) {
            result.push_back('-');
            toStringHelper(result, rem, false);
        }
    } else {
        if (isBig)
            result.append("and ");
        result.append(numerals[num]);
    }
}

std::string toString(const int value)
{
    std::string result;
    toStringHelper(result, value);
    return result;
}

int count(const int value)
{
    const auto str = toString(value);
    int result = 0;
    for (auto c : str) {
        if (c != ' ' && c != '-')
            ++result;
    }
    return result;
}

int main()
{
    int result = 0;
    for (int i = 1; i <= 1000; ++i) {
        result += count(i);
    }
    std::cout << "result: " << result << '\n';
}
