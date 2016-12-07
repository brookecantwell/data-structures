#include <iostream>
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
   if (current_size == STACK_MAX)
      return 1;
   else
      return 0;
}

example_structure Stack::top( )
{
   return data[current_size];
}

example_structure Stack::pop( )
{
   example_structure stack_element;
   if (!is_empty( ))
   {
      stack_element = data[current_size];
      current_size = current_size - 1;
      return stack_element;
   }
   else
      cout << "Could not return data. Stack is empty." << endl;
}

example_structure Stack::push(example_structure stack_element)
{
   if (!is_full( ))
   {
      current_size = current_size + 1;
      data[current_size] = stack_element;
   }
   else
      cout << "Could not insert data. Stack is full." << endl;
}
