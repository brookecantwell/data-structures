/*
 * Brooke Cantwell
 *
 * Data Structures
 *
 */

#include <iostream>
#include <assert.h>
#include <stdio.h>
#include "list-char.h"

using namespace std;

list_char::list_char( )
{
   head = NULL;
   current = NULL;
   previous = NULL;
   list_length = 0;
}

list_char::list_char(const list_char&list)
{
   node_ptr probe = list.head;
   while (probe != NULL)
   {
      insert(probe -> data);
      next( );
      probe = probe -> next;
   }
}

list_char::~list_char( )
{
   node_ptr garbage;
   node_ptr probe = head;
   while (probe != NULL)
   {
      garbage = probe;
      probe = probe -> next;
      delete garbage;
   }
   list_length = 0;
   head = NULL;
   current = NULL;
   previous = NULL;
}

list_char& list_char::operator= (const list_char&list)
{
   node_ptr probe = list.head;
   while (probe != NULL)
   {
      insert(probe -> data);
      next( );
      probe = probe -> next;
   }
   return *this;
}

bool list_char::empty( )
{
   return (list_length == 0);
}

int list_char::length( )
{
   return (list_length);
}

bool list_char::at_end( )
{
   if (current == NULL)
      return (true);
   else
   {
      if (current != NULL && (current -> next) == NULL)
         return (true);
      else
         return (false);
   }
}

void list_char::next()
{
   if (current != NULL)
   {
      previous = current;
      current = current -> next;
   }
}

void list_char::first( )
{
   current = head;
   previous = NULL;
}

void list_char::insert(const char&item)
{
   node_ptr new_node = get_node(item);
   new_node -> next = current;
   if (current == head)
      head = new_node;
   else
      previous -> next = new_node;
   current = new_node;
   ++list_length;
}

bool list_char::remove(char&item)
{
   node_ptr old_node = current;
   bool success = true;
   if (current == NULL)
      success = false;
   else
   {
      item = current -> data;
      if (current == head)
         head = current -> next;
      else
         previous -> next = current -> next;
      current = current -> next;
      delete old_node;
      --list_length;
   }
   return (success);
}

bool list_char::retrieve(char&item)
{
   bool success = true;
   if (current == NULL)
      success = false;
   else
      item = current -> data;
   return (success);
}

bool list_char::search_list(char search)
{
   bool in_list = false;
   char element;
   bool success;

   while (!at_end( ))
   {
      success = retrieve(element);
      if (element == search)
      {
         in_list = true;
         break;
      }
      else
         next( );
   }
   if (in_list == true)
      cout << search << " was found in the list." << endl;
   else
      cout << search << " was not found in the list." << endl;
   
   return(in_list);
}

/*
char list_char::get_index(int index)
{
   char element;
   first( );
   for (int i = 0; i < index; i++)
   {
      if (!at_end( ))
         next( );
      else
      {
         cout << "Cannot retrieve item. Index unavailable." << endl;
         exit(1);
      }
   }
   retrieve(element);
   return (element);
}
*/

int list_char::get_last(char search)
{
   int index = 0;
   int current_last_index;
   bool in_list = false;
   char element;
   bool success;

   while (!at_end( ))
   {
      success = retrieve(element);
      if (element == search)
      {
         in_list = true;
         current_last_index = index;
      }
      next( );
      index++;
   }

   if (in_list == false)
   {
      cout << "Element was not found in list. Cannot retrieve index." << endl;
      current_last_index = -1;
   }
   else
      cout << "Element was found at index " << index << endl;

   return(current_last_index);
}

list_char::node_ptr list_char::get_node(const char&item)
{
   node_ptr temp = new node;
   assert (temp != NULL);
   temp -> data = item;
   temp -> next = NULL;
   return (temp);
}
