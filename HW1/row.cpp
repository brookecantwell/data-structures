/*
 * Brooke Cantwell
 *
 * CISC2200 Data Structures
 *
 * Row Class Implementation File
 *
 * 8 September 2016
 *
 */

#include <iostream>
#include "row.h"

using namespace std;

//STATIC VARIABLES
int Row::numRows = 0;

//GLOBAL FUNCTIONS

//CONSTRUCTORS

Row::Row( ) {
	rowNum = 0;
	numRows++;
}

//constructor instantiating an object with a row number
Row::Row(int r) {
	rowNum = r;
	numRows++;
}

//MUTATOR METHODS
void Row::setRowNum(int r) {
	rowNum = r;
}

//display method
void Row::print( ) {
	for (int i = 0; i < numRows; i++) {
		cout << row[i] << "  ";
	}
}
