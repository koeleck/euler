#include <iostream>

constexpr int coin[] = {1, 2, 5, 10, 20, 50, 100, 200};
constexpr int num_coins = sizeof(coin) / sizeof(decltype(coin[0]));

int foo(const int value, const int start)
{
    if (value == 200)
        return 1;

    int result = 0;
    for (int i = start; i < num_coins; ++i) {
        const auto tmp = value + coin[i];
        if (tmp > 200)
            continue;
        result += foo(tmp, i);
    }
    return result;
}

int main()
{
    std::cout << "result: " << foo(0, 0) << '\n';
}
