#include <iostream>
#include <iomanip>
#include <array>

template <std::size_t SIZE>
auto gen() -> std::array<std::array<unsigned long int, SIZE>, SIZE>
{
    static_assert((SIZE - 1) % 2 == 0, "");
    constexpr int end = SIZE * SIZE;
    std::array<std::array<unsigned long int, SIZE>, SIZE> result;

    int pos_x = SIZE / 2;
    int pos_y = SIZE / 2;
    int dir_x = 1;
    int dir_y = 0;
    int len = 0;
    int max_len = 1;
    int value = 1;
    int cycle = 1;

    do {
        result[pos_y][pos_x] = value++;
        if (len++ == max_len) {
            const int tmp = dir_y;
            dir_y = dir_x;
            dir_x = -tmp;
            if (cycle++ % 2 == 0)
                max_len += 1;
            len = 1;
        }
        pos_x += dir_x;
        pos_y += dir_y;

    } while (value <= end);

    return result;
}

int main()
{
    constexpr int size = 1001;
    const auto grid = gen<size>();

    unsigned long int result = 0;
    for (unsigned int i = 0; i < size; ++i) {
        result += grid[i][i];
        result += grid[size - 1 - i][i];
    }
    result -= 1;
    std::cout << "result: " << result << '\n';
}
