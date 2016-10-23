/*
 * Brooke Cantwell
 *
 * CISC2200 Data Structures
 *
 * Driver 
 *
 * 8 September 2016
 *
 */

#include <iostream>
#include <fstream>
#include "cell.h"

using namespace std;

main( ) {
	int testArray[8] = {1, 1, 2, 3, 2, 1, 3, 1};
//	Cell row[8] =  
	Cell resultsArray[8];
//	for (int i = 0; i < 8; i++) {
		
	
	for (int i = 0; i < 8; i++) {
		int localType;
		localType = testArray[i];
		resultsArray[i].setType(localType);
	}

	for (int i = 0; i < 8; i++) {
		cout << resultsArray[i];
	}

}
