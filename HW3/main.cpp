/*
 * Brooke Cantwell
 *
 * Data Structures - HW #3
 *
 * 13 October 2016
 *
 */

#include <iostream>
#include <iomanip>
#include <stdio.h>

const int MAXSIZE = 10;
int stack[MAXSIZE];
int current_size = -1;
unsigned int seed = 1;

int is_empty( )
{
   if (current_size == -1)
      return 1;
   else
      return 0;
}

int is_full( )
{
   if (current_size == MAXSIZE)
      return 1;
   else
      return 0;
}

int top( )
{
   return stack[current_size];
}

int pop( )
{
   int data;

   if (!is_empty( ))
   {
      data = stack[current_size];
      current_size = current_size - 1;
      return(data);
   }
   else
      printf("Could not retrieve data. Stack is empty.\n");

}

int push(int data)
{
   if (!is_full( ))
   {
      current_size = current_size + 1;
      stack[current_size] = data;
   }
   else
      printf("Could not insert data. Stack is full.\n");
}

double random(unsigned int&seed)
{
   const int MODULUS = 15748;
   const int MULTIPLIER = 69069;
   const int INCREMENT = 1;

   seed = ((MULTIPLIER * seed) + INCREMENT) % MODULUS;

   return double(seed) / double(MODULUS);
}

main( )
{
   int local_data;

   //test is empty function
   if (is_empty( ))
      std::cout << "The stack is empty.\n";
   else
      std::cout << "The stack is not empty.\n";

   //push random values to every space in stack
   for (int i = 0; i < MAXSIZE; i++)
   {
      local_data = 10*random(seed);
      push(local_data);
   }

   std::cout << "Stack with random numbers and push function\n";
   for (int i = 0; i < current_size; i++)
      std::cout << stack[i] << ' ';
   std::cout << '\n';

   //test top function
   local_data = top( );
   std::cout << "Top function: " << local_data << '\n';
   std::cout << "Current stack:\n";
   for (int i = 0; i < current_size; i++)
      std::cout << stack[i] << ' ';
   std::cout << '\n';

   //test pop function
   local_data = pop( );

   std::cout << "Stack after pop function (removing top element of the stack):\n";
   std::cout << "Elemet removed: " << local_data << '\n';
   for (int i = 0; i < current_size; i++)
      std::cout << stack[i] << ' ';
   std::cout << '\n';

}

/*
 * ERROR IN THE ORIGINAL PROGRAM
 *
 * In the original program the random function returned an
 * integer, causing all of the elements in the stack to be
 * zero after the random function was called. If the return
 * type is changed to a double, the double is returned to
 * the driver function, and because local_data is an integer
 * the decimal points of the double are truncated and the
 * resulting value is a random integer.
 *
 */

