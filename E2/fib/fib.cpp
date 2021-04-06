#include "fib.h"
#include <stdexcept>

Fib::Fib(int first, int second) {
    fibs.push_back(first);
    fibs.push_back(second);
    if(first < 0 || second <= first)
        throw std::runtime_error{"Invalid starting sequence"};
}
int Fib::operator[](int index) {
    int s;
    while((s=fibs.size()) <= index)
        fibs.push_back(fibs[s-1] + fibs[s-2]);
    return fibs[index];
}
