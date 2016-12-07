#include <iostream>
#include <iomanip>
//#include <stdio.h>

using namespace std;

unsigned int seed = (unsigned)7;

struct structure_1
{
   int x;
   char y;
};

struct structure_2
{
   char x;
   int y;
};

template <typename T>
void test(T s)
{
   cout << s.x;
   cout << s.y;
}

template <typename T>
void print_info(T arr[ ], int s)
{
   for (int i = 0; i < s; i++)
      cout << arr[i] << ' ';
   cout << endl;
}

/*
template <typename T>
void fill_info(T arr[ ], int s)
{
   T new_data;
   for (int i = 0; i < s; i++)
   {
      new_data = (1 + 10 * random(seed));
      arr[i] = new_data;
   }
}
*/

double random(unsigned int&seed)
{
   const int MODULUS = 15748;
   const int MULTIPLIER = 69069;
   const int INCREMENT = 1;

   seed = ((MULTIPLIER * seed) + INCREMENT) % MODULUS;
   return double(seed) / double(MODULUS);
}

main( )
{
   int size = 3;
   int int_array[size];
   char char_array[size];

   int_array[0] = 10;
   int_array[1] = 11;
   int_array[2] = 12;

   print_info(int_array, size);

   structure_1.x = 3;
   structure_1.y = 'a';

   structure_2.x = 'b';
   structure_2.y = 10;

   test(structure_1);
   cout << endl;
   test(structure_2);

}
