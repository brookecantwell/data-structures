/* Brooke Cantwell
 *
 * CISC2200 Data Structures
 *
 * Homework #1
 *
 * Maze Class Header File
 *
 * 6 September 2016
 *
 */

#ifndef MAZE_H
#define CELL_H

#include <iostream>

using namespace std;

class Maze{
	//global functions
	//output operator overload function
	friend ostream& operator<< (ostream&, Maze);
	//input operator overload function
//	friend istream& operator<< (istream&, Cell&);
	
	public:
		void input(istream&);
		void output(ostream&);
	private:
		static const SIZE = 10;
		char Cells[SIZE][SIZE];
};

istream& operator>> (istream&, Maze&);
ostream& operator<< (ostream&, Maze);

#endif
