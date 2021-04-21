#include <iostream>

class Flyable {
  public:
    virtual std::string fly() = 0;
};

class Fruit : public Flyable {
  public:
    std::string fly() override {
      return "like a banana";
    }
};

class Time : public Flyable {
  public:
    std::string fly() override {
      return "like an arrow";
    }
};

int main() {
    Flyable* f = new Time;
    std::cout << "Time flies " << f->fly() << std::endl;
    delete f;
    f = new Fruit;
    std::cout << "Fruit flies " << f->fly() << std::endl;
}
