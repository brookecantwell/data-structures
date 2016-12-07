/*
 * Brooke Cantwell
 *
 * Data Structures
 *
 * 21 November 2016
 *
 */

#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <string.h>
#include "stack-4.h"

using namespace std;

const char* get_c_string( );

main( )
{
   Stack stack_1;
   const char *traverse;
   const char *user_string;
   
   cout << setw(13) << "Enter a string: ";
   user_string = get_c_string( );

   cout << "User String: " << *user_string << endl;

   initialize_stack(&stack_1, strlen(user_string));
  
   for (traverse = user_string; *traverse != '\0'; traverse++)
      push(&stack_1, *traverse);

   cout << "Popped characters are: ";
   while (!is_Empty(&stack_1));
      cout << setw(2) << pop(&stack_1);
 
   destroy_stack(&stack_1);
}

const char *get_c_string( )
{
   string str;
   getline(cin, str);
   const char *s = str.c_str( );
   return s;
}
