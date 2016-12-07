/*
 * Brooke Cantwell
 *
 * Data Structures
 *
 * Homework #7
 *
 * 31 October 2016
 *
 * Declare and populate a 1D vector in
 * 3 substantially different ways and 
 * measure which is the most efficient
 * / takes the shortest time.
 *
 */

#undef WATCH_H
#ifndef WATCH_H
#define WATCH_H

#include <time.h>

class Watch
{
   public:
      Watch( );
      void start( );
      void stop( );
      void delay(int);
      double seconds( );
      double minutes( );
      double hours( );
   private:
      clock_t ticks_passed;
};

#endif
