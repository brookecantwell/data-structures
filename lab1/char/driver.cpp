/*
 * Brooke Cantwell
 *
 * CISC2200 Data Structures
 *
 * Lab #1
 *
 * 12 September 2016
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iomanip>

#define LARGE_BLACK_SQUARE "\u25A0";
#define SMALL_SQUARE "\u25AB";
#define TRIANGLE "\u25B2";

using namespace std;

//global variables
const int SIZE = 10;
const char SENTINEL = 0;

//function prototypes
void print_vector(vector<vector<char>>);
string get_string(char);
void print_array(char arr[ ][SIZE], int[ ]);
void fill_vector(vector<vector<char>>);
int fill_labirynth(vector<vector<char>>, char arr[ ][SIZE]);



main( ) 
{

   char n;
   string line;
   stringstream ss;
   char labirynth[SIZE][SIZE] = {{SENTINEL}};
   vector <vector<char>> v;	
   vector<char> row;
   int spaces[SIZE];

   //open step-1.dat and create stream to read data
   ifstream data_file("step-1.dat");

   //error message if file fails to open
   if (!data_file.is_open( ))
      cout << "Error opening file." << endl;

   //statements to execute after opening file
   else 
   {
      //while there is more data to read in from file
      while (getline(data_file, line))
      {
         ss.clear( );
         ss.str(" ");
         ss << line;
         //while there is more data to read in from row
         while (ss >> n)
            //push character n to 1D row vector	
            row.push_back(n);
         //push 1D row vector to 2D vector
         v.push_back(row);
         //clear vector
         row.clear( );
      } 
   }

   ///close file
   data_file.close( );


   //print array, vector, and labirynth

   cout << "Print Array Before Embedding Vector:" << endl;
//   print_array(labirynth);

   cout << "Print Vector:" << endl;
   print_vector(v); 

   fill_labirynth(v, labirynth);

   cout << endl << "Print Labirynth:" << endl;  
//   print_array(labirynth);

}

//print the 2D vector read in from the file
void print_vector(vector<vector<char>> v)
{
   for (int row = 0; row < v.size( ); row++)
   {
      for (int col = 0; col < v[row].size( ); col++)
         cout << setw(3) << v[row][col];
   cout << endl;
   }
}

//use the character read in from the file to return 
//the unicode character as a string
string get_string(char c) 
{
   string display_string;

   switch(c)
   {
      case 'n':
         display_string = " ";
         break;
      case 'w':
         display_string = LARGE_BLACK_SQUARE;
         break;
      case 's':
         display_string = SMALL_SQUARE;
         break;
      case 't':
         display_string = TRIANGLE;
         break;
   }

   return(display_string);
}

//print the 2D labirynth array
void print_array(char labirynth[ ][SIZE], int space_arr[ ])
{

   cout << setw(3) << " ";

   for (int i = 0; i < SIZE; i++)
      cout << left << setw(3) << i + 1;
   cout << endl;

   for (int row = 0; row < SIZE; row++)
   {
      cout << row + 1;
      for (int i = 0; i < space_arr[row]; i++)
         cout << setw(3) << ' ';


      for (int col = 0; row < SIZE; col++)
      {
         string display_string = get_string(labirynth[row][col]);

         cout << left <<  setw(3) << display_string;
      }
      cout << endl;
   }
   cout << endl;
}

//initialize the 2D vector with the sentinal value
void fill_vector(vector <vector<char>> v)
{
   for (int row = 0; row < v.size( ); row++)
   {
      for (int col = 0; col < v[row].size( ); col++)
         v[row][col] = SENTINEL;
   }
}

//embed the 2D vector into the labirynth array
int fill_labirynth(vector <vector<char>> v, char labirynth[ ][SIZE])
{
   int line_size, spaces;
   int space_arr[SIZE];

   for (int i = 0; i < v.size( ); i++)
   {
      line_size = v[i].size( );
      int spaces = (SIZE - line_size) / 2;

      for (int j = 0; j < v[i].size( ); j++)
         labirynth[i][j+spaces] = v[i][j];

      space_arr[i] = spaces;

   }

//   cout << "SPACE TEST" << endl;
//   for (int i = 0; i < space_arr[i]; i++)
//      cout << 1 << ' ';

   print_array(labirynth, space_arr);

}
