#ifndef EULER_COMMON_BIGINTEGER_H
#define EULER_COMMON_BIGINTEGER_H

#include <stdexcept>
#include <string>

#include <gmp.h>

struct BigIntegerDivisionResult;

class BigInteger
{
public:
    BigInteger()
    {
        mpz_init(m_value);
    }

    // init & assignment
    BigInteger(const BigInteger& other)
    {
        mpz_init_set(m_value, other.m_value);
    }

    BigInteger(BigInteger&& other) noexcept
      : BigInteger{}
    {
        mpz_swap(m_value, other.m_value);
    }

    explicit BigInteger(const unsigned long int value)
    {
        mpz_init_set_ui(m_value, value);
    }

    explicit BigInteger(const long int value)
    {
        mpz_init_set_si(m_value, value);
    }

    explicit BigInteger(const double value)
    {
        mpz_init_set_d(m_value, value);
    }

    explicit BigInteger(const char* value_str)
      : BigInteger{value_str, 10}
    {
    }

    BigInteger(const char* value_str, int base)
    {
        if (-1 == mpz_init_set_str(m_value, value_str, base)) {
            mpz_clear(m_value);
            throw std::runtime_error("invalid value string");
        }
    }

    ~BigInteger()
    {
        mpz_clear(m_value);
    }

    // assignment
    BigInteger& operator=(const BigInteger& other)
    {
        mpz_set(m_value, other.m_value);
        return *this;
    }

    BigInteger& operator=(BigInteger&& other) noexcept
    {
        mpz_swap(m_value, other.m_value);
        return *this;
    }

    BigInteger& operator=(const unsigned long int value)
    {
        mpz_set_ui(m_value, value);
        return *this;
    }

    BigInteger& operator=(const long int value)
    {
        mpz_set_si(m_value, value);
        return *this;
    }

    BigInteger& operator=(const double value)
    {
        mpz_set_d(m_value, value);
        return *this;
    }

    BigInteger& operator=(const char* value_str)
    {
        set(value_str, 10);
        return *this;
    }

    void set(const char* value_str, const int base)
    {
        if (-1 == mpz_set_str(m_value, value_str, base)) {
            throw std::runtime_error("invalid value string");
        }
    }

    // conversion
    explicit operator unsigned long int() const
    {
        return mpz_get_ui(m_value);
    }

    explicit operator long int() const
    {
        return mpz_get_si(m_value);
    }

    explicit operator double() const
    {
        return mpz_get_d(m_value);
    }

    explicit operator std::string() const
    {
        return toString(10);
    }

    std::string toString(int base) const
    {
        const auto len = mpz_sizeinbase(m_value, base);
        std::string result(len + 1, ' ');

        mpz_get_str(&result[0], base, m_value);
        if (result[0] != '-')
            result.pop_back();
        return result;
    }

    // arithmetic
    BigInteger& operator+=(const BigInteger& other)
    {
        mpz_add(m_value, m_value, other.m_value);
        return *this;
    }

    BigInteger& operator+=(const unsigned long int value)
    {
        mpz_add_ui(m_value, m_value, value);
        return *this;
    }

    BigInteger& operator-=(const BigInteger& other)
    {
        mpz_sub(m_value, m_value, other.m_value);
        return *this;
    }

    BigInteger& operator-=(const unsigned long int value)
    {
        mpz_sub_ui(m_value, m_value, value);
        return *this;
    }

    BigInteger& operator*=(const BigInteger& other)
    {
        mpz_mul(m_value, m_value, other.m_value);
        return *this;
    }

    BigInteger& operator*=(const unsigned long int value)
    {
        mpz_mul_ui(m_value, m_value, value);
        return *this;
    }

    BigInteger& operator*=(const long int value)
    {
        mpz_mul_si(m_value, m_value, value);
        return *this;
    }

    BigInteger& operator/=(const BigInteger& other)
    {
        mpz_tdiv_q(m_value, m_value, other.m_value);
        return *this;
    }

    BigInteger& operator%=(const BigInteger& other)
    {
        mpz_tdiv_r(m_value, m_value, other.m_value);
        return *this;
    }

    BigInteger& operator/=(const unsigned long int value)
    {
        mpz_tdiv_q_ui(m_value, m_value, value);
        return *this;
    }

    BigInteger& operator%=(const unsigned long int value)
    {
        mpz_tdiv_r_ui(m_value, m_value, value);
        return *this;
    }

