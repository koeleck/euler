#ifndef EULER_COMMON_RANGE_HELPER_H
#define EULER_COMMON_RANGE_HELPER_H

#include <utility>

template <typename Iterable>
class RangeHelper
{
public:
    template <typename T>
    RangeHelper(T&& begin, T&& end)
      : m_begin{std::forward<T>(begin)}
      , m_end{std::forward<T>(end)}
    {
    }

    const Iterable& begin() const
    {
        return m_begin;
    }

    const Iterable& end() const
    {
        return m_end;
    }

private:
    Iterable    m_begin;
    Iterable    m_end;
};

#endif // EULER_COMMON_RANGE_HELPER_H
