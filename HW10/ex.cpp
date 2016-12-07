#include <iostream>
#include <iomanip>
#include <assert.h>

using namespace std;

unsigned int seed = (unsigned int)time(0);
struct structure;
typedef structure *structure_pointer;

double random(unsigned int&);
structure_pointer get_structure();
void build_structure(structure_pointer, structure_pointer);

struct structure
{
   structure_pointer left;
   int int_data;
   structure_pointer 
   structure_pointer right;
};

int main()
{
   structure_pointer head, p, q;
   head = get_structure();

   for(int i=0; i<10; i++)
   {
      p = head;
      q = create__structure( );
      build_structure(q ,p);
   }

   p = head;
   cout << "The value of 'head' is: " << endl;
   cout << head->int_data << endl;
//    print_structure(p, width);

}

double random( unsigned int &seed)
{
   const int MODULUS = 15749;
   const int MULTIPLIER = 69069;
   const int INCREMENT = 1;
   seed = ((MULTIPLIER*seed) + INCREMENT) % MODULUS;
   return double(seed)/double(MODULUS);
}


structure_pointer create_structure( )
{
   int random_integer = int(20*random(seed));

   structure_pointer p;
   p = new structure;
   assert (p != NULL);
   p -> data = random_integer;
   p -> left_str_ptr = NULL;
   p -> right_str_ptr = NULL;
   return p;       
}

void build_structure(structure_pointer p1, structure_pointer p2)
{
    if(p1 -> data < p2 -> data)
    {
        if(p2 -> left_str_ptr == NULL)
            p2 -> left= p2;
            else
            {
                p1 =p1 -> left_str_ptr;
                build_structure(p1, p2);
            }
    }
        else
        {
            if(p->right==NULL)
                p->right=new_value;
                else
                {
                    p=p->right;
                    build_structure(new_value,p);
                }

        }   
}
