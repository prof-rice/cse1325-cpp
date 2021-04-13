#ifndef __STUDENT_H
#define __STUDENT_H

#include "person.h"
#include <vector>
#include <map>

class Parent;

class Student : public Person {
  public:
    Student(std::string name, std::string email, int grade);
    Student(std::istream& ist);
    void save(std::ostream& ost) override;
    void save_aggregates(std::ostream& ost);
    void load_aggregates(std::istream& ist, const std::map<std::string, Parent*>& parents);
    void add_parent(Parent& parent);
    int parents();
    Parent& parent(int index);
    std::string full_info() const override;
  protected:
    int _grade;
    std::vector<Parent*> _parents;
};

#endif
