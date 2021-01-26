#ifndef __COMPLEX_H
#define __COMPLEX_H
#include <string>

typedef double Radians;                              // Type Definition

// Manages complex numbers
class Complex {
  public:
    Complex(double re, double im);                   // Constructor
    ~Complex();                                      // Destructor
    friend Complex Polar(double r, Radians theta);   // Friend Function
    std::string to_string();                         // Method
    static void set_polar(bool p);                   // Static Method
    static bool get_polar();                         // Static Method
  private:
    double _re;                                      // Attribute
    double _im;                                      // Attribute
    static bool polar;                               // Static Attribute
};
Complex Polar(double r, Radians theta);
void print(Complex number);                          // Function
// Friend function Polar is the Factory pattern that "instances" a double 
//   using polar coordinates instead of rectangular (as the constructor uses)
// This pattern enables us to define "constructors" for a class
//   with a different name and behavior than a proper constructor.

#endif
