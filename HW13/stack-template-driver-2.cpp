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

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>
#include "stack-template.h"

using namespace std;

unsigned int seed = 7;

double random(unsigned int&);

template <typename T>
void print_stack(Stack<T> s)
{
   T element;
   int i = 0;
   while (!s.is_empty( ))
   {
      element = s.pop( );
      cout << element << ' ';
   }
   cout << endl;
}

template <typename T>
void test_stack(Stack<T> s)
{
   cout << "is_empty = " << s.is_empty( ) << endl;
   cout << "is_full = " << s.is_full( ) << endl;
   cout << endl;
}

main( )
{
   Stack<int> int_stack;
   Stack<char> char_stack;
   int i;

   cout << "Test stacks:" << endl;
   cout << "int_stack" << endl;
   test_stack(int_stack);
   cout << "char_stack" << endl;
   test_stack(char_stack);

   int_stack.initialize_stack(10);
   char_stack.initialize_stack(10);

   cout << fixed << right << setprecision(3);

   i = 0;
   cout << "Pushing integers to the stack:" << endl;
   while (!int_stack.is_full( ))
   {
      int random_int = int(1 + 10 * random(seed));
      cout << random_int << ' ';
      int_stack.push(random_int);
   }
   

   i = 0;
   cout << "Pushing characters to the stack:" << endl;
   while (!char_stack.is_full( ))
   {
      char random_char = char('a' + 25 * random(seed));
      cout << random_char << ' ';
      char_stack.push(random_char);
   }

   cout << endl << endl << "Test stacks:" << endl;
   cout << "int_stack" << endl;
   test_stack(int_stack);
   cout << "char_stack" << endl;
   test_stack(char_stack);
   cout << endl;

   cout << "Popping elements from the stacks using templated function" << endl;
   cout << "Integer stack:" << endl;
   print_stack(int_stack);
   cout << "Character stack:" << endl;
   print_stack(char_stack);

   cout << endl << "Destroy stacks:" << endl;
   int_stack.destroy_stack( );
   char_stack.destroy_stack( );

   cout << endl << "Test stacks:"<< endl;
   cout << "int stack" << endl;
   test_stack(int_stack);
   cout << "char stack" << endl;
   test_stack(char_stack);
}
double random(unsigned int&seed)
{
   const int MODULUS = 15749;
   const int MULTIPLIER = 69069;
   const int INCREMENT = 1;
   seed = ((MULTIPLIER * seed) + INCREMENT) % MODULUS;
   return (double) seed / (double) MODULUS;
}
