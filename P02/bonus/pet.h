#ifndef __PET_H
#define __PET_H

#include <vector>
#include <string>

enum Type {DOG, CAT, HORSE};
const std::vector<std::string> to_string {
    "dog", "cat", "horse",
};
const double human_lifespan = 80.0;
const std::vector<double> pet_lifespan {
    10.0, 14.0, 27.0,
};


class Pet {
  public:
    Pet(std::string _name, double age, Type type);
    std::string to_string();
    double human_years();
  private:
    std::string _name;
    double _age;
    Type _type;
};


#endif
