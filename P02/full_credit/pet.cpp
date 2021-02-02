#include "pet.h"

Pet::Pet(std::string name, double age, Type type)
  : _name{name}, _age{age}, _type{type} { }
std::string Pet::to_string() {
  return _name + " is a " + ::to_string[_type] + " age " + std::to_string(_age);
}

