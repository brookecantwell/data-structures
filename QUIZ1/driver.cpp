/* Brooke Cantwell
 *
 * Data Structures
 *
 * Quiz 1
 *
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int is_minimum(vector<int>);
//void print_line(vector<int>);

main( )
{
   stringstream ss;
   int n;
   string line;
   ifstream input_file("file1.dat");
   vector<vector<int>> v;
   vector<int> row;
   int min = 0;
   int sum = 0;
   bool minimum;
//   int y = 0;

   if (!input_file.is_open( ))
      cout << "Unable to open file." << endl;
   else 
   {
      while (getline(input_file, line)) 
      {
         ss.clear( );
         ss.str(" ");
         ss << line;
         while (ss >> n)

            row.push_back(n);
           
        
         
           v.push_back(row);

           min = is_minimum(row); 
	   row.clear( );
//           min = is_minimum(row, min);

//           row.clear( );
           input_file.close( );
       }

   

//        min = is_minimum(row, min);


//         for (int i = 0; i < v.size( ); i++) 
//         {
//            for (int x = 0; x < v[i].size( ); x++) 
//            {
//            if (sum += v[i][x] > min)
//            v.push_back(row);
//            print_line(row);
//            for (int i = 0; i < row.size( ); i++)
//              cout << v[i][x] << ' ';
//              min = is_minimum(v[i], min);
//            cout << endl;
//            }
//         row.clear( );
//         }
//      }


      for (int i = 0; i < v.size( ); i++) 
      {
         for (int x = 0; x < v[i].size( ); x++)
         {
//            if (arr_min[i] == true)

            if (v[i][x] <= min)
            cout << v[i][x] << ' ';
  
         }
         cout << endl;
      }
      

   }

   cout << "test" << endl;
   
}


int is_minimum(vector<int> v) 
{
   int min;
   bool minimum = false;
   static bool first = true;
   int temp = 0;

   if (first == true)
   {
      for (int i = 0; i < v.size( ); i++) 
      {
//      for (int x = 0; x < v[i].size( ); x++)
//      {
         temp = 0;
         temp += v[i];
         first = false;
         if (min >= temp)
            min = temp;
//      }
        else
            return temp;
      }
   }

   for (int x = 0; x < v.size( ); x++) {
//   for (int i = 0; i < v[x].size( ); i++) {
//      temp = 0;

      temp = 0;
      temp += v[x];

      cout << "temp: " << temp << "   min: " << min << endl;
//   }
      if (min >= temp)
         min = temp;
     else
         return temp;
   }

//   if (temp <= min)
//      min = temp;  


//      if (temp <= min)
//      {
//         v.push_back(v[x]);
//         min = temp;
//         minimum = is_minimum(v, min);
//        temp = 0;
//         cout << "\nboolean minimum: " << minimum << endl;
//      }
//      else
//         minimum = false;
//   }
   cout << "min: " << min << endl; 
  
   return(min);
}

/*
void print_line(vector<int> row)
{
   for (int i = 0; i < row.size( ); i++)
      cout << row[i];
} 
*/ 
