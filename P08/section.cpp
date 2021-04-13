#include "section.h"

Section::Section(Course course, Semester semester, int year) 
  : _course{course}, _semester{semester}, _year{year} { }
Section::Section(std::istream& ist) : _course{ist} {
    _semester = load_semester(ist);
    ist >> _year; ist.ignore(32767, '\n');
}
void Section::save(std::ostream& ost) {
    _course.save(ost);
    ost << _semester << '\n' << _year << '\n';
}
std::ostream& operator<<(std::ostream& ost, const Section& section) {
    ost << section._course << " for " << section._semester << ' ' << section._year;
    return ost;
}

