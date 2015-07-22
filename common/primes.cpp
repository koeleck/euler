#include <cassert>
#include <cstdint>
#include <cstring>
#include <cmath>
#include <climits>
#include <memory>

#include "primes.h"

std::vector<unsigned long long> getPrimes(const unsigned long long to)
{
    using element_type = std::uint64_t;
    constexpr auto bpe = sizeof(element_type) * CHAR_BIT;

    std::vector<unsigned long long> result;

    assert(to > 2);

    const auto size = ((to - 1) / 2 + bpe - 1) / bpe;
    const auto num_bits = size * bpe;
    const auto max = 3 + 2 * size * bpe;

    // estimate number of primes:
    result.reserve(static_cast<std::size_t>( 1.01 * max / std::log(max)));

    std::unique_ptr<element_type[]>  bits{new element_type[size]};
    std::memset(bits.get(), 0, size * sizeof(element_type));

    result.emplace_back(2);

    for (unsigned long long i = 0; i < num_bits; ++i) {
        unsigned long long idx = i / bpe;
        unsigned long long bit = i % bpe;

        if ((bits[idx] & (static_cast<element_type>(1)<<bit)) != 0)
            continue;
        const auto num = 3 + 2 * i;
        result.emplace_back(num);

        do {
            bits[idx] |= static_cast<element_type>(1)<<bit;
            bit += num;
            if (bit >= bpe) {
                idx += bit / bpe;
                bit %= bpe;
            }
        } while (idx < size);
    }

    return result;
}
