#include "solution.h"
#include <stdexcept>
#include <iostream>
#include <sstream>

Solution::Solution(std::string name, std::string word, int x, int y, Direction direction) 
  : _name{name}, _word{word}, _x{x}, _y{y}, _direction{direction} { }

std::ostream& operator<<(std::ostream& ost, const Direction& direction) {
    ost << direction_to_string.at(direction);
    return ost;
}

std::string Solution::word() const {return _word;}
int Solution::x() const {return _x;}
int Solution::y() const {return _y;}
Direction Solution::direction() const {return _direction;}

bool Solution::operator<(const Solution& rhs) {
    if(_name < rhs._name) return true;
    else if (_name > rhs._name) return false;

    if(_word < rhs._word) return true;
    else if (_word > rhs._word) return false;

    if(_direction < rhs._direction) return true;
    else if (_direction > rhs._direction) return false;
    
    return false;
}

std::ostream& operator<<(std::ostream& ost, const Solution& solution) {
    ost << "In " << solution._name << ": " << solution._word << " found at (" << solution._x << ',' << solution._y << ',' << solution._direction << ")";
    return ost;
}
