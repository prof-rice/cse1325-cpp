#ifndef __PET_H
#define __PET_H

#include <vector>
#include <string>

enum Type {DOG, CAT, HORSE};
const std::vector<std::string> to_string {
    "dog", "cat", "horse"
};

class Pet {
  public:
    Pet(std::string _name, double age, Type type);
    std::string to_string();
  private:
    std::string _name;
    double _age;
    Type _type;
};


#endif
