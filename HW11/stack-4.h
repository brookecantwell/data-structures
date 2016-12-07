/*
 * Brooke Cantwell
 *
 * Data Structures
 *
 * 21 November 2016
 *
 * HW #11
 *
 * Stack implementation #4
 *
 * NOTE: There is a  problem in the get_c_string( )
 * and elements are not being returned correctly.
 *
 */

#ifndef STACK_H
#define STACK_H

typedef char stack_element;

typedef struct
{
   stack_element *data;
   int max_size;
   int stack_top_index;
} Stack;

void initialize_stack(Stack *stack_pointer, int max_size);
void destroy_stack(Stack *stack_pointer);
void push(Stack *stack_pointer, stack_element element);
stack_element pop(Stack *stack_pointer);
bool is_Empty(Stack *stack_pointer);
bool is_full(Stack *stack_pointer);

#endif
