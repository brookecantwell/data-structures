/*
 * Brooke Cantwell
 *
 * Data Structures
 *
 * Homework #13
 *
 * 5 December 2016
 *
 */

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>

using namespace std;

template <class T>
class Stack
{
   public:
      Stack( )
      {
         T *data = NULL;
         max_size = 0;
         stack_top_index = -1;
      }
      ~Stack( )
      {
      }
      void initialize_stack(int size)
      {
         T *new_data;
         new_data = (T*)malloc(sizeof(T) * size);
         if (new_data == NULL)
         {
            cerr << "Insufficient memory to initialize stack." << endl;
            exit(1);
         }
         data = new_data;
         max_size = size;
         stack_top_index = -1;
      }
      void destroy_stack( )
      {
         free(data);
         data = NULL;
         max_size = 0;
         stack_top_index = -1;
      }
      void push(T element)
      {
         if (is_full( ))
         {
            cerr << "Can't push on stack, it is full." << endl;
            exit(1);
         }
         data[++stack_top_index] = element;
      }
      T pop( )
      {
         if (is_empty( ))
         {
            cerr << "Can't pop from stack, it is empty." << endl;
            exit(1);
         }
         return (data[stack_top_index--]);
      }
      int is_empty( )
      {
         return (stack_top_index < 0);
      }
      int is_full( )
      {
         //conditional statement prevents is_full from returning
         //true when the max_size is 0 and the stack_top_index
         //is -1
         if (max_size == 0)
            return max_size;
         else
            return(stack_top_index >= max_size - 1);
      }
   private:
      T *data;
      int max_size;
      int stack_top_index;
};

#endif
