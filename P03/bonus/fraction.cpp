#include "fraction.h"
#include <iostream>

Fraction::Fraction(int numerator, int denominator) : _n{numerator}, _d{denominator} {
    if(_d == 0) std::cerr << "Zero denominator!" << std::endl;
    else reduce();
}

// Mathematical operators

Fraction Fraction::operator-() {
    return Fraction{-_n, _d};
}
Fraction Fraction::operator+(Fraction& rhs) {
    return Fraction{(_n*rhs._d + _d*rhs._n),(_d * rhs._d)};
}
Fraction Fraction::operator-(Fraction& rhs) {
    return (-rhs) + (*this);
}
Fraction Fraction::operator*(Fraction& rhs) {
    return Fraction{_n*rhs._n,_d*rhs._d};
}
Fraction Fraction::operator/(Fraction& rhs) {
    return Fraction{_n*rhs._d,_d*rhs._n};
}

// Input / Output Operators

std::ostream& operator<<(std::ostream& ost, const Fraction& fraction) {
    ost << fraction._n;
    if(fraction._d != 1) ost << '/'<< fraction._d;
    return ost;
}
std::istream& operator>>(std::istream& ist, Fraction& fraction) {
    int n, d;
    char c;
    ist >> n >> c >> d;
    if(ist && c == '/') {
        fraction._n = n;
        fraction._d = d;
    } else {
        std::cerr << "ERROR: Invalid fraction" << std::endl;
    }
    fraction.reduce();
    return ist;
}

// Utility methods

// Return -1 if *this < rhs, 1 if *this > rhs, 0 if equal
// Simplest to make denominators equal and compare numerators
int Fraction::compare(const Fraction& rhs) {
    int left  = _n * rhs._d;
    int right = rhs._n * _d;
    if(left  < right) return -1;
    if(left  > right) return  1;
    return 0;
}

// This function is in "file scope", a psuedo-scope meaning 
// "global scope but inaccessible outside of its source file".
// It's a side-effect of how C++ 17 and earlier works.
// It could as easily be a private method.
int gcd(int n, int d) {
    n = abs(n);
    d = abs(d);
    if (n == d) return d;
    if (n == 0) return d;
    if (d == 0) return n;
    if (n % 2 == 0) { // n is even
        if (d % 2 == 0) return 2 * gcd(n/2, d/2); // d is even
        else return gcd(n/2, d);                  // d is odd

    } else {          // n is odd
        if (d % 2 == 0) return gcd(n, d/2);       // d is even
        if (n > d) return gcd((n - d)/2, d);      // d is odd
        else return gcd((d - n)/2, n);
    }
}

// Ensure that only the numerator is negative
// Also, simplify by dividing both by their greatest common divisor
void Fraction::reduce() {
    if(_d < 0) {_n = -_n; _d = -_d;}
    int _gcd = gcd(_n, _d);; 
    _n /= _gcd;
    _d /= _gcd;
}
