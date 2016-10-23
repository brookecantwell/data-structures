/*
 * Brooke Cantwell
 *
 * Data Structures
 *
 * Homework #5
 *
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

struct coordinates
{
   int row, col;
};

class Stack
{
   friend istream& operator>>(istream&, Stack&);
   friend ostream& operator<<(ostream&, Stack);

   public:
      Stack( );
      ~Stack( ) { }
      int stack_size( );
      bool is_empty( );
      bool is_full( );
      coordinates top( );
      coordinates pop( );
      coordinates push(coordinates element);
      coordinates first( );
      void print( );
   protected:
      void input(istream&);
      void output(ostream&);
      static const int SIZE = 20;
      int current_size;
      coordinates data[SIZE];
};

#endif
