#ifndef MAZE_H
#define MAZE_H

#include <iostream>

using namespace std;

const int SIZE = 10;

class Maze {
   public:
      void input(istream&);
      void output(ostream&);	
   protected:
      char cells[SIZE][SIZE];

};

#endif
