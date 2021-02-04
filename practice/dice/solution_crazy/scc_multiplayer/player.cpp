#include "player.h"
#include "die.h"
#include <iostream>
#include <vector>

Player::Player(std::string name) : _name{name}, _score{0} { }
std::string Player::name() {return _name;}
int Player::score() {return _score;}
bool validate(std::vector<Die> dice);
void Player::voyage() {
    std::cout << "\n---\n\n" << _name << " (" << _score << ") is attempting a voyage!\n\n";
        
    int score    = 0;
    std::vector<Die> dice{Die{4}, Die{6}, Die{8}, Die{10}, Die{12}};
    
    const int ROLLS = 5;
    for(int roll=1; roll<=ROLLS; ++roll) {
        for(auto& d: dice) std::cout << d.faces() << " => " << d.roll() << (d.keep() ? " (k)" : "") << std::endl;
        if(roll == ROLLS) break;
        while(true) {
            std::cout << "For each die, enter k (keep) or d (discard), e.g., kddkd: ";
            std::string keep;
            std::cin >> keep;
            for(int i=0; i<5 && i<keep.size(); ++i) dice[i].keep(keep[i]=='k');
            if(!validate(dice)) continue;
            if(keep == "kkkkk") {
                int early = ROLLS - roll;
                early *= early;
                if (early > 0) std::cout << "BONUS for early delivery: " << early << std::endl; 
                score += early; 
            }
            break;
        }
        if (score) break; // detect early voyage completion
    }
    
    // Generate score
    bool ship    = false;
    bool captain = false;
    bool crew    = false;

    for(auto& d: dice) {
        d.keep(true);
        switch(d.roll()) {
            case 1: if(ship) score += 1;
                    else ship = true;
                    break;
            case 2: if(captain) score += 2;
                    else captain = true;
                    break;
            case 3: if(crew) score += 3;
                    else crew = true;
                    break;
            default: score += d.roll();
        }
    }
    std::cout << "\nEarned this voyage: ";
    if(!ship) {score = 0; std::cout << "0 - you have no ship!";}
    else if(!captain) {score = 0; std::cout << "0 - you have no captain!";}
    else if(!crew) {score = 0; std::cout << "0 - you have no crew!";}
    else std::cout << score << " - anchors aweigh!";
    _score += score;
}
bool validate(std::vector<Die> dice) {
        bool ship    = false;
        bool captain = false;
        bool crew    = false;
        bool cargo   = false;
        
        for(auto& d: dice) {
            if(d.keep()) {
              switch(d.roll()) {
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

