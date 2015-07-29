#include <iostream>
#include <algorithm>

int foo(const int p)
{
    int result = 0;
    for (int a = 1; a < p; ++a) {
        const int a2 = a * a;
        for (int b = a; b < p; ++b) {
            const int b2 = b * b;
            const int c = p - a - b;
            if (c <= 0)
                break;
            if (a2 + b2 == c*c) {
                ++result;
            }
        }
    }
    return result;
}

int main()
{
    int max = 0;
    int result = 0;
    for (int p = 1; p <= 1000; ++p) {
        const auto r = foo(p);
        if (r > max) {
            max = r;
            result = p;
        }
    }
    std::cout << "result: " << result << '\n';
}
