#include <iostream>
#include <vector>
#include <iomanip>
#define HEIGHT 7

using namespace std;

class Game {

	vector<vector<char>> field;

	/*
	*	CONSTRUCTOR
	*/
	public : Game() {
		int count = 0;
		for (int i = 0; i < HEIGHT; i++) {
			field.push_back(vector<char>());
			for (int j = 0; j < HEIGHT; j++) {
				field[i].push_back('_');
				count++;
			}
		}
	}

	void showField() {
		for (int y = HEIGHT; y > 0; y--) {
			for (int x = 0; x < HEIGHT; x++) {
				cout << setw(3) << field[x][y-1];
			}
			cout << endl;
		}
	}

	void playPiece(int colInd) {
		int rowInd = getNextRow(colInd);
		field[colInd][rowInd] = 'X';
	}

	int getNextRow(int colInd) {
		int placeRow = 0;
		while(field[colInd][placeRow] != '_') {
			placeRow++;
		}
		return placeRow;
	}

	public : void run() {
		showField();
		playPiece(3);
		showField();
		playPiece(3);
		showField();
	}

};

/*

|0,6|1,6|
|0,5|1,5|
|0,4|1,4|
|0,3|1,3|
|0,2|1,2|
|0,1|1,1|
|0,0|1,0|

*/

int main(void) {
	Game trame;
	trame.run();

	return 0;
}