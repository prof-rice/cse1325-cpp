#include "deck.h"
#include <iostream>

int main() {
    Deck deck;
    
    deck.add_card("Reuse and extension of fields and method implementations from another class", "Inheritance");
    deck.add_card("Bundling data and code into a restricted container","Encapsulation");
    deck.add_card("A data type that can typically be handled directly by the underlying hardware","Primitive Type");
     deck.add_card("A data type consisting of a fixed set of constant values called enumerators","Enumerated Type");
    deck.add_card("A template encapsulating data and code that manipulates it","Class");
    deck.add_card("An encapsulated bundle of data and code","Instance");
    deck.add_card("A block of memory associated with a symbolic name that contains an object instance or a primitive data value","Variable");
    deck.add_card("A short string representing a mathematical, logical, or machine control action","Operator");
    deck.add_false_answer("Constructor");
    deck.add_false_answer("Attribute");
    deck.add_false_answer("Friend");
    deck.add_false_answer("Override");
    
    std::cout << "Select the number of the term for each definition (-1 to exit)\n\n";
    
    std::vector<std::string> options = deck.options();
    int option;
    
    while(std::cin) {
        for(int i=0; i < options.size(); ++i) 
            std::cout << i << ") " << options[i] << std::endl;
        const Card& card = deck.deal();
        std::cout << '\n' << card << "? ";
        std::cin >> option;
        if(option < 0) break;
        std::cout << '\n' << card.attempt(options[option]) << "\n\n";
    }
}
