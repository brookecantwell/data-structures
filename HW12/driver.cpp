/*
 * Brooke Cantwell
 *
 * Data Structures
 *
 * Homework #12
 *
 * 1 December 2016
 *
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "stack-5.h"

using namespace std;

main( )
{
   Stack s_1;
   const char *traverse;
   const char *user_string;
   string original_string;

   cout << "Enter string: ";
   getline(cin, original_string);

   user_string = original_string.c_str( );

   s_1.initialize_stack(strlen(user_string));

   for (traverse = user_string; *traverse != '\0'; traverse++)
      s_1.push(*traverse);

   cout << "Top element of the stack: " << s_1.top_stack( ) << endl; 

   cout << "Characters printed using pop function: ";
   while (!s_1.is_empty( ))
      cout << setw(3) << s_1.pop( );
   cout << endl;

   s_1.destroy_stack( );
}
