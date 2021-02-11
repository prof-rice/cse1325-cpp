#include <iostream>

// Here's the same class for us to aggregate or composite - a named double.
// It's just a double with an associated std::string name.

class Ndouble {
  public:
    Ndouble(std::string name, double d);
    friend std::ostream& operator<<(std::ostream& ost, const Ndouble& n);
  private:
    std::string _name;
    double _d;
};

