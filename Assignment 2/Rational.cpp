// Implementation for class RationalNumber

#include "Rational.h"
#include <sstream>
#include <regex>

using namespace std;

Rational::Rational()
        :numerator(0),denominator(1) {};
Rational::Rational(int number)
        :numerator(number),denominator(1) {}
Rational::Rational(int numerator, int denominator)
        :numerator(numerator),denominator(denominator) {
    if(denominator == 0) {
        this->divByZero();
    }
    this->reduce();
}
Rational::~Rational() = default;

void Rational::divByZero() {
    cerr << "Error: divide by 0\n";
    throw overflow_error("Error: Divide by zero");
}

int Rational::getNumerator() const {
    return this->numerator;
}

void Rational::setNumerator(int numerator) {
    this->numerator = numerator;
    if(this->denominator != 1) {
        this->reduce();
    }
}

int Rational::getDenominator() const {
    return this->denominator;
}

void Rational::setDenominator(int denominator) {
    if(denominator == 0) {
        divByZero();
    }
    this->denominator = denominator;
    if(this->denominator != 1) {
        this->reduce();
    }
}

void Rational::reduce() {
    int mod;
    int larger_num;
    int smaller_num;
    int commonFactor;

    if(this->numerator != 0) {
        if(abs(this->getNumerator()) >= abs(this->getDenominator())) {
            larger_num = this->getNumerator();
            smaller_num = this->getDenominator();
        } else {
            larger_num = this->getDenominator();
            smaller_num = this->getNumerator();
        }

        mod = larger_num % smaller_num;

        if(mod == 0) {
            commonFactor =  smaller_num;
        } else {
            commonFactor =  mod;
        }

        this->numerator /= commonFactor;
        this->denominator /= commonFactor;
    }

    if(this->denominator < 0) {
        this->numerator *= -1;
        this->denominator *= -1;
    }

}

bool Rational::operator==(const Rational &rhs) const {
    return (this->numerator * rhs.denominator) == (rhs.numerator * this->denominator);
}

bool Rational::operator!=(const Rational &rhs) const {
    return !(*this == rhs);
}

bool Rational::operator<(const Rational &rhs) const {
    return (this->numerator * rhs.denominator) < (rhs.numerator * this->denominator);
}

bool Rational::operator>(const Rational &rhs) const {
    return (this->numerator * rhs.denominator) > (rhs.numerator * this->denominator);
}

bool Rational::operator<=(const Rational &rhs) const {
    return ((*this < rhs) || (rhs == *this));
}

bool Rational::operator>=(const Rational &rhs) const {
    return ((*this > rhs) || (rhs == *this));
}

Rational Rational::operator+(Rational &rightObj) {
    int new_numerator = (this->getNumerator() * rightObj.getDenominator())
                        + (rightObj.getNumerator() * this->getDenominator());
    int new_denominator = this->getDenominator() * rightObj.getDenominator();
    return Rational(new_numerator, new_denominator);
}

Rational Rational::operator-(Rational &rightObj) {
    int new_numerator = (this->getNumerator() * rightObj.getDenominator())
                        - (rightObj.getNumerator() * this->getDenominator());
    int new_denominator = this->getDenominator() * rightObj.getDenominator();
    return Rational(new_numerator, new_denominator);
}

Rational Rational::operator*(Rational &rightObj) {
    return Rational(this->numerator * rightObj.getNumerator(),
                          this->denominator * rightObj.getDenominator());
}

Rational Rational::operator/(Rational &rightObj) {
    if(rightObj.getNumerator() == 0) {
        cerr << "Error: divide by 0\n";
        throw overflow_error("Error: Divide by zero");
    } else {
        return Rational(this->numerator * rightObj.getDenominator(),
                              this->denominator * rightObj.getNumerator());
    }
}

ostream &operator<<(ostream &os, const Rational &number) {
    os << number.numerator << "/" << number.denominator;
    return os;
}

istream &operator>>(std::istream &is, Rational &number) {
    regex fracRegex ("^(-?[0-9]+)\\/(-?[1-9][0-9]*)$");
    regex intRegex ("^(-?[0-9]+)$");
    smatch m;
    string input;
    stringstream ss;
    while(is) {
        if(is.fail()) {
            is.clear();
        }
        is >> input;
        if(regex_search(input, m, fracRegex) && m.size() > 1) {
            ss << m[1] << ' ' << m[2];
            ss >> number.numerator >> number.denominator;
            if(number.denominator == 0) {
                number.divByZero();
            }
            number.reduce();
            break;
        } else if(regex_search(input, m, intRegex) && m.size() > 1) {
            ss << m[1];
            ss >> number.numerator;
            number.denominator = 1;
            break;
        } else {
            cerr << "Please enter a valid fraction.\n";
            is.fail();
        }
    }
}