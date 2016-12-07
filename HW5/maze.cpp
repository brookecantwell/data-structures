/*
 * Brooke Cantwell
 *
 * CISC2200 Data Structures
 *
 * Maze Class Implementation File
 *
 */

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include "maze.h"

using namespace std;

//GLOBAL METHODS

//operator overload methods for input & output

istream& operator>>(istream&in, Maze&m)
{
   m.input(in);
   return(in);
}

ostream& operator<<(ostream&out, Maze m)
{
   m.output(out);
   return(out);
}

//intput and output methods
void  Maze::input(istream&in)
{
   int row, col;
   

   for (row = 0; row < SIZE; row++) 
   {
      for (col = 0; col < SIZE; col++)
         in >> Cells[row][col];
   }
}

void Maze::output(ostream&out)
{
   #define LARGE_SQUARE "\u25A0";
   #define SMALL_SQUARE "\u25AB";
   #define TRIANGLE "\u25B2";
   #define BLANK " ";
   #define FOOTPRINT "\u25CB";
   #define RIGHT "\u2192";
   #define LEFT "\u2190";
   #define DOWN "\u2193";
   #define UP "\u2191";

   int row, col;
   char var;

   cout << setw(3) << " ";

   for (int i = 0; i < SIZE; i++)
      cout << left << setw(3) << i;

   cout << endl;

   for (row = 0; row < SIZE; row++)
   {
      cout << setw(3) << row ;

      for (col = 0; col < SIZE; col++) 
      {
         var = Cells[row][col];
         switch(var)
         {
            case 'n':
               cout << setw(5) << BLANK;
               break;
            case 'w':
               cout << setw(5) << LARGE_SQUARE;
               break;
            case 's':
               cout << setw(5) << SMALL_SQUARE;
               break;
            case 't': //entry & exit (at beginning)
            case 'o': //entry after being reset
               cout << setw(5) << TRIANGLE;
               break;
            case 'U':
               cout << setw(5) << UP;
               break;
            case 'D':
               cout << setw(5) << DOWN;
               break;
            case 'L':
               cout << setw(5) << LEFT;
               break;
            case 'R':
               cout << setw(5) << RIGHT;
               break;
            default:
               cout << setw(5) << SMALL_SQUARE;
         }

      }
   cout << endl;
   }
}

//set_character( ) method, used to differentiate
//the maze entrance from exit after user input
//for enterance coordinates
void Maze::set_character(char c, int x, int y)
{
   Cells[x][y] = c;   
}

//wrapper method for recursive_solve( ) method
int Maze::solve(int x, int y)
{
   int success;

   success = recursive_solve(x, y);
 
   coordinates temp = stack_data.first( );

   //mark the last spot visitied if it is successful
   //with a triangle isntead of a footprint
   if (success > 0)
   {
      Cells[temp.row][temp.col] = 't';
      stack_data.print( );
   }

}

//recursive_solve( ) method, finds maze path
int Maze::recursive_solve(int x, int y)
{
   int success = 0;
   coordinates local_data;   

   switch(Cells[x][y])
   {
      case 't': //exit
         success = 1;
         break;
      case 'w': //wall
         success = 0;
         break;
      case 'o':
         if (x == 0)
            success = recursive_solve(x + 1, y) || recursive_solve(x + 1, y + 1) || recursive_solve(x + 1, y - 1);
         else
         if (x == SIZE - 1)
            success = recursive_solve(x - 1, y) || recursive_solve(x - 1, y + 1) || recursive_solve(x - 1, y - 1);
         if (y == 0)
            success = recursive_solve(x, y + 1) || recursive_solve(x + 1, y + 1) || recursive_solve(x - 1, y + 1);
         else
         if (y == SIZE - 1)
            success = recursive_solve(x, y - 1) || recursive_solve(x + 1, y - 1) || recursive_solve(x - 1, y - 1);
         break;
      case 'f': //footprint
         success = 0;
         break;
      default:

         Cells[x][y] = 'f'; //footprint

         success = recursive_solve(x + 1, y) || recursive_solve(x - 1, y) || recursive_solve(x, y + 1) || recursive_solve(x, y - 1);
         break;

   }


   //determine direction and push new coordinate to the stack
   if (success > 0)
   {
      coordinates temp = stack_data.top( );
      
      local_data.row = x;
      local_data.col = y;

      stack_data.push(local_data);

      if (local_data.row > temp.row)
         Cells[x][y] = 'U';
      else
      if (local_data.row < temp.row)
         Cells[x][y] = 'D';
      else
      if (local_data.col > temp.col)
         Cells[x][y] = 'L';
      else
      if (local_data.col < temp.col)
         Cells[x][y] = 'R';

   }

   return(success);

}
