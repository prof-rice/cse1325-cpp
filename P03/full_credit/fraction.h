#ifndef __FRACTION_H
#define __FRACTION_H

#include <iostream>

class Fraction {
  public:
    Fraction(int numerator = 0, int denominator = 1);
    Fraction operator-();
    Fraction operator+(Fraction& rhs);
    Fraction operator-(Fraction& rhs);
    Fraction operator*(Fraction& rhs);
    Fraction operator/(Fraction& rhs);
    friend std::ostream& operator<<(std::ostream& ost, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& ist, Fraction& fraction);
    friend bool operator!=(const Fraction& lhs, const Fraction& rhs);
  private:
    void reduce();
    int _n; // numerator
    int _d; // denominator
};

#endif
