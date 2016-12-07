/*
 * Brooke Cantwell
 *
 * Data Structures
 *
 * Quiz #2
 *
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <iomanip>
#include <stdio.h>

class Stack
{
   public:
      Stack( );
      ~Stack( ) { }
      int stack_size( );
      bool is_empty( );
      bool is_full( );
      int top( );
      int pop( );
      int push(int);
   private:
      static const int STACK_MAX = 10;
      int data[STACK_MAX];
      int current_size;
};

#endif
