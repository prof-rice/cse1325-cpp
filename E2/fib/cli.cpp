#include "fib.h"
#include <iostream>

int main() {
    Fib fib;                 // Create a Fibonacci series object
    for(int i=4; i<9; ++i)   // Print the 5th through 10th integer
        std::cout << fib[i] << ' ';
    std::cout << std::endl;
}
