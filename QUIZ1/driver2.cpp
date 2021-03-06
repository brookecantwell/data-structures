#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void print_row(vector<int>);
int get_minimum(vector<vector<int>>);
int get_sum(vector<int>);

main( ) 
{

   int n;
   string line;
   stringstream ss;
   vector<vector<int>> v;
   vector<int> row;
   int min = 0;
   int temp = 0;
   int sum = 0;
   bool first = true;
   string fileName;

   cout << "Input file name: ";
   cin >> fileName;

   ifstream input_file(fileName);

   if (!input_file.is_open( ))
      cout << "Error opening file." << endl;
   else
   {
      while(getline(input_file, line))
      {
         ss.clear( );
         ss.str(" ");
         ss << line;
         while (ss >> n) 
            row.push_back(n);
         v.push_back(row);
         row.clear( );
      }
      input_file.close( );

      min = get_minimum(v);
   }

   for (int i = 0; i < v.size( ); i++)
   {      
      if (get_sum(v[i]) > min)
      {
         v.erase(v.begin( ) + i);
         i -= 1;
      }   
   }

   for (int i = 0; i < v.size( ); i++)
      print_row(v[i]);
}

int get_sum(vector<int> row)
{
   int sum = 0;

   for (int i = 0; i < row.size( ); i++)
   {
      sum += row[i];
   }

   return(sum);
}

void print_row(vector<int> row)
{
   for (int i = 0; i < row.size( ); i++)
      cout << row[i] << ' ';
   cout << endl;

}

int get_minimum(vector<vector<int>> v)
{
   int min;
   int temp = 0;
   static bool first = true;  

   if (first == true)
   {
      first = false;
      min = get_sum(v[0]);
   }
   

   for (int i = 0; i < v.size( ); i++)
   {
      temp = get_sum(v[i]);
      if (temp < min)
         min = temp;
      temp = 0;
   }
    
   return(min);
}
   
