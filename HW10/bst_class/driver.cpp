#include <iostream>
#include "TreeType.h"


using namespace std;

main( )
{
   TreeNode *tree;
   tree = new TreeNode([1,3,2,6,4,7], 6);

   tree.PrettyPrint( );
}
