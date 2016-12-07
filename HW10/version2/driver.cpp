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
   structure_pointer left, right;
};

unsigned int seed = (unsigned) time(0);

double random(unsigned int&);
structure_pointer create_structure(int);
void traverse_tree(structure_pointer&, int);
void print_tree(structure_pointer);

main( )
{
   int random_integer;

   structure_pointer head, q, p;

   head = create_structure(3);

   for (int i = 0; i < 10; i++)
   {
      p = head;
      random_integer = (1 + 10 * random(seed));
      traverse_tree(p, random_integer);
   }

   if (p -> right != NULL)
      cout << "p -> right -> data: " << p -> right -> data << endl;
   if (p -> left != NULL)
      cout << "p -> left -> data: " << p -> left -> data << endl;
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

structure_pointer create_structure(int n)
{
   structure_pointer p;
   p = new structure;
   assert (p != NULL);
   p -> data = n;
   p -> right = NULL;
   p -> left = NULL;
}

void traverse_tree(structure_pointer&p, int n)
{
   if (p == NULL)
      p = create_structure(n);

   else
   {
      if (n < p -> data)
      {
         cout << "n < p -> data --- left tree" << endl;
         traverse_tree(p -> left, n);
      }
      else
      {
         cout << "n >= p -> data --- right tree" << endl;
         traverse_tree(p -> right, n);
      }
   }
}

void print_tree(structure_pointer p)
{
   if (p == NULL)
      cout << "Empty tree." << endl;
   print_tree(p -> right);
   for (int i = 0; i < 10; i++)
      cout << '\t';
   cout << p -> data << endl;
   print_tree(p -> right);
}
