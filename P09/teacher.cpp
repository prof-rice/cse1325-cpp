#include "teacher.h"
#include "section.h"
#include <sstream>

Teacher::Teacher(std::istream& ist) : Person{ist} { }
void Teacher::save(std::ostream& ost) {
    Person::save(ost);
}
std::string Teacher::full_info() const {
    std::ostringstream oss;
    oss << Person::full_info();
    return oss.str();
}

