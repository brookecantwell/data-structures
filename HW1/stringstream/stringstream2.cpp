#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

main( ) {

	stringstream ss;
	int n;
	string line;
	ifstream myFile("file.txt");
//	vector <vector <int>> num(30, vector<int>( ));
//	vector <int> row;
	vector<vector<int>> num;
//	int indexX, indexY = 0;
	int rows = 0;

	if (!myFile.is_open( ))
		cout << "Unable to open file." << endl;

	else {

		while (getline(myFile, line)) {
			vector <int> row;
			ss.clear( );
			ss.str(" ");
			ss << line;
			while (ss >> n) {
				row.push_back(n);		
			}
			num.push_back(row);
			rows++;
		}
	}

//	cout << "n = " << n << endl;
	for (int i = 0; i < num.size( ); i++) {
		for (int x = 0; x < num[i].size( ); x++) {
			cout << num[i][x] << ' ';
		}
//		cout << "row = " << i + 1 << endl;
		cout << endl;
	}
}
