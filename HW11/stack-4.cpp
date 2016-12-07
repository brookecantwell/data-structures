/*
 * Brooke Cantwell
 *
 * Data Structures
 *
 * HW #11
 *
 */

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include "stack-4.h"

using namespace std;

void initialize_stack(Stack *stack_pointer, int max_size)
{
   stack_element *new_data;
   new_data = (stack_element*)malloc(sizeof(stack_element) * max_size);
   if (stack_pointer == NULL)
   {
      cerr << "Insufficient memory to initialize stack." << endl;
      exit(1);
   }
   stack_pointer -> data = new_data;
   stack_pointer -> max_size = max_size;
   stack_pointer -> stack_top_index = -1;
}

void destroy_stack(Stack *stack_pointer)
{
   free(stack_pointer -> data);
   stack_pointer -> data = NULL;
   stack_pointer -> max_size = 0;
   stack_pointer -> stack_top_index = -1;
}

void push(Stack *stack_pointer, stack_element element)
{
   if (is_full(stack_pointer))
   {
      cerr << "Can't push on stack (stack is full)." << endl;
      exit(1);
   }
   stack_pointer -> data[++stack_pointer -> stack_top_index] = element;
}

stack_element pop(Stack *stack_pointer)
{
   if(is_Empty(stack_pointer))
   {
      cerr << "Can't pop from stack (stack is empty)." << endl;
      exit(1);
   }
   return(stack_pointer -> data[stack_pointer -> stack_top_index--]);
}

bool is_Empty(Stack *stack_pointer)
{
   return(stack_pointer -> stack_top_index < 0);
}

bool is_full(Stack *stack_pointer)
{
   return(stack_pointer -> stack_top_index >= stack_pointer -> max_size);
}
