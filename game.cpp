//SDEV 240 Final Project "Conway's Game of Life" Douglass A. Belley

#include <iostream>
#include <cstdlib>
#include "PlaySpace.h"
#include "InitialShape.h"

using namespace std;

void displayMenu();
int getChoice(int, int);

int main() {
	//initialize variables that will be needed
	int generationCounter = 1;
	int choice;
	//create two playspace classes
	PlaySpace world1;
	PlaySpace world2;
	//each world gets an initialized play area
	world1.playArea;
	world2.playArea;
	world1.initGrid();
	world1.displayGrid();
	//create a shape from the Initial shape class, set it, and display it
	InitialShape shape;
	shape.setShape();
	shape.displayShape();
	//this logic is writing the shape to the play area
	for (int i = 0;i < 4;i++) {
		for (int j = 0; j < 4;j++) {
			world1.playArea[i + 3][j + 3] = shape.newShape[i][j];
		}
	};
	//displays your starting first generation layout
	world1.displayGrid();
	//menu option advances the game by one generation as well as iterating the generation count to track how long it has been going
	do {
		displayMenu();
		choice = getChoice(1, 2);
		if (choice == 1)
		{
			for (int i = 0;i < 25;i++) {
				for (int j = 0;j < 25;j++) {
					int neighbors = 0;
					if (world1.playArea[i - 1][j - 1] + world1.playArea[i][j - 1] + world1.playArea[i + 1][j - 1] +
						world1.playArea[i - 1][j] + world1.playArea[i + 1][j] +
						world1.playArea[i - 1][j + 1] + world1.playArea[i][j + 1] + world1.playArea[i + 1][j + 1] == 3) {
						world2.playArea[i][j] = 1;
					}
					else if ((world1.playArea[i - 1][j - 1] + world1.playArea[i][j - 1] + world1.playArea[i + 1][j - 1] +
						world1.playArea[i - 1][j] + world1.playArea[i + 1][j] +
						world1.playArea[i - 1][j + 1] + world1.playArea[i][j + 1] + world1.playArea[i + 1][j + 1] == 2 &&
						world1.playArea[i][j] == 1))
					{
						world2.playArea[i][j] = 1;
					}
					else {
						world2.playArea[i][j] = 0;
					}
				}
			}
			world1 = world2;
			world1.displayGrid();
			cout << "Generation " << generationCounter;
			generationCounter++;
		}
		else if (choice == 2)
		{
			cout << "Goodbye";
		}
		else
		{
			cout << "Unrecognized command.\n"
				<< "please exit and try again with an appropriate choice selection.";
		}
	} while (choice != 2);
};

void displayMenu() {
	int choice;
	cout << "\nEnter Option.\n"
		<< "Please choose an option:\n"
		<< "1 -- advance life by one generation\n"
		<< "2 -- quit\n";
};

int getChoice(int min, int max)
{
	int input;
	// Get and validate the input
	cin >> input;
	while (input < min || input > max)
	{
		cout << "Invalid input. Enter an integer between " << min << " and " << max << ":";
		cin >> input;
	}
	return input;
};
