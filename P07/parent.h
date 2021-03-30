#ifndef __PARENT_H
#define __PARENT_H

#include "person.h"
#include <vector>
#include <map>

class Student;

class Parent : public Person {
  public:
    using Person::Person;
    void save(std::ostream& ost) override;
    void save_aggregates(std::ostream& ost);
    void load_aggregates(std::istream& ist, const std::map<std::string, Student*>& students);
    void add_student(Student& student);
    int students();
    Student& student(int index);
    std::string full_info() const override;
  private:
    std::vector<Student*> _students;
};

#endif
