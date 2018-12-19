#include <iostream>
#include <vector>
#include <iomanip>
#define HEIGHT 7

using namespace std;

class Player {
	public : char symbol;

	public : Player(char s) {
		symbol = s;
	}

	public : int getPlayColumn() {
		int s;
		cout << "Enter column number (1-7)" << endl;
		cin >> s;
		//ADD CHECK HERE
		return s-1;
	}
};

class Game {

	vector<vector<char>> field;
	Player* p1;
	Player* p2;
	bool end;

	/*
	*	CONSTRUCTOR
	*/
	public : Game() {

		//INITIALISE PLAYERS
		p1 = new Player('X');
		p2 = new Player('O');

		end = false;

		int count = 0;
		for (int i = 0; i < HEIGHT; i++) {
			field.push_back(vector<char>());
			for (int j = 0; j < HEIGHT; j++) {
				field[i].push_back('_');
				count++;
			}
		}
	}

	public : ~Game() {
		delete p1;
		delete p2;
	}

	void showField() {
		for (int y = HEIGHT; y > 0; y--) {
			for (int x = 0; x < HEIGHT; x++) {
				cout << setw(3) << field[x][y-1];
			}
			cout << endl;
		}
	}

	void playPiece(Player* p) {
		int colInd = p->getPlayColumn();
		int rowInd = getNextRow(colInd);
		field[colInd][rowInd] = p->symbol;
		checkWin(colInd,rowInd,p);
	}

	void checkWin(int colInd, int rowInd, Player* p) {
		
		char piece = p->symbol;

		//VERTICALS
		int count = 0;
		for (int i = 0; i<HEIGHT; i++) {
			if(field[colInd][i] == piece) {
				count++;
			} else {
				count = 0;
			}

			if (count >= 4) {
				//Player wins
				end = true;
			}
		}

		//HORIZONTALS
		count = 0;
		for (int i = 0; i<HEIGHT; i++) {
			if (field[i][rowInd] == piece) {
				count++;
			} else {
				count = 0;
			}

			if(count >= 4) {
				//Player wins
				end = true;
			}

		}

		//DIAGONALS
		count = 0;
	}

	int getNextRow(int colInd) {
		int placeRow = 0;
		while(field[colInd][placeRow] != '_') {
			placeRow++;
		}
		return placeRow;
	}

	public : void run() {
		bool p1Turn = true;
		while (end == false) {
			showField();
			if (p1Turn) {
				playPiece(p1);
				p1Turn = false;
			} else {
				playPiece(p2);
				p1Turn = true;
			}
		}
	}

};



/*

|0,6|1,6|
|0,5|1,5|
|0,4|1,4|
|0,3|1,3|
|0,2|1,2|
|0,1|1,1|
|0,0|1,0|2,0|3,0|4,0|

*/

int main(void) {
	Game trame;
	trame.run();

	return 0;
}