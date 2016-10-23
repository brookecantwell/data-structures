/*
 * Brooke Cantwell
 *
 * Data Structures
 *
 * Homework #1
 *
 * 6 September 2016
 *
 */

#include <iostream>
#include "header.h"
#include "cell.h"

using namespace std;

main( ) {
	
	//local variables
	int counter = 1;

	//function prototypes
	void print(Cell*[ ], int&);

	//pointers to cell types
	Cell square(1);
	Cell smallSquare(2);
	Cell triangle(3);

	Cell *row1[COL] = {&square, &square, &square, &triangle, &square, &square, &square, &square};
	Cell *row2[COL] = {&square, &square, &square, &smallSquare, &square, &square, &square, &square};
	Cell *row3[COL] = {&square, &square, &square, &smallSquare, &smallSquare, &square, &square, &square};
	Cell *row4[COL] = {&square, &square, &smallSquare, &smallSquare, &smallSquare, &smallSquare, &square, &square};
	Cell *row5[COL] = {&square, &square, &smallSquare, &square, &square, &smallSquare, &square, &square};
	Cell *row6[COL] = {&square, &square, &square, &square, &square, &smallSquare, &square, &square};
	Cell *row7[COL] = {&square, &square, &square, &square, &square, &smallSquare, &square, &square};
	Cell *row8[COL] = {&square, &square, &square, &square, &square, &triangle, &square, &square};	



	//display column numbers
	cout << " ";
	for (int i = 1; i <= COL; i++) {
		cout << ' ' << i << ' ';	
	}
	cout << endl;

	print(row1, counter);
	print(row2, counter);
	print(row3, counter);
	print(row4, counter);
	print(row5, counter);
	print(row6, counter);
	print(row7, counter);
	print(row8, counter);

}


void print(Cell *rowNum[ ],int&counter) {
	cout << counter << ' ';
	
	for (int c = 0; c < COL; c++) {
		cout << *rowNum[c] << ' ';
	}
	cout << endl;

	counter++;
}
