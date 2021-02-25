#ifndef __DECK_H
#define __DECK_H

#include "card.h"
#include <vector>
#include <random>

class Deck {
  public:
    Deck();
    void add_card(const std::string& question, const std::string& answer,
                  const std::string& hint = "", const std::string& image = "");
    void add_false_answer(std::string false_answer);
    
    std::vector<std::string> options();
    Card& deal();
  private:
    std::default_random_engine random;
    std::vector<Card*> _cards;
    std::vector<std::string> _options;
    int _next_card;
};
#endif
