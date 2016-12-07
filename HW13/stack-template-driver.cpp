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

typedef struct
{
   double x, y;
} point;

main( )
{
   int i;
   char ch;
   point p;
   Stack<point> s;

   cout << "is_empty = " << s.is_empty( ) << endl;
   cout << "is_full = " << s.is_full( ) << endl;

   s.initialize_stack(10);

   cout << endl << "is_empty = " << s.is_empty( ) << endl;
   cout << "is_full = " << s.is_full( ) << endl << endl;

   cout << fixed << right << setprecision(3);

   i = 0;
   cout << "Pushing points to the stack:" << endl;
   while (!s.is_full( ))
   {
      cout << setw(3) << ++ i << ". ";
      p.x = random(seed);
      p.y = random(seed);
      cout << "p.x = " << setw(5) << p.x << ' ';
      cout << "p.y = " << setw(5) << p.y;
      cout << endl;
      s.push(p);
   }

   i = 0;
   cout << endl << "Popping points from the stack: " << endl;
   while(!s.is_empty( ))
   {
      cout << setw(3) << ++i << ". ";
      p = s.pop( );
      cout << "p.x = " << setw(5) << p.x << ' ';
      cout << "p.y = " << setw(5) << p.y;
      cout << endl;
   }
}

double random(unsigned int&seed)
{
   const int MODULUS = 15749;
   const int MULTIPLIER = 69069;
   const int INCREMENT = 1;
   seed = ((MULTIPLIER * seed) + INCREMENT) % MODULUS;
   return (double) seed / (double) MODULUS;
}
