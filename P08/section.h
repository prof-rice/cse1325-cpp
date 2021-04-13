#ifndef __SECTION_
#define __SECTION_

#include "course.h"
#include "semester.h"

class Section {
  public:
    Section(Course course, Semester semester, int year); // Teacher teacher
    Section(std::istream& ist);
    void save(std::ostream& ost);
    friend std::ostream& operator<<(std::ostream& ost, const Section& section);
  private:
    Course _course;
    Semester _semester;
    int _year;
    int _max_students;
    // Teacher& _teacher;
};

#endif
