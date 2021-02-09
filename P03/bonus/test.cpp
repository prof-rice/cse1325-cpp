#include "fraction.h"
#include <iostream>
#include <sstream>

int main() {
    // Vector is the bit representing the test being performed
    // Result accumulates all failures, and is the return code
    int vector = 1;
    int result = 0;

    // Three fractions to handle the test cases
    Fraction f1{1, 2};
    Fraction f2{3, -4};
    Fraction f3{-1, 3};
    Fraction f4{2, 4};
    
    //
    // Begin testing
    //
    
    // I/O Testing
    // Test output
    std::ostringstream oss;
    oss << f1 << ' ' << f3;
    if (oss.str() != "1/2 -1/3") {
        std::cerr << "FAIL: Stream out\n";
        result |= vector;
    }
    
    // Test input
    std::string sfi{"-13/255"};
    std::istringstream iss{sfi};
    Fraction fi;
    iss >> fi;
    if (fi != Fraction{-13, 255}) {
        std::cerr << "FAIL: Stream in\n";
        result |= vector;
    }
    vector <<= 1;

    // Reduce testing    
    // Test reduce() handling of a negative denominator
    if (f2 != Fraction{-3, 4}) {
        std::cerr << "FAIL: Reduce sign\n";
        result |= vector;
    }
    
    if (f1 != f4) {
        std::cerr << "FAIL: Reduce numerator and denominator\n";
        result |= vector;
    }
    vector <<= 1;

    // Negation testing
    // Test negation of a positive fraction
    if (-f1 != Fraction{-1, 2}) {
        std::cerr << "FAIL: Unary negative of positive\n";
        result |= vector;
    }

    // Test negation of a negative fraction
    if (-f2 != Fraction{3, 4}) {
        std::cerr << "FAIL: Unary negative of negative\n";
        result |= vector;
    }
    vector <<= 1;

    // Mathematical operator testing
    // Test addition
    if (f1+f2 != Fraction{-1, 4}) {
        std::cerr << "FAIL: Addition\n";
        result |= vector;
    }


    // Test subtraction
    if (f1-f3 != Fraction{5, 6}) {
        std::cerr << "FAIL: Subtraction\n";
        result |= vector;
    }

    // Test multiplication
    if (f2*f3 != Fraction{3, 12}) {
        std::cerr << "FAIL: Multiplication\n";
        result |= vector;
    }

    // Test division
    if (f3/f1 != Fraction{-2, 3}) {
        std::cerr << "FAIL: Division\n";
        result |= vector;
    }
    vector <<= 1;

    // Comparison operator testing
    // Test equality
    if (f1 == f2 || f1 == f3 || f2 == f3) {
        std::cerr << "FAIL: Equality\n";
        result |= vector;
    }
  
    // Test inequality
    if (f1 != f4) {
        std::cerr << "FAIL: Inquality\n";
        result |= vector;
    }
  
    // Test less than
    if (f1 < f2 || f1 < f4) {
        std::cerr << "FAIL: Less than\n";
        result |= vector;
    }
  
    // Test less than or equal
    if (f1 <= f2 || !(f1 <= f4)) {
        std::cerr << "FAIL: Less than or equal\n";
        result |= vector;
    }
  
      // Test greater than
    if (f2 > f1 || f4 > f1) {
        std::cerr << "FAIL: Greater than\n";
        result |= vector;
    }
  
    // Test greater than or equal
    if (f2 >= f1 || !(f4 >= f1)) {
        std::cerr << "FAIL: Greater than or equal\n";
        result |= vector;
    }
    vector <<= 1;

    //
    // End Testing
    //
    
    // Report the test results to the user and OS
    if(result) std::cerr << "\nFAILED - result is " << std::hex << std::showbase << result << std::endl;
    return result;
}
