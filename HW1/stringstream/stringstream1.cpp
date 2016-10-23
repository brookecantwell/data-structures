#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

main( ) {

	string line;
	stringstream ss;
	ifstream inFile("file.txt");
	int n = 0;

	if (!inFile.is_open( ))
		cout << "Failed to open file." << endl;
	
	else {
		while (getline(inFile, line))
			ss << line;
			cout << line << endl;
			cout << "n = " << n << endl;
			ss.clear( );
	}
}
