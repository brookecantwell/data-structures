/*
 * Brooke Cantwell
 *
 * Data Structures
 *
 */

#include <iostream>
#include <iomanip>
#include "list-char.h"

using namespace std;

unsigned int seed = 7;

void print(list_char&);
double random(unsigned int&);
bool search_list(list_char&, char);

main( )
{
   list_char list;
   char item;
   int size;
   bool success;
   char search_char;
   
   cout << "Test list insertions:" << endl;

   do
   {
      cout << "Enter number of characters to insert: ";
      cin >> size;
   } while (size < 2);

   for (int i = 0; i < size; ++i)
      list.insert(char('b' + ('k' - 'b' + 1) * random(seed)));

   print(list);

   cout << "Enter character to search for in list: ";
   cin >> search_char;

   success = list.search_list(search_char);
 
   cout << "Test get_last( )" << endl;

   int index = list.get_last(search_char);

   if (index == -1)
      cout << "Element not found in list (main)." << endl;
   else
      cout << "Search character " << search_char << " was found in the list at index " << index << '.' << endl;
}

void print(list_char&list)
{
   char item;
   bool success;
   cout << "Contents of list: ";
   if (!list.empty( ))
   {
      list.first( );
      while (!list.at_end( ))
      {
         success = list.retrieve(item);
         cout << item << ' ';
         list.next( );
      }
      success = list.retrieve(item);
      cout << item << endl;
   }
   list.first( );
}

double random(unsigned int&seed)
{
   const int MODULUS = 15749;
   const int MULTIPLIER = 69069;
   const int INCREMENT = 1;
   seed = ((MULTIPLIER * seed) + INCREMENT) % MODULUS;
   return (double) seed / (double) MODULUS;
}

/*
bool search_list(list_char&list, char search)
{
   bool in_list = false;  
   char element;
   bool success;

   while (!list.at_end( ))
   {
      success = list.retrieve(element);
      if (element == search)
      {
         in_list = true;
         break;
      }
      else
//         cout << "Character not found in list." << endl;
         list.next( );
   }
   if (in_list == true)
      cout << search << " was found in the list." << endl;
   else
      cout << search << " was not found in the list." << endl;
 
   return(in_list);
}
*/

void get_last(list_char&list)
{
      

}
