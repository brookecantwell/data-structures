/*
 * Brooke Cantwell
 *
 * Data Structures
 *
 * Maze Class Header File
 *
 */

#ifndef MAZE_H
#define MAZE_H

#include <iostream>

using namespace std;

class Maze 
{
   //global functions
   //operator overload functions
   friend istream& operator>>(istream&, Maze&);
   friend ostream& operator<<(ostream&, Maze);

   public:
      void set_character(char, int, int);
      int solve(int, int);
   protected:
      int recursive_solve(int, int); 
      void input(istream&);
      void output(ostream&);
      static const int SIZE = 10;
      char Cells[SIZE][SIZE];
};

#endif