    std::size_t sizeInBase(const int base) const
    {
        return mpz_sizeinbase(m_value, base);
    }

private:
    friend BigInteger operator+(const BigInteger&, const BigInteger&);
    friend BigInteger operator+(const BigInteger&, unsigned long int);
    friend BigInteger operator+(unsigned long int, const BigInteger&);
    friend BigInteger operator-(const BigInteger&, const BigInteger&);
    friend BigInteger operator-(const BigInteger&, unsigned long int);
    friend BigInteger operator-(unsigned long int, const BigInteger&);
    friend BigInteger operator-(const BigInteger&);
    friend BigInteger operator*(const BigInteger&, const BigInteger&);
    friend BigInteger operator*(const BigInteger&, unsigned long int);
    friend BigInteger operator*(unsigned long int, const BigInteger&);
    friend BigInteger operator*(const BigInteger&, long int);
    friend BigInteger operator*(long int, const BigInteger&);

    friend BigInteger operator/(const BigInteger&, const BigInteger&);
    friend BigInteger operator%(const BigInteger&, const BigInteger&);
    friend BigInteger operator/(const BigInteger&, unsigned long int);
    friend BigInteger operator%(const BigInteger&, unsigned long int);

    friend BigIntegerDivisionResult div(const BigInteger&, const BigInteger&);
    friend BigIntegerDivisionResult div(const BigInteger&, unsigned long int);

    friend BigInteger pow(const BigInteger&, unsigned long int);
    friend BigInteger pow(unsigned long int, unsigned long int);

    friend BigInteger abs(const BigInteger&);

    friend bool operator==(const BigInteger&, const BigInteger&);
    friend bool operator==(const BigInteger&, double);
    friend bool operator==(double, const BigInteger&);
    friend bool operator==(const BigInteger&, long int);
    friend bool operator==(long int, const BigInteger&);
    friend bool operator==(const BigInteger&, unsigned long int);
    friend bool operator==(unsigned long int, const BigInteger&);

    friend bool operator<(const BigInteger&, const BigInteger&);
    friend bool operator<(const BigInteger&, double);
    friend bool operator<(double, const BigInteger&);
    friend bool operator<(const BigInteger&, long int);
    friend bool operator<(long int, const BigInteger&);
    friend bool operator<(const BigInteger&, unsigned long int);
    friend bool operator<(unsigned long int, const BigInteger&);

    friend bool operator<=(const BigInteger&, const BigInteger&);
    friend bool operator<=(const BigInteger&, double);
    friend bool operator<=(double, const BigInteger&);
    friend bool operator<=(const BigInteger&, long int);
    friend bool operator<=(long int, const BigInteger&);
    friend bool operator<=(const BigInteger&, unsigned long int);
    friend bool operator<=(unsigned long int, const BigInteger&);

    friend bool operator>(const BigInteger&, const BigInteger&);
    friend bool operator>(const BigInteger&, double);
    friend bool operator>(double, const BigInteger&);
    friend bool operator>(const BigInteger&, long int);
    friend bool operator>(long int, const BigInteger&);
    friend bool operator>(const BigInteger&, unsigned long int);
    friend bool operator>(unsigned long int, const BigInteger&);

    friend bool operator>=(const BigInteger&, const BigInteger&);
    friend bool operator>=(const BigInteger&, double);
    friend bool operator>=(double, const BigInteger&);
    friend bool operator>=(const BigInteger&, long int);
    friend bool operator>=(long int, const BigInteger&);
    friend bool operator>=(const BigInteger&, unsigned long int);
    friend bool operator>=(unsigned long int, const BigInteger&);


    mpz_t   m_value;
};

struct BigIntegerDivisionResult
{
    BigInteger quot;
    BigInteger rem;
};

BigInteger operator+(const BigInteger& op0, const BigInteger& op1)
{
    BigInteger result;
    mpz_add(result.m_value, op0.m_value, op1.m_value);
    return result;
}

BigInteger operator+(const BigInteger& op0, const unsigned long int op1)
{
    BigInteger result;
    mpz_add_ui(result.m_value, op0.m_value, op1);
    return result;
}

BigInteger operator+(const unsigned long int op0, const BigInteger& op1)
{
    BigInteger result;
    mpz_add_ui(result.m_value, op1.m_value, op0);
    return result;
}

BigInteger operator-(const BigInteger& op0, const BigInteger& op1)
{
    BigInteger result;
    mpz_sub(result.m_value, op0.m_value, op1.m_value);
    return result;
}

