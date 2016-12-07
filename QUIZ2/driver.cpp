#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "stack.h"
#include <ctime>

using namespace std;

unsigned int seed = (unsigned) time(0);
const int SIZE = 10;

double random(unsigned int&);
void fill_stack(Stack&);
void print_stack(Stack);
void reverse_stack(Stack&);
void swap_stack(Stack&, Stack&);

main( )
{
   Stack stack_1;

   fill_stack(stack_1);
   cout << "Original Stack" << endl;
   print_stack(stack_1);   

   reverse_stack(stack_1);
 
   cout << "Reversed Stack" << endl;
   print_stack(stack_1);
}

double random(unsigned int&seed)
{
   const int MODULUS = 15748;
   const int MULTIPLIER = 69069;
   const int INCREMENT = 1;

   seed = ((MULTIPLIER * seed) + INCREMENT) % MODULUS;

   return double(seed) / double(MODULUS);
}

void fill_stack(Stack&s)
{
   int new_integer;

   for (int i = 0; i < SIZE; i++)
   {
      new_integer = int(1 + 10 * random(seed));
      s.push(new_integer);
   }

}

void print_stack(Stack s)
{
   int local_data;

   for (int i = 0; i < SIZE; i++)
   {
      local_data = s.pop( );
      cout << left << setw(4) << local_data;
   }
   cout << endl;
}

void reverse_stack(Stack&original_stack)
{
   int local_data;
   Stack local_stack_1, local_stack_2;

   swap_stack(original_stack, local_stack_1);
   swap_stack(local_stack_1, local_stack_2);
   swap_stack(local_stack_2, original_stack);

}

void swap_stack(Stack&s1, Stack&s2)
{
   int local_data;

   for (int i = 0; i < SIZE; i++)
   {
      local_data = s1.pop( );
      s2.push(local_data);
   }
}
