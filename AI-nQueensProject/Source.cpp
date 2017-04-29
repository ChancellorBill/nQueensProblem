// William Munshaw
// Source.cpp

#include <iostream>
#include "chessBoard.h"
#include "Header.h"
#include "generation.h"
#include <time.h>

using namespace std;

int main()
{
	//Declarations:
	int userDeclaredSize = 0;
	srand(time(NULL));
	generation currentGeneration;
	////////////////
	userDeclaredSize = welcomeAndUserInput();
	currentGeneration.intialGeneration(userDeclaredSize, 1);
	return 0;
}

int welcomeAndUserInput()
{
	//Declarations:
	int userChoice = 0;
	///////////////
	cout << welcomeMSG << endl;
	cout << requestInfoMSG << endl;
	do
	{
		cin >> userChoice;
		if (userChoice < minAcceptedValue || userChoice > maxAcceptedValue)
			cout << outOfBoundsMSG << endl;
	} while (userChoice < minAcceptedValue || userChoice > maxAcceptedValue);
	return userChoice;
}