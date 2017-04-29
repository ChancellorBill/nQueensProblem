// William Munshaw
// depricatedFunctions.cpp

#include "generation.h"
#include <iostream>
#include <random>

//Functions from the Generation Class:

int generation::generationalCleansing() // Discard the worse performers of the previous generation. Not used at this time - Depricated
{
	int discardedBoards = 0;
	for (int i = 0; i < chessBoardVector.size(); i++)
	{
		if (chessBoardVector[i].getFitness() < avgFitness)
		{
			//chessBoardVector[i].printBoard();
			chessBoardVector.erase(chessBoardVector.begin() + i);
			discardedBoards++;
			i--;
		}
	}
	return discardedBoards;
}

int generation::replacement(int discardedBoards, int userDeclaredSize) // Create new members to replace those discarded from the last generation. Not used at this time - Depricated
{
	int newBoards = 0;
	for (int i = 0; i < discardedBoards; i++)
	{
		chessBoard* tempBoard = new chessBoard;
		tempBoard->creation(userDeclaredSize);
		chessBoardVector.push_back(*tempBoard);
		delete tempBoard;
		newBoards++;
	}
	return newBoards;
}


// From the Reproduction function in the chessBoard class:

//for (int i = 0; i < parent1.getBoardSize(); i++) // Old method of choosing each value independently
//{
//	tempValue = rand() % 100+1;
//	if (tempValue < 50)
//	{
//		//cout << "Gene from parent 1" << endl;
//		board.push_back(parent1.getGene(i));
//	}
//	else
//	{
//		//cout << "Gene from parent 2" << endl;
//		board.push_back(parent2.getGene(i));
//	}
//	mutation(i, parent1.getBoardSize());
//}

//////////////////////////////////////////////////////////////