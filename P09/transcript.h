#ifndef __TRANSCRIPT_H
#define __TRANSCRIPT_H

#include "student.h"
#include "section.h"
#include "grade.h"
#include <iostream>

class Transcript {
  public:
    Transcript(Student& student, Section& section);
    Transcript(std::istream& ist);
    void save(std::ostream& ost);
    void assign_grade(Grade grade);
    friend std::ostream& operator<<(std::ostream& ost, const Transcript transcript);
  private:
    Student& _student;
    Section& _section;
    Grade _grade;
};

#endif
