/* Brooke Cantwell
 *
 * CISC2200 Data Structures
 *
 * Cell Class Header File
 *
 * 8 September 2016
 *
 */

#ifndef ROW_H
#define ROW_H

#include <iostream>
#include "cell.h"

using namespace std;

class Row {
	//global functions
	//output operator overload function
	
	public:
	//constructors
		Row( );
		Row(int);
		void setRowNum(int);
		void print( );
	private:
		static const int DEFAULT_STARTING_SIZE = 100;
		static int numRows;
		int rowNum;
		Cell *row[DEFAULT_STARTING_SIZE];	
};

#endif
