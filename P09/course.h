#ifndef __COURSE_
#define __COURSE_

#include "subject.h"
#include <vector>

class Course {
  public:
    Course(Subject subject, int grade);
    //void add_prerequisite(Course& course);
    Course(std::istream& ist);
    void save(std::ostream& ost);
    friend std::ostream& operator<<(std::ostream& ost, const Course& course);
  private:
    Subject _subject;
    int _grade;
    //std::vector<Course> _prerequisites;
};


#endif
