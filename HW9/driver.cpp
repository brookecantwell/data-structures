/*
 * Brooke Cantwell
 *
 * Data Structures
 *
 * 14 November 2016
 *
 * Design a function get_structure( ) that
 * will create a structure and assign values 
 * to fields f1 and f2 of the structure 
 * presented in class.
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <assert.h>

using namespace std;

struct structure;
typedef structure *structure_pointer;

struct structure
{
   int f1;
   char f2;
   structure_pointer f3, f4;
};

structure_pointer get_structure(int, char);
void print_structure(structure_pointer);

main( )
{
   structure_pointer s1, s2;
 
   s1 = get_structure(1, 'a');
   assert(s1 != NULL);
   cout << "Structure #1" << endl;
   print_structure(s1);


   s2 = get_structure(2, 'b');
   assert(s2 != NULL);
   cout << endl << "Structure #2" << endl;
   print_structure(s2);
}

structure_pointer get_structure(int m, char c)
{
   structure_pointer p = new structure;
   
   if (p != NULL) {
      p -> f1 = m;
      p -> f2 = c;
      p -> f3 = NULL;
      p -> f4 = NULL;
      return(p);
   }
   else
      cout << "Error: No dynamic memory available." << endl;
}

void print_structure(structure_pointer p)
{
   assert(p != NULL);
   cout << "structure -> f1: " << p -> f1 << endl;
   cout << "structure -> f2: " << p -> f2 << endl;
}
