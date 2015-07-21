#ifndef EULER_COMMON_RANGE_H
#define EULER_COMMON_RANGE_H

#include "range_helper.h"

template <typename T>
class RangeIterator
{
public:
    RangeIterator(const T& value, const T& step = static_cast<T>(1))
      : m_count{value}
      , m_step{step}
    {
    }

    T operator*() const
    {
        return m_count;
    }

    RangeIterator& operator++()
    {
        m_count += m_step;
        return *this;
    }

    bool operator!=(const RangeIterator& other) const
    {
        return m_count < other.m_count;
    }

private:
    T   m_count;
    T   m_step;
};

template <typename T>
RangeHelper<RangeIterator<T> > range(const T& start, const T& stop, const T& step = static_cast<T>(1))
{
    return RangeHelper<RangeIterator<T> >{RangeIterator<T>(start, step), RangeIterator<T>(stop)};
}

#endif // EULER_COMMON_RANGE_H
