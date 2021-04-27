#include "solver.h"
#include "logger.h"

Solver::Solver(const Puzzle& puzzle) : _puzzle{puzzle} { }
Solution Solver::solve(std::string word) const {
    LOG("### Searching for word " + word + ":");
    const Board& board = _puzzle.board();
    for(int row=0; row<board.size(); ++row) {
        LOG("Row "+std::to_string(row));
        for(int col=0; col<board[row].size(); ++col) {
            // LOG("("+std::to_string(col)+","+std::to_string(row)+") ");
            for(Direction d : direction_vector) {
                //LOG("("+std::to_string(col)+","+std::to_string(row)+","+direction_to_string.at(d)+") ");
                try {
                    int x=col;
                    int y=row;
                    bool found=true;
                    
                    for(char c : word) {
                        if(c != board.at(y).at(x)) {
                            found = false;
                            break;
                        }
                        x += offsets.at(d).first;
                        y += offsets.at(d).second;
                    }
                    if(found) {
                        LOG("### FOUND ###");
                        Solution solution{_puzzle.name(), word, col, row, d};
                        return solution;
                    }
                } catch(...) { // We ran off the board
                    LOG("#offboard#");
                }
            }
        }
    }
    throw std::runtime_error{"Unable to find " + word};
}

