#include <algorithm>
#include <boost/tokenizer.hpp>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <memory>
#include <string>

std::vector<std::uint64_t> triangle_numbers{1, 3, 6};

std::string readIn()
{
    std::ifstream is("words.txt", std::ifstream::binary);
    if (!is)
        abort();

    is.seekg(0, std::ifstream::end);
    const unsigned long int size = static_cast<unsigned long int>(is.tellg());
    is.seekg(0, std::ifstream::beg);

    std::unique_ptr<char[]> data{new char[size + 1]};
    is.read(data.get(), static_cast<long int>(size));
    data[size] = '\0';

    return std::string(data.get());
}

void createTriangleNumbers(unsigned long long int to)
{
    unsigned long int n = triangle_numbers.size();
    while (triangle_numbers.back() < to)
        triangle_numbers.emplace_back(triangle_numbers.back() + ++n);
}

bool isTriangleNumber(unsigned long long int num)
{
    if (triangle_numbers.back() < num) {
        createTriangleNumbers(num);
    }
    const auto it = std::lower_bound(triangle_numbers.begin(), triangle_numbers.end(), num);
    return *it == num;
}

unsigned long int getSum(const std::string& s)
{
    unsigned long int result = 0;
    for (std::size_t i = 0, end = s.size(); i != end; ++i)
        result += static_cast<unsigned long int>(s[i] - ('A' - 1));
    return result;
}

int main()
{
    auto data = readIn();

    boost::char_separator<char> sep(",\"");
    boost::tokenizer<boost::char_separator<char>> tok(data, sep);

    std::vector<std::string> words;
    for (const auto& word : tok) {
        words.emplace_back(word);
    }

    unsigned int result = 0;
    for (const auto& word : words) {
        const auto sum = getSum(word);
        if (isTriangleNumber(sum))
            ++result;
    }
    std::cout << "result: " << result << '\n';
}

