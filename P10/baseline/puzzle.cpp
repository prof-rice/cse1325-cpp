#include "puzzle.h"
#include <algorithm>
#include <cmath>
#include <iomanip>

Puzzle::Puzzle(std::string name, std::istream& ist) : _name{name} {
    // If the stream isn't readable, thrown an exception
    if(!ist) throw std::runtime_error{"Bad stream"};

    // Loop for as long as lines can be read from the stream
    std::string line;
    int row = 0;
    int rowlen = 0;
    while(ist) {
        std::getline(ist, line);
        
        // Skip blank lines before the puzzle
        // Stop loading the puzzle itself on a following empty row        
        if(line.empty()) {
            if(row > 0) break;
            else continue;
        }

        // Skip solution (if present)
        if(line == "Solution:") {
            while(!line.empty()) std::getline(ist, line);
            while(line.empty()) std::getline(ist, line);
        }  // line contains the first row of the puzzle at this point
        
        // std::remove all spaces from line by moving all non-space characters to the left,
        //   returning an iterator to the last non-space char (length of line is unchanged)
        // std::string::erase erases the unneeded characters to the right of the survivors
        std::string::iterator end_pos = std::remove(line.begin(), line.end(), ' ');
        line.erase(end_pos, line.end());
       
        // Remember the length of the row (validate that all are the same length)
        if(rowlen == 0) rowlen = line.size();
        if(line.size() != rowlen) {
            std::cerr << line.size() << ' ' << rowlen << '\n' << line << '\n';
            throw std::runtime_error{"Bad puzzle row " + std::to_string(row)};
        }
        
        // Valid row found - add it to the puzzle board!
        _board.push_back(line);
        ++row;
    }
    
    // Load the hidden words to be found
    while(ist >> line) _words.push_back(line);
}

std::string Puzzle::name() const {return _name;}
const Board& Puzzle::board() const {return _board;}

std::ostream& operator<<(std::ostream& ost, const Puzzle& puzzle) {
    ost << "From file " << puzzle.name() << "\n\n";
    
    int width = 0; // of row / column numbers
    int n = puzzle._board[0].size();
    while (n) {
        n /= 10;
        ++width;
    }
    
    // print column numbers
    ost << std::setw(width) << ' ';
    for(int i=0; i<puzzle._board[0].size(); ++i)
        ost << std::setw(width) << i;
    ost << '\n';
    
    n = 0;    
    for(auto row : puzzle._board) {
        ost << std::setw(width) << n++;
        for(char c : row)
            ost << std::setw(width) << c;
        ost << '\n';
    }
    ost << '\n';
    return ost;
}
