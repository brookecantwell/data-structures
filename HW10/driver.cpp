#include <iostream>
#include <iomanip>
#include <ctime>
#include <assert.h>

using namespace std;

struct structure;
typedef structure *structure_pointer;

struct structure
{
   int data;
   structure_pointer left_str_ptr, right_str_ptr;
};

unsigned int seed = (unsigned) time(0);

double random(unsigned int&);
structure_pointer create_structure(structure_pointer);
void insert_into_tree(structure_pointer, int);
void print_tree(structure_pointer);

main( )
{
   int random_integer;
   structure_pointer head, q, p;

   head = create_structure(head);
   cout << "Head: " << head -> data << endl;


   for (int i = 0; i < 10; i++)
   {
      p = head;
      random_integer = (1 + 10 * random(seed));
      insert_into_tree(p, random_integer);
   }

//   print_tree(p);

}

double random(unsigned int&seed)
{
   const int MODULUS = 15748;
   const int MULTIPLIER = 69069;
   const int INCREMENT = 1;

   seed = ((MULTIPLIER * seed) + INCREMENT) % MODULUS;
   return double(seed) / double(MODULUS);
}

structure_pointer create_structure(structure_pointer p)
{
   p = new structure;
   assert (p != NULL);
   p -> data = (1 + 10 * random(seed));
   p -> left_str_ptr = NULL;
   p -> right_str_ptr = NULL;
   return(p);
}

void insert_into_tree(structure_pointer p, int n)
{

   if (p == NULL)
   {
      p = new structure;
      assert(p != NULL);
      p -> data = n;
      p -> left_str_ptr = NULL;
      p -> right_str_ptr = NULL;
   }

   else
   {
      if (n < p -> data)
      {
         insert_into_tree(p -> left_str_ptr, n);
         cout << n << " inserted into left sub-tree." << endl;
      }
      else
      {
         insert_into_tree(p -> right_str_ptr, n);
         cout << n << " inserted into the right sub-tree." << endl;
      }
   }

}


//recursive print function does not work
void print_tree(structure_pointer p)
{
   if (p == NULL)
      cout << "Empty tree." << endl;
   print_tree(p -> right_str_ptr);
   for (int i = 0; i < 10; i++)
      cout << '\t';
   cout << p -> data << endl;
   print_tree(p -> right_str_ptr);
}
