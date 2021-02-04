#include "player.h"

#include <iostream>
#include <vector>
#include <ctime> // for time

const int GOAL = 47; // Profits needed to win!

int main() {
    srand (time(NULL));
    std::vector<Player> players;
    
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
Typing kkkkk ends the turn early if you get all 'keepers'.

The first merchant to )" << GOAL << " wins, although the other merchants will be given one final turn.\n\nFair winds!\n\n";
    
    std::cout << "Enter player names, one per line (empty line when done):" << std::endl;
    std::string name;
    while(std::getline(std::cin, name)) {
        if(name.empty()) break;
        players.push_back(Player{name}); 
    }
    if(players.empty()) exit(0);

    Player* winner = &players[0];

    int player = rand() % players.size();
    while(players[player].score() < GOAL) {
        if(winner->score() >= GOAL) std::cout << "\n= FINAL ROUND =\n";
        players[player].voyage();
        if (players[player].score() > winner->score()) winner = &players[player];
        if(++player >= players.size()) player = 0;
        std::cout << "\n\nSCORES (of " << GOAL << ")\n==============\n";
        for(Player& p : players) {
            std::cout << p.score() << " " << p.name() << std::endl;
        }
    }    

    std::cout << '\n' << winner->name() << " is the WINNER!!!" << std::endl;
}
