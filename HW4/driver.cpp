/*
 * Brooke Cantwell
 *
 * Data Structures HW #4
 *
 * 20 October 2016
 *
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <limits.h>

using namespace std;

struct vector_node
{
   int sum;
   vector<int> row_vector;
};

vector<vector_node> v;
unsigned int seed = (unsigned int) time(0);

double random(unsigned int&);
void fill_vector(vector<vector_node>&, int&);
void print_vector(vector<vector_node>);
void trim_vector(vector<vector_node>&, int&);

main( )
{
   int minimum_sum;
   int vector_size = int(5 + 6 * random(seed));
   vector<vector_node> v(vector_size);
   fill_vector(v, minimum_sum);
   cout << "Original Vector:" << endl;
   print_vector(v);
   trim_vector(v, minimum_sum);
   cout << endl << "Trimmed Vector:" << endl;
   print_vector(v);
}

double random(unsigned int&seed)
{
   const int MODULUS = 15748;
   const int MULTIPLIER = 69069;
   const int INCREMENT = 1;
   seed = ((MULTIPLIER * seed) + INCREMENT) % MODULUS;
   return double(seed) / double(MODULUS);
}

void fill_vector(vector<vector_node>&v, int&minimum_sum)
{
   int new_integer, node_vector_size;
   minimum_sum = INT_MAX;

   for (int row = 0; row < v.size( ); ++row)
   {
      node_vector_size= int(1 + 10 * random(seed));
      v[row].sum = 0;
      for (int col = 0; col < node_vector_size; ++col)
      {
         new_integer = int(11 * random(seed));
         v[row].row_vector.push_back(new_integer);
         v[row].sum += new_integer;
      }

      if(v[row].sum < minimum_sum)
         minimum_sum = v[row].sum;

   }
}

void print_vector(vector<vector_node> v)
{
   for (int row = 0; row < v.size( ); ++row)
   {
      cout << "sum = " << setw(3) << v[row].sum << ':';
      for (int col = 0; col < v[row].row_vector.size( ); ++col)
         cout << setw(4) << v[row].row_vector[col];
      cout << endl;
   }
}

void trim_vector(vector<vector_node>&v, int&minimum_sum)
{
   int index = 0;
   int vector_size = v.size( );

   for (int row = 0; row < vector_size; ++row)
   {
      if(v[index].sum > minimum_sum)
         v.erase(v.begin( ) + index);
      else
         ++index;
   }
}
