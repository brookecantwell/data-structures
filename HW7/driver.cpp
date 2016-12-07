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
#include <iomanip>
#include <vector>
#include "watch.h"

using namespace std;

void print_times(Watch, double&);
void get_minimum_time(Watch, double&);

main( )
{
   double min_time;

   //FIRST TEST CASE
   Watch stop_watch1;
   stop_watch1.start( );
   vector<int> v1;

   for (int i = 0; i < 10000; ++i)
      //push value of 1 to the vector 100000 times
      v1.push_back(1);

   stop_watch1.stop( );
   cout << "Stop Watch #1:" << endl;
   print_times(stop_watch1, min_time);


   //SECOND TEST CASE
   Watch stop_watch2;
   stop_watch2.start( );
   vector<int> v2;
   vector<int>::iterator p = v2.begin( );

   for (int i = 0; i < 10000; ++i)
      //insert 1 at vector beginning 100000 times
      p = v2.insert(p, 1);   

   stop_watch2.stop( );
   cout << "Stop Watch #2:" << endl;
   print_times(stop_watch2, min_time);

 
   //THIRD TEST CASE
   Watch stop_watch3;
   stop_watch3.start( );

   //declare a vector of size 10000 initialized to 1
   vector<int> v3(10000, 1);

   stop_watch3.stop( );
   cout << "Stop Watch #3:" << endl;
   print_times(stop_watch3, min_time);

   cout << "Shortest Time: " << min_time << " seconds." << endl;

}

void print_times(Watch stop_watch, double&min_time)
{
   cout << scientific << setprecision(3) << left;

   cout << setw(10) << "Seconds: " << stop_watch.seconds( ) << endl;
   cout << setw(10) << "Minutes: " << stop_watch.minutes( ) << endl;
   cout << setw(10) << "Hours: " << stop_watch.hours( ) << endl << endl;

   get_minimum_time(stop_watch, min_time);
}

void get_minimum_time(Watch stop_watch, double&min_time)
{
   static bool first = true;

   //set original minimum time to the first stop watch seconds
   if (first == true)
   {
      min_time = stop_watch.seconds( );
      first = false;
   }

   if (stop_watch.seconds( ) < min_time)
      min_time = stop_watch.seconds( );

}
