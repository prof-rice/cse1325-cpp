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
    std::string full_info() const override;

    // Iterate over a parent to get their students
    typedef std::vector<Student*>::iterator iterator;
    typedef std::vector<Student*>::const_iterator const_iterator;
    inline iterator begin() {return _students.begin();}
    inline iterator end() {return _students.end();}
  protected:
    std::vector<Student*> _students;
};

#endif
