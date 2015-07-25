#include <iostream>
#include <algorithm>
#include <string>

int main()
{
    std::string str = "0123456789";
    constexpr int num_perm = 1000000;
    for (unsigned int i = 0; i < num_perm - 1; ++i)
        std::next_permutation(str.begin(), str.end());
    std::cout << "result: " << str << '\n';
}
