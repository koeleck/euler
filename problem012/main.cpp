#include <iostream>
#include <thread>
#include <atomic>
#include <limits>
#include <mutex>

constexpr int threshold = 500;
std::atomic_ullong result{std::numeric_limits<unsigned long long>::max()};
std::mutex write_lock;

void worker(unsigned long long cnt, unsigned long long num, int num_steps)
{
    do {
        const auto prev = num;
        for (int i = 0; i < num_steps; ++i)
            num += cnt++;
        if (num < prev) {
            std::cerr << "overflow!\n";
            abort();
        }

        int num_div = 2;
        for (unsigned long long i = 2; i <= num / 2; ++i) {
            if (num % i == 0)
                ++num_div;
        }
        if (num_div > threshold)
            break;
    } while (true);

    {
        std::lock_guard<std::mutex> guard(write_lock);
        std::cout << "possible result: " << num << '\n';
    }

    unsigned long long expct = result.load(std::memory_order_relaxed);
    while (!result.compare_exchange_weak(expct, num, std::memory_order_relaxed, std::memory_order_relaxed)) {}
}

int main()
{
    std::thread t0 = std::thread(worker, 2, 1, 4);
    std::thread t1 = std::thread(worker, 3, 3, 4);
    std::thread t2 = std::thread(worker, 4, 6, 4);
    std::thread t3 = std::thread(worker, 5, 10, 4);

    t0.join();
    t1.join();
    t2.join();
    t3.join();

    std::cout << "result: " << result << '\n';
}
