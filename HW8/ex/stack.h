#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <iomanip>
#include <stdio.h>

struct example_structure
{
   int i;
   char c;
};

class Stack
{
   public:
      Stack( );
      ~Stack( ) { }
      int stack_size( );
      bool is_empty( );
      bool is_full( );
      example_structure top( );
      example_structure pop( );
      example_structure push(example_structure stack_element);
   private:
      static const int STACK_MAX = 10;
      example_structure data[STACK_MAX];
      int current_size;
};

#endif
