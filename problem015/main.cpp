#include <iostream>
#include <future>


unsigned long int foo(int x, int y)
{
    constexpr int grid_size = 20;
    constexpr int len = grid_size;

    if (x == len && y == len)
        return 1;

    unsigned long int result = 0;
    if (x < 2 && y < 2) {
        int num_futures = 0;
        std::future<unsigned long int> res[2];
        if (x < len)
            res[num_futures++] = std::async(std::launch::async, foo, x + 1, y);
        if (y < len)
            res[num_futures] = std::async(std::launch::async, foo, x, y + 1);
        for (int i = 0; i < num_futures; ++i)
            result += res[i].get();
    } else {
        if (x < len)
            result += foo(x + 1, y);
        if (y < len)
            result += foo(x, y + 1);
    }
    return result;
}

int main()
{
    std::cout << "result: " << foo(0, 0) << '\n';
}
