#ifndef __GRADE_
#define __GRADE_

#include <iostream>
#include <vector>
#include <map>

enum class Grade {A, B, C, D, F, I, X};
const std::vector<Grade> grades_vector {
    Grade::A, Grade::B, Grade::C, Grade::D, Grade::F, Grade::I, Grade::X,  
};

const std::map<Grade, std::string> grade_to_string {
  {Grade::A, "A"},
  {Grade::B, "B"},
  {Grade::C, "C"},
  {Grade::D, "D"},
  {Grade::F, "F"},
  {Grade::I, "I"},
  {Grade::X, "X"},
};

std::ostream& operator<<(std::ostream& ost, const Grade& grade);
Grade load_grade(std::istream& ist);

#endif
