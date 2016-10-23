/*
 * Brooke Cantwell
 *
 * Data Structures
 *
 * Homework #5
 *
 */

#include <iostream>
#include <iomanip>
#include "stack.h"

using namespace std;

Stack::Stack( )
{
   current_size = -1;
}

int Stack::stack_size( )
{
   return(current_size + 1);
}

bool Stack::is_empty( )
{
   if (current_size == -1)
      return 1;
   else
      return 0;
}

bool Stack::is_full( )
{
   if (current_size == SIZE)
      return 1;
   else
      return 0;
}

coordinates Stack::top( )
{
   return(data[current_size]);
}

coordinates Stack::first( )
{
   return(data[0]);
}

coordinates Stack::pop( )
{
   coordinates stack_element;
   if (!is_empty( ))
   {
      stack_element = data[current_size];
      current_size = current_size - 1;
      return stack_element;
   }
   else
      printf("Could not return data. Stack is empty\n.");
}

coordinates Stack::push(coordinates stack_element)
{
   if (!is_full( ))
   {
      current_size = current_size + 1;
      data[current_size] = stack_element;
   }
   else
      printf("Could not insert data. Stack is full.\n");
}

void Stack::print( )
{
   for (int i = current_size; i >= 0; --i)
      cout << "(" << data[i].row << ", " << data[i].col << ")\n";
}