BigInteger operator-(const BigInteger& op0, const unsigned long int op1)
{
    BigInteger result;
    mpz_sub_ui(result.m_value, op0.m_value, op1);
    return result;
}

BigInteger operator-(const unsigned long int op0, const BigInteger& op1)
{
    BigInteger result;
    mpz_ui_sub(result.m_value, op0, op1.m_value);
    return result;
}

BigInteger operator-(const BigInteger& op)
{
    BigInteger result;
    mpz_neg(result.m_value, op.m_value);
    return result;
}

BigInteger operator*(const BigInteger& op0, const BigInteger& op1)
{
    BigInteger result;
    mpz_mul(result.m_value, op0.m_value, op1.m_value);
    return result;
}

BigInteger operator*(const BigInteger& op0, unsigned long int op1)
{
    BigInteger result;
    mpz_mul_ui(result.m_value, op0.m_value, op1);
    return result;
}

BigInteger operator*(unsigned long int op0, const BigInteger& op1)
{
    BigInteger result;
    mpz_mul_ui(result.m_value, op1.m_value, op0);
    return result;
}

BigInteger operator*(const BigInteger& op0, long int op1)
{
    BigInteger result;
    mpz_mul_si(result.m_value, op0.m_value, op1);
    return result;
}

BigInteger operator*(long int op0, const BigInteger& op1)
{
    BigInteger result;
    mpz_mul_si(result.m_value, op1.m_value, op0);
    return result;
}

BigInteger operator/(const BigInteger& op0, const BigInteger& op1)
{
    BigInteger result;
    mpz_tdiv_q(result.m_value, op0.m_value, op1.m_value);
    return result;
}

BigInteger operator%(const BigInteger& op0, const BigInteger& op1)
{
    BigInteger result;
    mpz_tdiv_r(result.m_value, op0.m_value, op1.m_value);
    return result;
}

BigInteger operator/(const BigInteger& op0, const unsigned long int op1)
{
    BigInteger result;
    mpz_tdiv_q_ui(result.m_value, op0.m_value, op1);
    return result;
}

BigInteger operator%(const BigInteger& op0, const unsigned long int op1)
{
    BigInteger result;
    mpz_tdiv_r_ui(result.m_value, op0.m_value, op1);
    return result;
}

BigIntegerDivisionResult div(const BigInteger& op0, const BigInteger& op1)
{
    BigIntegerDivisionResult result;
    mpz_tdiv_qr(result.quot.m_value, result.rem.m_value, op0.m_value, op1.m_value);
    return result;
}

BigIntegerDivisionResult div(const BigInteger& op0, const unsigned long int op1)
{
    BigIntegerDivisionResult result;
    mpz_tdiv_qr_ui(result.quot.m_value, result.rem.m_value, op0.m_value, op1);
    return result;
}

BigInteger abs(const BigInteger& op)
{
    BigInteger result;
    mpz_abs(result.m_value, op.m_value);
    return result;
}

BigInteger pow(const BigInteger& base, const unsigned long int exp)
{
    BigInteger result;
    mpz_pow_ui(result.m_value, base.m_value, exp);
    return result;
}

BigInteger pow(const unsigned long int base, const unsigned long exp)
{
    BigInteger result;
    mpz_ui_pow_ui(result.m_value, base, exp);
    return result;
}

bool operator==(const BigInteger& op0, const BigInteger& op1)
{
    return 0 == mpz_cmp(op0.m_value, op1.m_value);
}

bool operator==(const BigInteger& op0, double op1)
{
    return 0 == mpz_cmp_d(op0.m_value, op1);
}

bool operator==(double op0, const BigInteger& op1)
{
    return 0 == mpz_cmp_d(op1.m_value, op0);
}

bool operator==(const BigInteger& op0, long int op1)
{
    return 0 == mpz_cmp_si(op0.m_value, op1);
}

bool operator==(long int op0, const BigInteger& op1)
{
    return 0 == mpz_cmp_si(op1.m_value, op0);
}

bool operator==(const BigInteger& op0, unsigned long int op1)
{
    return 0 == mpz_cmp_ui(op0.m_value, op1);
}

bool operator==(unsigned long int op0, const BigInteger& op1)
{
    return 0 == mpz_cmp_ui(op1.m_value, op0);
}

bool operator!=(const BigInteger& op0, const BigInteger& op1)
{
    return !(op0 == op1);
}

bool operator!=(const BigInteger& op0, double op1)
{
    return !(op0 == op1);
}

bool operator!=(double op0, const BigInteger& op1)
{
    return !(op0 == op1);
}

