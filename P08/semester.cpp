#include "semester.h"

std::ostream& operator<<(std::ostream& ost, const Semester& semester) {
    ost << ((semester == Semester::FALL) ? "fall" :
           ((semester == Semester::SPRING) ? "spring" : "summer"));
    return ost;
}
Semester load_semester(std::istream& ist) {
    std::string s;
    std::getline(ist, s);
    if(s == "fall") return Semester::FALL;
    if(s == "spring") return Semester::SPRING;
    if(s == "summer") return Semester::SUMMER;
    throw std::runtime_error{std::string{"Invalid semester: " + s}};
}
