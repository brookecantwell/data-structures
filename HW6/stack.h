/*
 * Brooke Cantwell
 *
 * Data Structures
 *
 * Homework #6
 *
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <iomanip>
#include <stdio.h>

//#define STACK_MAX = 10;

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
      int push(int stack_element);
   private:
      static const int STACK_MAX = 10;
      int data[STACK_MAX];
      int current_size;
};

#endif
