/*
 * Brooke Cantwell
 *
 * CISC2200 Data Structures
 *
 * Lab #1
 *
 */

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include "maze.h"

using namespace std;

//output method
void Maze::input(istream&in)
{
   int row, col;

   for (row = 0; row < SIZE; row++) 
   {
      for (col = 0; col < SIZE; col++)
         in >> cells[row][col];
   }
}

void Maze::output(ostream&out)
{
   #define LARGE_SQUARE "\u25A0";
   #define SMALL_SQUARE "\u25AB";
   #define TRIANGLE "\u25B2";
   #define BLANK " ";

   int row, col;
   char var;

   for (row = 0; row < SIZE; row++)
   {
      for (col = 0; col < SIZE; col++) {
         var = cells[row][col];
         switch(var)
         {
            case 'n':
               cout << BLANK;
               break;
            case 'w':
               cout << LARGE_SQUARE;
               break;
            case 's':
               cout << SMALL_SQUARE;
               break;
            case 't':
               cout << TRIANGLE;
               break;
         }
      cout << endl;

      }
   }
}

istream& operator>> (istream&in, Maze m)
{
   m.input(in);
   return(in);
}

ostream& operator<< (ostream&out, Maze m)
{
   m.output(out);
   return(out);
}
