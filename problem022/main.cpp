#include <iostream>
#include <fstream>
#include <boost/tokenizer.hpp>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>

std::string readIn()
{
    std::ifstream is("names.txt", std::ifstream::binary);
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

int main()
{
    auto data = readIn();

    boost::char_separator<char> sep(",\"");
    boost::tokenizer<boost::char_separator<char>> tok(data, sep);

    std::vector<std::string> names;
    for (const auto& name : tok) {
        names.emplace_back(name);
    }

    std::sort(names.begin(), names.end());

    unsigned long long int result = 0;
    for (std::size_t i = 0; i < names.size(); ++i) {
        unsigned int sum = 0;
        for (auto c : names[i])
            sum += static_cast<unsigned int>(c - 'A' + 1);
        const auto score = (i + 1) * sum;
        result += score;
    }
    std::cout << "result: " << result << '\n';
}
