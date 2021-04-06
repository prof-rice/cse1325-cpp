#ifndef __FIB_H
#define __FIB_H

#include <vector>

class Fib {
  public:
    Fib(int first = 1, int second = 2);
    int operator[](int index);
  private:
    std::vector<int> fibs; // cache of ints already generated
};

#endif

