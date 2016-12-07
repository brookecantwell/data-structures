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

#ifndef STACK_H
#define STACK_H

typedef char stack_element;

class Stack
{
   public:
      Stack( );
      void initialize_stack(int);
      void destroy_stack( );
      stack_element pop( );
      stack_element top_stack( );
      void push(stack_element);
      int is_empty( );
      int is_full( );
   private:
      stack_element *data;
      int max_size;
      int stack_top_index;
};

#endif
