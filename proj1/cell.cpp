/*
 * Brooke Cantwell
 *
 * CISC2200 Data Structures
 *
 * HW #1
 *
 * Cell Class Implementation
 *
 * 6 September 2016
 *
 */

#include <iostream>
#include "cell.h"

using namespace std;


//GLOLBAL FUNCTIONS

//OPERATOR OVERLOAD FUNCTIONS

//output operator overload function
ostream& operator<< (ostream&out, Cell cell) {

	cell.displayCell( );
}

/*
istream& operator>> (istream&in, Cell&cell) {
	cout << "Cell Type: ";
	in >> cell.cellType;
}
*/

//CONSTRUCTORS

Cell::Cell( ) {
	cellType = 0;
	displayString = " ";
}

//constructor uses the setType mutator method
//to assign cellType and displayString
Cell::Cell(int type) {
	setType(type);
}

//MUTATOR METHODS

//mutator method setType uses the cellType to set the
//displayString (which unicode character the cell is
//supposed to display)
//CELLTYPE
//0 = NUll
//1 = Black Square
//2 = Small Square
//3 = Triangle
void Cell::setType(int type) {
	switch(type) {
		case 0:
			cellType = 0;
			displayString = " ";
			break;
		case 1:
			cellType = 1;
			displayString = "\u25A0";
			break;
		case 2:
			cellType = 2;
			displayString = "\u25AB";
			break;
		case 3:
			cellType = 3;
			displayString = "\u25B2";
	}
}

//set the row number for any given row
void Cell::setRowNum(int r) {
	rowNum = r;
}

//Set the position in the row (array) for a given cell
void Cell::setColPosition(int c) {
	colPosition = c;
} 

//ACCESSOR METHODS
int Cell::getCellType( ) {
	return(cellType);
}

/*
//OTHER CLASS METHODS
bool Cell:checkPath( ) {
	

}
*/

//display method - displays an individual cell
void Cell::displayCell( ) {
	cout << displayString << " ";
}