bool operator!=(const BigInteger& op0, long int op1)
{
    return !(op0 == op1);
}

bool operator!=(long int op0, const BigInteger& op1)
{
    return !(op0 == op1);
}

bool operator!=(const BigInteger& op0, unsigned long int op1)
{
    return !(op0 == op1);
}

bool operator!=(unsigned long int op0, const BigInteger& op1)
{
    return !(op0 == op1);
}

//
// operator<
//
bool operator<(const BigInteger& op0, const BigInteger& op1)
{
    return 0 > mpz_cmp(op0.m_value, op1.m_value);
}

bool operator<(const BigInteger& op0, double op1)
{
    return 0 > mpz_cmp_d(op0.m_value, op1);
}

bool operator<(double op0, const BigInteger& op1)
{
    return 0 < mpz_cmp_d(op1.m_value, op0);
}

bool operator<(const BigInteger& op0, long int op1)
{
    return 0 > mpz_cmp_si(op0.m_value, op1);
}

bool operator<(long int op0, const BigInteger& op1)
{
    return 0 < mpz_cmp_si(op1.m_value, op0);
}

bool operator<(const BigInteger& op0, unsigned long int op1)
{
    return 0 > mpz_cmp_ui(op0.m_value, op1);
}

bool operator<(unsigned long int op0, const BigInteger& op1)
{
    return 0 < mpz_cmp_ui(op1.m_value, op0);
}

//
// operator<=
//
bool operator<=(const BigInteger& op0, const BigInteger& op1)
{
    return 0 >= mpz_cmp(op0.m_value, op1.m_value);
}

bool operator<=(const BigInteger& op0, double op1)
{
    return 0 >= mpz_cmp_d(op0.m_value, op1);
}

bool operator<=(double op0, const BigInteger& op1)
{
    return 0 <= mpz_cmp_d(op1.m_value, op0);
}

bool operator<=(const BigInteger& op0, long int op1)
{
    return 0 >= mpz_cmp_si(op0.m_value, op1);
}

bool operator<=(long int op0, const BigInteger& op1)
{
    return 0 <= mpz_cmp_si(op1.m_value, op0);
}

bool operator<=(const BigInteger& op0, unsigned long int op1)
{
    return 0 >= mpz_cmp_ui(op0.m_value, op1);
}

bool operator<=(unsigned long int op0, const BigInteger& op1)
{
    return 0 <= mpz_cmp_ui(op1.m_value, op0);
}

//
// operator>
//
bool operator>(const BigInteger& op0, const BigInteger& op1)
{
    return 0 < mpz_cmp(op0.m_value, op1.m_value);
}

bool operator>(const BigInteger& op0, double op1)
{
    return 0 < mpz_cmp_d(op0.m_value, op1);
}

bool operator>(double op0, const BigInteger& op1)
{
    return 0 > mpz_cmp_d(op1.m_value, op0);
}

bool operator>(const BigInteger& op0, long int op1)
{
    return 0 < mpz_cmp_si(op0.m_value, op1);
}

bool operator>(long int op0, const BigInteger& op1)
{
    return 0 > mpz_cmp_si(op1.m_value, op0);
}

bool operator>(const BigInteger& op0, unsigned long int op1)
{
    return 0 < mpz_cmp_ui(op0.m_value, op1);
}

bool operator>(unsigned long int op0, const BigInteger& op1)
{
    return 0 > mpz_cmp_ui(op1.m_value, op0);
}

//
// operator>=
//
bool operator>=(const BigInteger& op0, const BigInteger& op1)
{
    return 0 <= mpz_cmp(op0.m_value, op1.m_value);
}

bool operator>=(const BigInteger& op0, double op1)
{
    return 0 <= mpz_cmp_d(op0.m_value, op1);
}

bool operator>=(double op0, const BigInteger& op1)
{
    return 0 >= mpz_cmp_d(op1.m_value, op0);
}

bool operator>=(const BigInteger& op0, long int op1)
{
    return 0 <= mpz_cmp_si(op0.m_value, op1);
}

bool operator>=(long int op0, const BigInteger& op1)
{
    return 0 >= mpz_cmp_si(op1.m_value, op0);
}

bool operator>=(const BigInteger& op0, unsigned long int op1)
{
    return 0 <= mpz_cmp_ui(op0.m_value, op1);
}

bool operator>=(unsigned long int op0, const BigInteger& op1)
{
    return 0 >= mpz_cmp_ui(op1.m_value, op0);
}

#endif // EULER_COMMON_BIGINTEGER_H
