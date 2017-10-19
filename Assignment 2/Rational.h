// Header file for RationalNumber class

#pragma once

#include <iostream>

class Rational {
private:
    int numerator;
    int denominator;
    void reduce();
    void divByZero();
public:
    Rational();
    explicit Rational(int number);
    Rational(int numerator, int denominator);
    virtual ~Rational();
    int getNumerator() const;
    void setNumerator(int numerator);
    int getDenominator() const;
    void setDenominator(int denominator);
    bool operator==(const Rational &rhs) const;
    bool operator!=(const Rational &rhs) const;
    bool operator<(const Rational &rhs) const;
    bool operator>(const Rational &rhs) const;
    bool operator<=(const Rational &rhs) const;
    bool operator>=(const Rational &rhs) const;
    Rational operator+(Rational &rightObj);
    Rational operator-(Rational &rightObj);
    Rational operator*(Rational &rightObj);
    Rational operator/(Rational &rightObj);
    friend std::ostream &operator<<(std::ostream &os, const Rational &number);
    friend std::istream &operator>>(std::istream &is, Rational &number);
};