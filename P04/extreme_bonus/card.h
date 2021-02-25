#ifndef __CARD_H
#define __CARD_H
#include <ostream>

class Card {
  public:
    Card(std::string question, std::string answer);
    virtual void extended_question() const;
    virtual std::string attempt(std::string response) const;
    friend std::ostream& operator<<(std::ostream& ost, const Card& card);
  protected:
    std::string _question;
    std::string _answer;
};
#endif
