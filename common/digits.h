#ifndef EULER_COMMON_DIGITS_H
#define EULER_COMMON_DIGITS_H

#include <vector>

template <typename T>
class DigitIterator
{
public:
    DigitIterator(T value)
      : m_value{value}
    {
    }

    T operator*() const
    {
        return m_value % static_cast<T>(10);
    }

    DigitIterator& operator++()
    {
        m_value /= static_cast<T>(10);
        return *this;
    }

    bool operator!=(const DigitIterator& other) const
    {
        return m_value != other.m_value;
    }

private:
    T   m_value;
};

template <typename T>
class DigitsOfANumber
{
public:
    DigitIterator<T> begin() const
    {
        return m_begin;
    }

    DigitIterator<T> end() const
    {
        return DigitIterator<T>(static_cast<T>(0));
    }

    DigitsOfANumber(T value)
      : m_begin{value}
    {
    }

private:
    DigitIterator<T>    m_begin;
};

template <typename T>
DigitsOfANumber<T> digits(T value)
{
    return DigitsOfANumber<T>(value);
}

template <typename T>
std::vector<unsigned char> getDigits(T value)
{
    if (value < static_cast<T>(0))
        value = -value;
    std::vector<unsigned char> result;
    do {
        result.emplace_back(value % 10);
        value /= 10;
    } while (value != 0);
    return result;
}

template <typename T>
T digitsToNum(const std::vector<unsigned char>& digits)
{
    T result = 0;
    for (auto it = digits.rbegin(); it != digits.rend(); ++it) {
        result = result * 10 + *it;
    }
    return result;
}

#endif // EULER_COMMON_DIGITS_H
