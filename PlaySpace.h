#include <iostream>
#include <cstdlib>
#include <string> 


using namespace std;

//this class sets up the play space, displays the grid, 
//and has a seperate tool to display grid cooridnates that was used during testing
class PlaySpace
{
public:
	//sets play area as an array and defines the space to be populated by 0s
	bool playArea[25][25];
	int SpaceWidth = 25;
	int SpaceHeight = 25;

	//initalizes the play grid and populates with 0 values
	void initGrid() {
		for (int i = 0; i < SpaceHeight; ++i)
		{
			for (int j = 0; j < SpaceWidth; ++j)
			{
				playArea[i][j] = 0;
			}
		}
	};

	//displays grid coordinates as a simple check during programming
	void displayGridCoordinates() {
		//print
		for (int i = 0; i < SpaceHeight; ++i)
		{
			for (int j = 0; j < SpaceWidth; ++j)
			{
				cout << '[';cout << i; cout << ' ';cout << j; cout << ']';
			}
			cout << '\n';
		}
	}
	//displays the actual play area grid, starts out all blank until cells get added
	void displayGrid() {
		//print
		for (int i = 0; i < SpaceHeight; ++i)
		{
			for (int j = 0; j < SpaceWidth; ++j)
			{
				if (playArea[i][j] == 1) {
					cout << 'X';
				}
				else {
					cout << '_';
					
				};
			}
			cout << '\n';
		}
	};
};