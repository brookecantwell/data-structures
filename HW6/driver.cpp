/*
 * Brooke Cantwell
 *
 * Data Structures
 *
 * Homework #6
 *
 */

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "stack.h"

unsigned int seed = (unsigned) time(0);

double random(unsigned int&seed);

using namespace std;

main( )
{
   int local_data;
   Stack s_1;
  
   cout << "s_1.is_empty( ) = " << s_1.is_empty( ) << endl;
   cout << "s_1.stack_size( ) = " << s_1.stack_size( ) << endl;
   cout << "local_data:" << endl;

   for (int i = 0; i < 10; ++i)
   {
      local_data = int(10*random(seed));
      cout << local_data << endl;
      s_1.push(local_data);
   }

   printf("\nElement at the top of the stack is %d.\n", s_1.top( ));

   printf("Stack elements are:\n");

   while (!s_1.is_empty( ))
   {
      int local_data = s_1.pop( );
      printf("%d\n", local_data);
   }

   printf("Stack full: %s\n", s_1.is_full( ) ? "true":"false");
   printf("Stack empty: %s\n", s_1.is_empty( ) ? "true":"false");

}

double random(unsigned int&seed)
{
   const int MODULUS = 15748;
   const int MULTIPLIER = 69069;
   const int INCREMENT = 1;

   seed = ((MULTIPLIER * seed) + INCREMENT) % MODULUS;

   return double(seed) / double(MODULUS);
}
