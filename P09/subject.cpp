#include "subject.h"
#include <stdexcept>

std::ostream& operator<<(std::ostream& ost, const Subject& subject) {
    try {
        ost << subject_to_string.at(subject);
    } catch(std::exception& e) {
        ost << "Unknown Subject(" << e.what() << ")";
    }
    return ost;
}
Subject load_subject(std::istream& ist) {
    std::string from_stream;
    std::getline(ist, from_stream);
    for(const auto& [subject, s] : subject_to_string)
        if(s == from_stream) return subject;
    throw std::runtime_error{std::string{"Invalid subject: " + from_stream}};
}
