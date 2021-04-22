#include "section.h"
#include "teacher.h"

Section::Section(Course course, Semester semester, int year, Teacher& teacher)
  : _course{course}, _semester{semester}, _year{year}, _teacher{&teacher} { }

Section::Section(std::istream& ist) : _course{ist}, _teacher{new Teacher{ist}} {
    _semester = load_semester(ist);
    ist >> _year; ist.ignore(32767, '\n');
}
void Section::save(std::ostream& ost) {
    _course.save(ost);
    _teacher->save(ost);
    ost << _semester << '\n' << _year << '\n';
}
std::ostream& operator<<(std::ostream& ost, const Section& section) {
    ost << section._course << " for " << section._semester << ' ' << section._year
        << " (taught by " << *(section._teacher) << ")";
    return ost;
}

