/*
 * Brooke Cantwell
 *
 * Data Structures
 *
 * Homework #12
 *
 * 1 December 2016
 *
 */

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include "stack-5.h"

using namespace std;

Stack::Stack( )
{
   data = NULL;
   max_size = 0;
   stack_top_index = -1;
}

void Stack::initialize_stack(int size)
{
   stack_element *new_data;
   new_data = (stack_element*)malloc(sizeof(stack_element) * size);
   if (new_data == NULL)
   {
      cerr << "Insufficient memory." << endl;
      exit(1);
   }
   data = new_data;
   max_size = size;
   stack_top_index = -1;
}

void Stack::destroy_stack( )
{
   free(data);
   data = NULL;
   max_size = 0;
   stack_top_index = -1;
}

void Stack::push(stack_element element)
{
   if (is_full( ))
   {
      cerr << "Stack is full, can't push element." << endl;
      exit(1);
   }
   data[++stack_top_index] = element;
}

stack_element Stack::pop( )
{
   if (is_empty( ))
   {
      cerr << "Can't pop, stack is empty." << endl;
      exit(1);
   }
   return data[stack_top_index--];
}

stack_element Stack::top_stack( )
{
   if (is_empty( ))
   {
      cerr << "Can't access top element, stack is empty." << endl;
      exit(1);
   }
   return data[stack_top_index];
}

int Stack::is_empty( )
{
   return(stack_top_index < 0);
}

int Stack::is_full( )
{
   return(stack_top_index >= max_size - 1);
}
