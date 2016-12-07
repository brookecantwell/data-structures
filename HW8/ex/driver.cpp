#include <iostream>
#include <algorithm>
#include <vector>
#include "stack.h"


using namespace std;

//ASCENDING ORDER IS THE DEFAULT BUT THIS FUNCTION
//SHOWS HOW IT WORKS
bool cmp_ascending(const example_structure&, const example_structure&);
bool cmp_descending(const example_structure&, const example_structure&);
void print_vector(vector<example_structure>);

main( )
{ 
   //CREATE STRUCTURES TO PUSH TO STACK
   example_structure e1;
   e1.i = 10;
   e1.c = 'a';

   example_structure e2;
   e2.i = 11;
   e2.c = 'b';

   //DECLARE STACK OBJECT
   Stack stack_1;

   //PUSH STRUCTURES TO STACK
   stack_1.push(e1);
   stack_1.push(e2);

   //PRINT STACK
   for (int i = 0; i < 2; i++)
   {
      example_structure element = stack_1.pop( );
      cout << "int: " << element.i << " char: " << element.c;
      cout << endl;
   }
   cout << endl;

   //SORTING STRUCTURES
   example_structure e3, e4, e5;
   e3.i = 7;
   e3.c = 'a';
   e4.i = 4;
   e4.c = 'b';
   e5.i = 13;
   e5.c = 'c';

   //VECTOR OF STRUCTURES TO SORT
   vector<example_structure> v;
   v.push_back(e1);
   v.push_back(e2);
   v.push_back(e3);
   v.push_back(e4);
   v.push_back(e5);

   vector<example_structure>::iterator beginning, ending;
   beginning = v.begin( );
   ending = v.end( );

   sort(beginning, ending, cmp_ascending);

   cout << "VECTOR SORTED IN ASCENDING ORDER" << endl;
   print_vector(v);

   sort(beginning, ending, cmp_descending);

   cout << "VECTOR SORTED IN DESCENDING ORDER" << endl;
   print_vector(v); 
}

bool cmp_ascending(const example_structure&m, const example_structure&n)
{
  return m.i < n.i;
}

bool cmp_descending(const example_structure&m, const example_structure&n)
{
   return m.i > n.i;
}

void print_vector(vector<example_structure> v)
{
   for (int i = 0; i < v.size( ); i++)
      cout << "int: " << v[i].i << " char: " << v[i].c << endl;
   cout << endl;
}
