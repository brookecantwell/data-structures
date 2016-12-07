/*
 * Brooke Cantwell
 *
 * Data Structures
 *
 * Homework #8
 *
 * 7 November 2016
 *
 * Write a program that creates a vector of
 * structures (with up to 10 elements), each
 * containing an integer value and a double
 * value, and use the sort function to sort
 * the vector in ascending order by integer
 * and descending order by double.
 *
 */

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <vector>

using namespace std;

unsigned int seed = (unsigned int) time(0);

struct int_and_double
{
   int m;
   double x;
};

double random(unsigned int&);
void fill_vector(vector<int_and_double>&);
void print_vector(vector<int_and_double>);
bool cmp_ints(const int_and_double&, const int_and_double&);
bool cmp_doubles(const int_and_double&, const int_and_double&);

main( )
{
   vector<int_and_double>::iterator beginning, ending;
   vector<int_and_double> v;

   int new_integer;
   double new_double;
   int_and_double local_structure;

   fill_vector(v);

   cout << "UNSORTED" << endl;
   print_vector(v);

   beginning = v.begin( );
   ending = v.end( );

   sort(beginning, ending, cmp_ints);

   cout << "\nOutput 1)\nVector v sort ascending by integers:\n";
   print_vector(v);

   sort(beginning, ending, cmp_doubles);

   cout << "\nOutput 2)\nVector v sort descending by doubles:\n";
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

void fill_vector(vector<int_and_double>&v)
{
   int_and_double local_structure;
   //minimum size big enough to demonstrate sorting
   int vector_size = int(3 + 7 * random(seed));

   for (int i = 0; i < vector_size; i++)
   {
      local_structure.m = int(10 * random(seed));
      local_structure.x = double(10 * random(seed));
      v.push_back(local_structure);
   }
}

void print_vector(vector<int_and_double> v)
{
   int_and_double local_structure;

   for (int i = 0; i < v.size( ); i++)
      cout << left << setw(6) << v[i].m;
   cout << endl;
   for (int j= 0; j < v.size( ); j++)
      cout << left << setprecision(3) << setw(6) << v[j].x;
   cout << endl;
}

bool cmp_ints(const int_and_double&m, const int_and_double&n)
{
   return m.m < n.m;
}

bool cmp_doubles(const int_and_double&m, const int_and_double&n)
{
   return m.x > n.x;
}
