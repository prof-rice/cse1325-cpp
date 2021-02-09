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

    inline bool operator==(const Fraction& rhs) {return compare(rhs) == 0;}
    inline bool operator!=(const Fraction& rhs) {return compare(rhs) != 0;}
    inline bool operator> (const Fraction& rhs) {return compare(rhs) >  0;}
    inline bool operator>=(const Fraction& rhs) {return compare(rhs) >= 0;}
    inline bool operator< (const Fraction& rhs) {return compare(rhs) <  0;}
    inline bool operator<=(const Fraction& rhs) {return compare(rhs) <= 0;}

    friend std::ostream& operator<<(std::ostream& ost, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& ist, Fraction& fraction);
  private:
    int compare(const Fraction& rhs);
    void reduce();
    int _n; // numerator
    int _d; // denominator
};

#endif
