#include "parent.h"
#include "student.h"

void Parent::save(std::ostream& ost) {
    Person::save(ost);
}
void Parent::save_aggregates(std::ostream& ost) {
    ost << _email << '\n';
    ost << _students.size() << '\n';
    for(Student* student : _students) ost << *student << '\n';
}
void Parent::load_aggregates(std::istream& ist, const std::map<std::string, Student*>& students) {
    // Validate that these aggregates are for this Parent
    std::string email;
    std::getline(ist, email);
    if(email != _email) 
        throw std::runtime_error{"load_aggregates: " + email + " vs " + _email};
    
    // Load identifiers and create pointers to aggregates
    int size;
    ist >> size; ist.ignore(32767, '\n');
    if(size > 100) throw std::runtime_error{"Aggregate students too big"};
    while(size--) {
        std::getline(ist, email);
        if(!ist) throw std::runtime_error{"Input stream failed on parent aggregate load"};
        add_student(*students.at(email));
    }
}
void Parent::add_student(Student& student) {
    for(Student* s : _students) if(s == &student) return;
    _students.push_back(&student);
}
int Parent::students() {return _students.size();}
Student& Parent::student(int index) {
    return *(_students.at(index));
}
std::string Parent::full_info() const {
    std::string info = Person::full_info() + " - Students: ";
    std::string separator;
    for(auto s : _students) {
        info += separator + s->to_string();
        separator = ", ";
    }
    return info;
}

