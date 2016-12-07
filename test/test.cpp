#include <iostream>

using namespace std;

main( )
{
   int integer_1;
   int *pointer_1;

   cout << pointer_1 << endl;

//   pointer_1 = new int;
   cout << pointer_1 << endl;

   pointer_1 = new int;
   *pointer_1 = 5;
   cout << pointer_1 << endl;

   cout << &integer_1 << endl;
}
