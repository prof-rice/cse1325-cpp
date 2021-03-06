#include "student.h"
#include "parent.h"

int main() {
    std::vector<Person*> people;
    Student s1{"Enrique Young", "eyoung@gmale.com", 1};
    Parent p1_1{"Robert Young", "bob-young@woohoo.com"};
    Parent p1_2{"Susan Young", "youngsr@uta.edu"};
    s1.add_parent(p1_1);
    s1.add_parent(p1_2);
    p1_1.add_student(s1);
    p1_2.add_student(s1);
    
    people.push_back(&s1);
    people.push_back(&p1_1);
    people.push_back(&p1_2);
    
    for(auto p : people) {
        std::cout << "operator<<:  " << *p << '\n'
                  << "full_info(): " << p->full_info() << "\n\n";
    }
}
    
