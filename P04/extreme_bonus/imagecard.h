#ifndef __IMAGECARD_H
#define __IMAGECARD_H
#include "card.h"

class Imagecard : public Card {
  public:
    Imagecard(std::string question, std::string answer, std::string imagefile);
    void extended_question() const override;
  private:
    std::string _imagefile;
};
#endif
