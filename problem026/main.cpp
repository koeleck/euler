#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>

int test(const unsigned int val)
{
    unsigned int numerator = 10;
    unsigned int denominator = val;

    std::vector<int> v;
    v.resize(10 * val + 1, -1);

    //std::ostringstream out;
    //out << "0.";
    int pos = 2;
    int periodic = -1;
    do {
        if (v.at(numerator) != -1) {
            periodic = v[numerator];
            break;
        }
        const auto quot = numerator / denominator;
        const auto rem = numerator % denominator;
        //out << quot;

        v[numerator] = pos++;

        numerator = 10 * rem;
    } while (numerator != 0);

    //std::string result = out.str();
    //if (periodic != -1) {
    //    result.insert(result.begin() + periodic, '(');
    //    result.push_back(')');
    //}
    //std::cout << result;
    //if (periodic != -1)
    //    std::cout << " :: " << (pos - periodic);
    //std::cout << '\n';
    if (periodic == -1)
        return 0;
    return pos - periodic;
}

int main()
{
    int result = 0;
    unsigned int num = 0;
    for (unsigned int i = 2; i < 1000; ++i) {
        const auto v = test(i);
        if (v > result) {
            result = v;
            num = i;
        }
    }
    std::cout << "result: " << num << " (" << result << ")\n";
}
