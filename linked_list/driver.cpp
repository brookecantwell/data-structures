#include <iostream>
#include <iomanip>
#include <assert.h>

using namespace std;

struct structure;
typedef structure *structure_pointer;

struct structure 
{
   int data;
   structure_pointer next;
};

void display_list(structure_pointer);
structure_pointer create_structure(int);
void insert_beginning(structure_pointer&, structure_pointer);
void insert_at(structure_pointer&, structure_pointer, int);
void append(structure_pointer&, structure_pointer);

main( )
{
   structure_pointer head, s2, s3, s4;
   head = create_structure(1);
   s2 = create_structure(2);
   s3 = create_structure(3);
   s4 = create_structure(4);

   //link structures
   head -> next = s2;
   s2 -> next = s3;
   s3 -> next = s4;

   display_list(head);

   //create structure to add to beginning
   structure_pointer begin = create_structure(10);

   insert_beginning(head, begin);

   cout << "List with new element inserted at beginning:" << endl;
   display_list(head);

   structure_pointer insert = create_structure(20);
   cout << "List with new element inserted at position 2:" << endl;
   insert_at(head, insert, 2);
   display_list(head);

   structure_pointer app = create_structure(30);
   cout << "List with new element appended:" << endl;
   append(head, app);
   display_list(head);
}


void display_list(structure_pointer head)
{
   structure_pointer p = head;
   int count = 0;
   while (p != NULL)
   {
      count++;
      cout << "Node #" << count << " Data: " << p -> data << endl;
      p = p -> next;
   }
}

//insert structure p at the beginning of the list
void insert_beginning(structure_pointer&head, structure_pointer p)
{
   p -> next = head;
   head = p;
}

void insert_at(structure_pointer&head, structure_pointer p, int index)
{
   structure_pointer left, right;
   right = head;

   for (int i = 1; i < index; i++)
   {
      left = right;
      right = right -> next;
   }
   
   left-> next = p;
   left = p;
   left -> next = right;   
}

void append(structure_pointer&head, structure_pointer p)
{
   structure_pointer curr;
   curr = head;
   if (curr == NULL)
      head = p;
   else
   {
      while (curr -> next != NULL)
         curr = curr -> next;
      curr -> next = p;
   }
}
structure_pointer create_structure(int n)
{
   structure_pointer p = new structure;
   assert (p != NULL);
   p -> data = n;
   p -> next = NULL;
}
