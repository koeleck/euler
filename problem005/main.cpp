#include <iostream>
#include <limits>

int main()
{
    for (unsigned long i = 2520; i < std::numeric_limits<unsigned long>::max(); ++i) {
        bool found = true;
        for (unsigned long j = 2; j <= 20; ++j) {
            if (i % j != 0) {
                found = false;
                break;
            }
        }
        if (found) {
            std::cout << "result: " << i << '\n';
            break;
        }
    }
}
