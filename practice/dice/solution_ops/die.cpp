#include "die.h"
#include <cstdlib>

Die::Die(int faces) : _faces{faces}, _value{1} { }
const int Die::faces() const {return _faces;}
void Die::roll() {_value = 1+std::rand()%_faces;}
int Die::value() const {return _value;}
std::ostream& operator<<(std::ostream& ost, const Die& die) {
    ost << die.value();
    return ost;
}
