#include "die.h"

#include <iostream>
#include <vector>
#include <ctime> // for time

bool validate(std::vector<Die> dice);
void score(std::vector<Die> dice);

int main() {

    std::cout << R"(
                                   SHIP -=- CAPTAIN -=- CREW

A voyage is attempted over 5 weeks, or rolls of 5 dice of 4, 6, 8, 10, and 12 sides respectively.
As a merchant, you seek to earn money by leasing a ship ('1'), hiring a captain ('2'), and completing
a full crew ('3'). If you succeed, then the sum of the remaining 2 dice is your commission. If you fail,
then you are paid nothing, but if you use fewer than 5 rolls, you will receive a bonus for delivering 
your cargo early.

You MUST follow precedence - ship before or concurrent with captain, before or concurrent with crew.
After a roll, type 5 characters to 'k'eep the corresponding die or 'd'iscard and reroll it.
(Previous decisions are remembered, although you must always type at least one k or d.)
You may 'k'eep any dice from a previous roll, as long as you follow the precedence.

Typing kddkd would 'k'eep the roll of the 4- and 10-sided dice, and reroll the rest. 
Typing k would keep the 4-sided roll again, and keep or discard the rest the same as the previous roll.
Typing kkkkk ends the game early if you get all 'keepers'.

Here's your first roll!

)";
    srand (time(NULL));

    std::vector<Die> dice{Die{4}, Die{6}, Die{8}, Die{10}, Die{12}};
    
    const int ROLLS = 5;
    for(int roll=1; roll<=ROLLS; ++roll) {
        for(auto& d: dice) {
            d.roll();
            std::cout << d.faces() << " => " << d.value() << (d.keep() ? " (k)" : "") << std::endl;
        }
        if(roll == ROLLS) break;
        std::string keep;
        do {
            std::cout << "For each die, enter k (keep) or d (discard), e.g., kddkd: ";
            std::cin >> keep;
            for(int i=0; i<5 && i<keep.size(); ++i) dice[i].keep(keep[i]=='k');
        } while (!validate(dice));
        if (keep == "kkkkk") break; // detect early voyage completion
    }
    score(dice);
}

void score(std::vector<Die> dice) {
    // Generate score
    bool ship    = false;
    bool captain = false;
    bool crew    = false;

    int points = 0;
    for(auto& d: dice) {
        switch(d.value()) {
            case 1: if(ship) points += 1;
                    else ship = true;
                    break;
            case 2: if(captain) points += 2;
                    else captain = true;
                    break;
            case 3: if(crew) points += 3;
                    else crew = true;
                    break;
            default: points += d.value();
        }
    }
    std::cout << "\nEarned this voyage: ";
    if(!ship) std::cout << "0 - you have no ship!\n";
    else if(!captain) std::cout << "0 - you have no captain!\n";
    else if(!crew) std::cout << "0 - you have no crew!\n";
    else std::cout << points << " - anchors aweigh!\n";
}

bool validate(std::vector<Die> dice) {
        bool ship    = false;
        bool captain = false;
        bool crew    = false;
        bool cargo   = false;
        
        for(auto& d: dice) {
            if(d.keep()) {
              switch(d.value()) {
                case 1: ship = true;
                        break;
                case 2: captain = true;
                        break;
                case 3: crew = true;
                        break;
                default: cargo = true;
              }
            }
        }
        if(!ship && (captain ||  crew || cargo)) {std::cerr << "INVALID: No ship!\n";    return false;}
        if(         !captain && (crew || cargo)) {std::cerr << "INVALID: No captain!\n"; return false;}
        if(                     !crew && cargo ) {std::cerr << "INVALID: No crew!\n";    return false;}
        return true;
}

