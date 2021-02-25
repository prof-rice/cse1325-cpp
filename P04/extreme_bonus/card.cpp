#include "card.h"

Card::Card(std::string question, std::string answer) : _question{question} {
    for(char& c : answer) _answer += toupper(c);
}

void Card::extended_question() const { }

std::string Card::attempt(std::string response) const {
    for(char& c : response) c = toupper(c);
    if(response == _answer) return "Correct!";
    return "X - Correct answer was " + _answer;
}

std::ostream& operator<<(std::ostream& ost, const Card& card) {
    card.extended_question();
    ost << card._question;
    return ost;
}

