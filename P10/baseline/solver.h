#ifndef __SOLVER_H
#define __SOLVER_H

#include "puzzle.h"
#include "solution.h"

class Solver {
  public:
    Solver(const Puzzle& puzzle);
    Solution solve(std::string word) const;
  private:
    const Puzzle& _puzzle;
};

#endif
