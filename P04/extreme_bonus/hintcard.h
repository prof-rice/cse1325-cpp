#ifndef __HINTCARD_H
#define __HINTCARD_H
#include "card.h"

class Hintcard : public Card {
  public:
    Hintcard(std::string question, std::string answer, std::string hint);
    std::string attempt(std::string response) const override;
  private:
    std::string _hint;
};
#endif
