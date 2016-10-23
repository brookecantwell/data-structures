#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

const int SIZE = 10, BLANK = 0;

void print_vector(vector<vector<int>> v);
void print_labirynth(const int labirynth[ ][SIZE]);
void fill_labirynth(int labirynth[ ][SIZE], const int P);
void fill_labirynth(int labirynth[ ][SIZE], vector<vector<int>> v);

main( ) {
   int n;
   string line;
   int labirynth[SIZE][SIZE] = {{0}};

   ifstream data_file("step-1.dat");

   print_labirynth(labirynth);

   vector<vector<int>> v;

   vector<int> line_vector;

   while(getline(data_file, line)) {
      stringstream ss(line);
      while (ss >> n)
         line_vector.push_back(n);
      v.push_back(line_vector);
   }

   fill_labirynth(labirynth, BLANK); 
   print_labirynth(labirynth);
   fill_labirynth(labirynth, v);
   print_labirynth(labirynth);

   return 0;
}

void print_vector(vector<vector<int>> v) {
   for (int row = 0; row < v.size( ); ++row) {
      for (int col = 0; col < v[row].size( ); ++col)
         cout << setw(3) << v[row][col];
      cout << endl;
   }
}

void print_labirynth(const int labirynth[ ][SIZE]) {
   for (int row = 0; row < SIZE; ++row) {
      for (int col = 0; col < SIZE; ++col) 
         cout << labirynth[row][col];
      cout << endl;
   }
}

void fill_labirynth(int labirynth[ ][SIZE], const int P) {
   for (int row = 0; row < SIZE; ++row) {
      for (int col = 0; col < SIZE; ++col)
         labirynth[row][col] = P;
   }
}

void fill_labirynth(int labirynth[ ][SIZE], vector<vector<int>> v) {
   int filling_index;

   for(int row = 0; row < SIZE; ++row) {
      if(row < v.size( )) {
         filling_index = (SIZE - v[row].size( ))/2;
         for (int col = 0; col < SIZE; ++col)
            labirynth[row][filling_index] = v[row][col];
      }
   }
}
 
