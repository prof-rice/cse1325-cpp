#include "hintcard.h"

Hintcard::Hintcard(std::string question, std::string answer, std::string hint) 
      : Card(question, answer), _hint{hint} { }

std::string Hintcard::attempt(std::string response) const {
    for(char& c : response) c = toupper(c);
    if(response == _answer) return "Correct!";
    return "X - Hint: " + _hint;
}


