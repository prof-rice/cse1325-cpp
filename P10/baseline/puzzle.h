#ifndef __PUZZLE_H
#define __PUZZLE_H

#include <vector>
#include <iostream>

typedef std::vector<std::string> Board;

class Puzzle {
  public:
    Puzzle(std::string name, std::istream& ist);  // read the puzzle and words
    std::string name() const;   // provides the filename
    const Board& board() const; // provides puzzle board
    friend std::ostream& operator<<(std::ostream& ost, const Puzzle& puzzle); 

    // Iterate over puzzle to get the words to be searched
    typedef std::vector<std::string>::iterator iterator;
    typedef std::vector<std::string>::const_iterator const_iterator;
    iterator begin() {return _words.begin();}
    iterator end() {return _words.end();}
   private:
    std::string _name;
    Board _board;
    std::vector<std::string> _words;
};

#endif
