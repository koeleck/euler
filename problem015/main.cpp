#include <iostream>
#include <cstring>


constexpr int grid_size = 20;
//constexpr int grid_size = 2;

unsigned long int num_steps[grid_size + 1][grid_size + 1];

unsigned long int foo(int x, int y)
{
    if (x == grid_size && y == grid_size)
        return 1;

    if (num_steps[x][y] == 0) {
        unsigned long int result = 0;
        if (x < grid_size)
            result += foo(x + 1, y);
        if (y < grid_size)
            result += foo(x, y + 1);
        num_steps[x][y] = result;
    }
    return num_steps[x][y];
}

int main()
{
    std::memset(num_steps, 0, grid_size * grid_size * sizeof(decltype(num_steps[0][0])));
    std::cout << "result: " << foo(0, 0) << '\n';
}
