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

using namespace std;

const int SIZE = 10, SENTINAL = 0;

//printVector function, prints a 2 dimensional vector
void printVector(vector<vector<int>> vec)
{
   for (int r = 0; r < vec.size( ); r++)
   {
      for (int c = 0; c < vec[r].size( ); c++)
         cout << vec[r][c] << ' ';
      cout << endl;
   }
}

//printArray function, prints 2 dimensional array
void printArray(int arr[ ][SIZE])
{
   for (int r = 0; r < SIZE; r++)
   {
      for (int c = 0; c < SIZE; c++)
         cout << arr[r][c] << ' ';
      cout << endl;
   }
   cout << endl;
}

void fillVector(vector <vector<int>> vec)
{
   for (int r = 0; r < vec.size( ); r++)
   {
      for (int c = 0; c < vec[r].size( ); c++)
         vec[r][c] = 0;
   }
}

//fillLabirynt, fills 2 dimensional labitynt array with vector
void fillLabirynt(vector <vector<int>> vec, int arr[ ][SIZE], int rows)
{
   for (int i = 0; i < vec.size( ); i++)
   {
      int lineSize = vec[i].size( );
      int spaces = (SIZE - lineSize) / 2;

      for (int j = 0; j < vec[i].size( ); j++)
         arr[i][j + spaces] = vec[i][j];
   }
}

main( ) {

   int n;
   string line;
   stringstream ss;
   ifstream myFile("step-1.dat");
   int arr[SIZE][SIZE] = {{0}};
   vector <vector<int>> vec;	
   int rows = 0;

   if (!myFile.is_open( ))
      cout << "Error opening file." << endl;
   else {
      while (getline(myFile, line)) {
         vector<int> row;
         ss.clear( );
         ss.str(" ");
         ss << line;
         while (ss >> n)	
            row.push_back(n);
         vec.push_back(row);
         rows++;
      } 
   }

   myFile.close( );


   cout << "Print Array:" << endl;
   printArray(arr);

   cout << "Print Vector:" << endl;
   printVector(vec); 

   fillLabirynt(vec, arr, rows);

   cout << endl << "Print Labirynt:" << endl;  
   printArray(arr);

}
