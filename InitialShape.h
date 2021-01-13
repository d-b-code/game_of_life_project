#include <iostream>
#include <cstdlib>

using namespace std;

//class used for setting shapes and displaying the shape as a test tool


class InitialShape
{
private:
	int blinker[4][4] = { 1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0 };
	int glider[4][4] = { 0,0,1,0,1,0,1,0,0,1,1,0,0,0,0,0 };
	int beacon[4][4] = {1,1,0,0,1,1,0,0,0,0,1,1,0,0,1,1};
public:
	int newShape[4][4];
	//improtant piece here, user selects what they want from three predetermined common cell shapes,
	//or they can set a custom shape
	void setShape() {
		int option;
		cout << "Choose a shape to test:\n"
			<< "1 -- blinker\n"
			<< "2 -- glider\n"
			<< "3 -- beacon\n"
			<< "4 -- custom\n";
		cin >> option;
		if (option == 1) {
			for (int i = 0; i < 4;i++) {
				for (int j = 0; j < 4; j++) {
					newShape[i][j] = blinker[i][j];
				}
			}
		}
		else if (option == 2) {
			for (int i = 0; i < 4;i++) {
				for (int j = 0; j < 4; j++) {
					newShape[i][j] = glider[i][j];
				}
			}
		}
		else if (option == 3) {
			for (int i = 0; i < 4;i++) {
				for (int j = 0; j < 4; j++) {
					newShape[i][j] = beacon[i][j];
				}
			}
		}
		else if (option == 4) {
			for (int i = 0; i < 4;i++) {
				for (int j = 0; j < 4; j++) {
					cout << "Enter 1 to populate the cell, or 0 to keep the cell empty\n";
					cout << "cell [" << i << ' ' << j << ']';
					cin >> newShape[i][j];
				}
			}
		};
	};
	void displayShape() {
		//print
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if (newShape[i][j] == 1) {
					cout << 'X';
				}
				else {
					cout << '_';
				}
			}
			cout << '\n';
		}
	}
};
