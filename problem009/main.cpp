#include <iostream>

int main()
{
    for (int a = 1; a < 499; ++a) {
        for (int b = a + 1; b < 500; ++b) {
            const int c = 1000 - a - b;
            if (a*a + b*b == c*c) {
                std::cout << "a = " << a << ", b = " << b << ", c = " << c << '\n';
                std::cout << "result: " << a * b * c << '\n';
            }
        }
    }
}
