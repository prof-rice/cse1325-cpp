#include "grade.h"
#include <stdexcept>

std::ostream& operator<<(std::ostream& ost, const Grade& grade) {
    ost << grade_to_string.at(grade);
    return ost;
}
Grade load_grade(std::istream& ist) {
    std::string from_stream;
    std::getline(ist, from_stream);
    for(const auto& [grade, s] : grade_to_string)
        if(s == from_stream) return grade;
    throw std::runtime_error{std::string{"Invalid grade: " + from_stream}};
}
