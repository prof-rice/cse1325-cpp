#include "student.h"
#include "parent.h"
#include <vector>

void print(const std::vector<Student>& students) {
    for(int i=0; i<students.size(); ++i)
        std::cout << i << ") " << students[i] << std::endl;
}

void print(const std::vector<Parent>& parents) {
    for(int i=0; i<parents.size(); ++i)
        std::cout << i << ") " << parents[i] << std::endl;
}

void cin_clear() {
    std::cin.ignore(32767, '\n');
}

      // Constructor Data
const std::vector<std::string> names{
        "Enrique Young",  // student
        "Isabella Young", // student
        "Biniti Adani", // student
        "James Montgomery", //student
        "Robert Young",
        "Susan Young",
        "Nimish Adani",
        "Oscar Montgomery",
      };
const std::vector<std::string> emails{
        "eyoung@gmale.com",
        "iyoung@fmale.com",
        "biniti@myschool.org",
        "james.q.montgomery@british.uk",
        "bob-young@woohoo.com",
        "youngsr@uta.edu",
        "nimish.adani@hatmail.com",
        "oscar.the.m@funville.net",
      };
const std::vector<int> grades {
          1, 5, 3, 12, // For students only
      };


const int MAX_STUDENTS = 100;
const int MAX_PARENTS = 400;

int main() {
    std::vector<Student> students; students.reserve(MAX_STUDENTS);
    std::vector<Parent> parents; parents.reserve(MAX_PARENTS);
    std::string menu = R"(
           School Management and Reporting Tool

    1) Create new student       11) List one student's info
    2) Create new parent        12) List parent's info
    3) Link student to parent   13) List entire database
    
    0) Exit

Selection? )";

    int selection=42;
    int student;
    int parent;
    std::string name;
    std::string email;
    int grade;
    while (selection != 0) {
        std::cout << menu;
        std::cin >> selection; cin_clear();
        if(selection == 1) {
            if(students.size() > MAX_STUDENTS) throw std::runtime_error{"Enrollment full"};
            std::cout << "Student name? "; std::getline(std::cin, name);
            std::cout << "Student email? "; std::getline(std::cin, email);
            std::cout << "Grade? "; std::cin >> grade; cin_clear();
            students.push_back(Student{name, email, grade});
            
        } else if(selection == 2) { 
            if(parents.size() > MAX_PARENTS) throw std::runtime_error{"PTA full"};
            std::cout << "Parent name? "; std::getline(std::cin, name);
            std::cout << "Parent email? "; std::getline(std::cin, email);
            parents.push_back(Parent{name, email});
            
        } else if(selection == 3) { 
            print(students);
            std::cout << "Student? "; std::cin >> student;
            print(parents);
            std::cout << "Parent? "; std::cin >> parent;
            try {
                students.at(student).add_parent(parents.at(parent));
                parents.at(parent).add_student(students.at(student));
            } catch(...) {
                std::cerr << "Invalid selection!" << std::endl;
            }
        
        } else if(selection == 11) {
            print(students);
            std::cout << "Student? "; std::cin >> student;
            try {
                std::cout << students.at(student).full_info() << std::endl;
            } catch(...) {
                std::cerr << "INVALID SELECTION" << std::endl;
            }

        } else if(selection == 12) {
            print(parents);
            std::cout << "Parent)? "; std::cin >> parent;
            try {
                std::cout << parents.at(parent).full_info() << std::endl;
            } catch(...) {
                std::cerr << "INVALID SELECTION" << std::endl;
            }
        } else if(selection == 13) {
           std::cout << "\n    Students\n\n";
           for(int i=0; i<students.size(); ++i) 
                    std::cout << i << ") " << students.at(i).full_info() << std::endl;
           std::cout << "\n    Parents\n\n";
           for(int i=0; i<parents.size(); ++i) 
               std::cout << i << ") " << parents.at(i).full_info() << std::endl;         
        } else if(selection == 99) {  // EASTER EGG (for testing)
           for(int i=0; i<grades.size(); ++i)
               students.push_back(Student{names[i], emails[i], grades[i]});
           for(int i=grades.size(); i<names.size(); ++i)
              parents.push_back(Parent{names[i], emails[i]});
           students[0].add_parent(parents[0]); parents[0].add_student(students[0]);
           students[0].add_parent(parents[1]); parents[1].add_student(students[0]);
           students[1].add_parent(parents[0]); parents[0].add_student(students[1]);
           students[1].add_parent(parents[1]); parents[1].add_student(students[1]);
           students[2].add_parent(parents[2]); parents[2].add_student(students[2]);
           students[2].add_parent(parents[1]); parents[1].add_student(students[2]);
           students[3].add_parent(parents[1]); parents[1].add_student(students[3]);
           students[3].add_parent(parents[2]); parents[2].add_student(students[3]);
           students[3].add_parent(parents[3]); parents[3].add_student(students[3]);
        } else if(selection != 0) {
            std::cerr << "Invalid selection!" << std::endl;
        }
        
        // Clear any errors
        if(!std::cin) {
            std::cin.clear();
            std::cin.ignore(32767, '\n');
        }
    }
}

