#ifndef __PARENT_H
#define __PARENT_H

#include "person.h"
#include <vector>

class Student;

class Parent : public Person {
  public:
    using Person::Person;
    void add_student(Student& student);
    int students();
    Student& student(int index);
    std::string full_info() const override;
  private:
    std::vector<Student*> _students;
};

#endif
