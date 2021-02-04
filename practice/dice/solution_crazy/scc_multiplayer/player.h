#ifndef __PLAYER_H
#define __PLAYER_H

#include <string>

class Player {
  public:
    Player(std::string name);
    std::string name();
    int score();
    void voyage();
  private:
    std::string _name;
    int _score;
};  

#endif

