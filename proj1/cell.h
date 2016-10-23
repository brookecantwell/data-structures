/* Brooke Cantwell
 *
 * CISC2200 Data Structures
 *
 * Homework #1
 *
 * Cell Class Header File
 *
 * 6 September 2016
 *
 */

#ifndef CELL_H
#define CELL_H

#include <iostream>

using namespace std;

class Cell{
	//global functions
	//output operator overload function
	friend ostream& operator<< (ostream&, Cell);
	//input operator overload function
//	friend istream& operator<< (istream&, Cell&);
	
	public:
		//constructors
		Cell( );
		Cell(int);
		//mutator methods
		void setType(int);
		void setRowNum(int);
		void setColPosition(int);
		//accessor methods
		int getCellType( );
		//other class methods
		
		//display methods
		void displayCell( );
	private:
		int cellType;
		string displayString;
		int rowNum;
		int colPosition;
};

#endif
