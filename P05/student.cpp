#include "student.h"
#include "parent.h"

Student::Student(std::string name, std::string email, int grade)
  :  Person(name, email), _grade{grade} { }

void Student::add_parent(Parent& parent) {
    _parents.push_back(&parent);
}
int Student::parents() {return _parents.size();}
Parent& Student::parent(int index) {
    return *(_parents.at(index));
}
std::string Student::full_info() const {
    std::string info = Person::full_info() + " in grade " + std::to_string(_grade) + " - Parents: ";
    std::string separator;
    for(auto p : _parents) {
        info += separator + p->to_string();
        separator = ", ";
    }
    return info;
}

