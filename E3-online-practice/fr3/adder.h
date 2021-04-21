#ifndef __ADDER_H
#define __ADDER_H

template<class T>
class Adder {
    T result;
  public:
    Adder(T initial) : result{initial} { }
    T add(T operand) {
        result += operand;
        return result;
    }
};

#endif
