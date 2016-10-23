/*
 * Brooke Cantwell
 *
 * CISC2200 Data Structures
 *
 * Homework #5
 *
 * Driver
 *
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>
#include "maze.h"

using namespace std;

//global variables
const int SIZE = 10;
const char SENTINEL = 0;

//function prototypes
bool read_maze(int&, int&, Maze&);
void print_vector(vector<vector<char>>);

main( ) 
{

   //local variables
   Maze this_maze;
   vector <vector<char>> v;	
   int x, y;
   bool file_open = false;
   int success = 0;

   //open and read from file, if there is an error
   //opening the file, prompt the user to input
   //the file name again
   while(!file_open)
      file_open = read_maze(x, y, this_maze);


   while (success < 1)
      success = this_maze.solve(x, y);

   //output
   cout << endl << "Labirynth:" << endl;  
   cout << this_maze << endl;

}

//get data file name, open and read from data file, and get
//starting coordinates, return false if file does not open
bool read_maze(int&x, int&y, Maze&this_maze)
{
   string file_name;
   char c;
   bool file_open;

   cout << "Enter file name: ";
   cin >> file_name;

   ifstream data_file(file_name);

   //if file doesn't open display error message
   //and set file_open to false
   if (!data_file.is_open( ))
   {
      cout << "Error opening file." << endl;
      file_open = false;
   }
   //if the file is open, read in data, get
   //user input for entry point, and make sure
   //user input values do not exceed the size
   else
   {
      file_open = true;  
      data_file >> this_maze;
      data_file.close( );

      cout << this_maze << endl;

      do 
      {
         cout << "Enter entry point coordinates in the form x,y: ";
         cin >> x >> c >> y;
      } while (x > SIZE || y > SIZE);

      //set entrance to a different character to prevent the
      //program from falsely thinking it's reached the exit
      this_maze.set_character('o', x, y);   

   }

   return(file_open);
}
