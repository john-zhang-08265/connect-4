#include <iostream>
#include <vector>
#include <iomanip>
#define HEIGHT 7

using namespace std;

class Game {

	vector<vector<int>> field;

	/*
	*	CONSTRUCTOR
	*/
	public : Game() {
		int count = 0;
		for (int i = 0; i < HEIGHT; i++) {
			field.push_back(vector<int>());
			for (int j = 0; j < HEIGHT; j++) {
				field[i].push_back(count);
				count++;
			}
		}
	}

	void showField() {
		for (int j = 0; j < HEIGHT; j++) {
			for (int i = 0; i < HEIGHT; i++) {
				cout << setw(3) << field[i][j];
			}
			cout << endl;
		}
	}

	public : void run() {
		showField();

	}

};

int main(void) {
	Game trame;
	trame.run();

	return 0;
}