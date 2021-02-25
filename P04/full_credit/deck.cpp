#include "deck.h"
#include <algorithm>

Deck::Deck() : _next_card{0}, random{std::default_random_engine{std::random_device{}()}} { }

void Deck::add_card(const std::string& question, const std::string& answer) {
    _cards.push_back(Card{question, answer});
    _options.push_back(answer);
    _next_card = _cards.size()+1; // force a reshuffle
}

void Deck::add_false_answer(std::string false_answer) {
    _options.push_back(false_answer);
}
  
std::vector<std::string> Deck::options() {
    std::sort(_options.begin(), _options.end());
    return _options;
}

Card& Deck::deal() {
    if(_cards.empty()) throw std::runtime_error{"Attempt to deal an empty deck!"};
    if(_next_card >= _cards.size()) {
        _next_card = 0;
        std::shuffle(_cards.begin(), _cards.end(), random);
    }
    return _cards[_next_card++];
}

