/*
 * Brooke Cantwell
 *
 * Data Structures
 *
 * Homework #7
 *
 * 31 October 2016
 *
 */

#include <iostream>
#include <cstdlib>
#include <time.h>
#include "watch.h"

using namespace std;

Watch::Watch( )
{
   ticks_passed = clock( );
}

void Watch::start( )
{
   ticks_passed = clock( );
}

void Watch::stop( )
{
   ticks_passed = clock( ) - ticks_passed;
   if (ticks_passed == clock_t(-1))
   {
      cout << "Clock overflow" << endl;
      exit(1);
   }
}

void Watch::delay(int duration)
{
   for (int i = 0; i < duration; ++i)
   { };
}

double Watch::seconds( )
{
   return (double(ticks_passed) / CLOCKS_PER_SEC);
}

double Watch::minutes( )
{
   return (double(ticks_passed) / CLOCKS_PER_SEC / 60);
}

double Watch::hours( )
{
   return (double(ticks_passed) / CLOCKS_PER_SEC / 60 / 60);
}
