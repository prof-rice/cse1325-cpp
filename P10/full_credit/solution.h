#ifndef __SOLUTION_H
#define __SOLUTION_H

#include <string>
#include <vector>
#include <map>
#include <utility>

enum class Direction {N, NE, E, SE, S, SW, W, NW};
std::ostream& operator<<(std::ostream& ost, const Direction& direction);
const std::map<Direction, std::string> direction_to_string {
  {Direction::N,  "north"},
  {Direction::NE, "northeast"},
  {Direction::E,  "east"},
  {Direction::SE, "southeast"},
  {Direction::S,  "south"},
  {Direction::SW, "southwest"},
  {Direction::W,  "west"},
  {Direction::NW, "northwest"},
};  
const std::map<Direction, std::pair<int,int>> offsets {
  {Direction::N,  std::pair{ 0,-1}},
  {Direction::NE, std::pair{ 1,-1}},
  {Direction::E,  std::pair{ 1, 0}},
  {Direction::SE, std::pair{ 1, 1}},
  {Direction::S,  std::pair{ 0, 1}},
  {Direction::SW, std::pair{-1, 1}},
  {Direction::W,  std::pair{-1, 0}},
  {Direction::NW, std::pair{-1,-1}},
};

const std::vector<Direction> direction_vector {
  Direction::N, Direction::NE, Direction::E, Direction::SE,
  Direction::S, Direction::SW, Direction::W, Direction::NW,
};

class Solution {
  public:
      Solution(std::string name, std::string word, int x, int y, Direction direction);

      std::string word() const;
      int x() const;
      int y() const;
      Direction direction() const; 
      bool operator<(const Solution& rhs);
      friend std::ostream& operator<<(std::ostream& ost, const Solution& solution); 
  private:
    std::string _name;
    std::string _word;
    int _x;
    int _y;
    Direction _direction;
};

#endif


