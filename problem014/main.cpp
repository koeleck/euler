#include <iostream>
#include <thread>
#include <mutex>

unsigned long long int result = 0;
unsigned long long int length = 0;

constexpr unsigned long long int max = 1000000;
std::mutex write_lock;

void worker(unsigned long long int num, unsigned char step)
{
    unsigned long long int local_result = 0;
    unsigned long long int local_len = 0;
    for (; num < max; num += step) {
        unsigned long long value = num;
        unsigned long long len = 1;
        do {
            ++len;
            if (value % 2 == 0)
                value = value / 2;
            else
                value = 3 * value + 1;
        } while (value != 1);

        if (len > local_len) {
            local_len = len;
            local_result = num;
        }
    }

    {
        std::lock_guard<std::mutex> guard(write_lock);
        if (local_len > length) {
            length = local_len;
            result = local_result;
        }
    }
}

int main()
{
    std::thread thread[4] = {std::thread(worker, 2, 4),
                             std::thread(worker, 3, 4),
                             std::thread(worker, 4, 4),
                             std::thread(worker, 5, 4)};
    thread[0].join();
    thread[1].join();
    thread[2].join();
    thread[3].join();

    std::cout << "result: " << result << ", length: " << length << '\n';
}
