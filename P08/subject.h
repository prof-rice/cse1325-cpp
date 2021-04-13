#ifndef __SUBJECT_
#define __SUBJECT_

#include <iostream>
#include <vector>
#include <map>

enum class Subject {READING, WRITING, MATH, SCIENCE, HISTORY, ART, MUSIC, SPORTS};
const std::vector<Subject> subjects_vector {
    Subject::READING, Subject::WRITING, Subject::MATH, Subject::SCIENCE, 
    Subject::HISTORY, Subject::ART, Subject::MUSIC, Subject::SPORTS,
};

const std::map<Subject, std::string> subject_to_string {
  {Subject::READING, "reading"},
  {Subject::WRITING, "writing"},
  {Subject::MATH,    "math"},
  {Subject::SCIENCE, "science"},
  {Subject::HISTORY, "history"},
  {Subject::ART,     "art"},
  {Subject::MUSIC,   "music"},
  {Subject::SPORTS,  "sports"},
};

std::ostream& operator<<(std::ostream& ost, const Subject& subject);
Subject load_subject(std::istream& ist);

#endif
