#include "ndouble.h"

Ndouble::Ndouble(std::string name, double d) : _name{name}, _d{d}{ }
std::ostream& operator<<(std::ostream& ost, const Ndouble& n) {
    ost << n._name << " (" << n._d << ")";
    return ost;
}

