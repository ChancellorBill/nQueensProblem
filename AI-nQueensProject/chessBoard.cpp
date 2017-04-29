// William Munshaw
// chessBoard.cpp

#include "chessBoard.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

void chessBoard::creation(int n)
{
	for (int i = 0; i < n; i++)
	{
		board.push_back(rand() % n);
		//cout << board[i] << " ";
	}
	//cout << endl;
	calculateFitness();
	//cout << fitness << endl;
}

void chessBoard::reproduction(chessBoard parent1, chessBoard parent2)
{
	int tempValue;
	int middleValue = rand() % parent1.getBoardSize(); // Decide how many values come from parent 1 vs parent 2
	/*cout << endl;
	parent1.printBoard();
	parent2.printBoard();
	cout << middleValue << endl;*/
	for (int i = 0; i < middleValue; i++)
	{
		board.push_back(parent1.getGene(i));
		mutation(i, parent1.getBoardSize());
	}
	for (int j = middleValue; j < parent2.getBoardSize(); j++)
	{
		board.push_back(parent2.getGene(j));
		mutation(j, parent2.getBoardSize());
	}
	//printBoard();
	
	calculateFitness();

}

void chessBoard::mutation(int i, int boardSize)
{
	int randomNumber = rand() % 100 + 1;
	int increaseOrDecrease = rand() % 100;
	if (randomNumber <= mutationFactor) // percent chance of mutation
	{
		//cout << "Mutation!" << endl;
		if (increaseOrDecrease < 50) // Determines if it will go up or down
		{
			if (board[i] == 0) // Check for roll over
			{
				board[i] = boardSize-1;
			}
			else
				board[i]--;
		}
		else
		{
			if (board[i] == boardSize-1) // Check for roll over
			{
				board[i] = 0;
			}
			else
				board[i]++;
		}
	}
}

void chessBoard::calculateFitness()
{
	int currentFitness = intialFitness;
	currentFitness -= searchForAttacks();
	fitness = currentFitness;
}

int chessBoard::searchForAttacks()
{
	int attacks = 0;
	for (int i = 0; i <= board.size(); i++)
	{
		for (int j = i + 1; j < board.size(); j++)
		{
			//cout << "Compare: " << board[i] << " at " << i << " with " << board[j] << " at " << j << endl;
			int k = j - i;
			if (board[i] == board[j] || board[i] == board[j] + k || board[i] == board[j] - k)
			{
				attacks++;
				//cout << "There is an attack with " << board[i] << " at " << i << " with " << board[j] << " at " << j << endl;
			}				
		}
	}
	return attacks;
}

int chessBoard::getFitness()
{
	return fitness;
}

int chessBoard::getGene(int i)
{
	return board[i];
}

int chessBoard::getBoardSize()
{
	return board.size();
}

void chessBoard::printBoard()
{
	for (int i = 0; i < board.size(); i++)
	{
		cout << board[i] << " ";
	}
	cout << endl;
}