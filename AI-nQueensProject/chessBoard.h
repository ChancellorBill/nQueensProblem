// William Munshaw
// chessBoard.h

#pragma once
#include <vector>
#include "Header.h"

using namespace std;

class chessBoard
{
	private:
		vector<int> board;
		int fitness;
	public:
		void creation(int n);
		void calculateFitness();
		//void searchColumns(); // Not necessary since each index in the vertex represents a column. There will never be more than one queen in a column
		int searchForAttacks(); // Used to find number of attacking queens
		void reproduction(chessBoard parent1, chessBoard parent2);
		void mutation(int i, int boardSize);
		int getFitness();
		int getGene(int i);
		int getBoardSize();
		void printBoard();
};