// William Munshaw
// generation.h

#pragma once
#include "Header.h"
#include "chessBoard.h"

class generation
{
	private:
		vector<chessBoard> chessBoardVector;
		int generationNumber;
		int generationSinceLastAVGFitnessChange;
		int speciesNumber;
		int maxFitness;
		int minFitness;
		int avgFitness;
		bool boardWithOutCaptures;
	public:
		void intialGeneration(int userDeclaredSize, int species);
		void generationNext(int userDeclaredSize, int species);
		int generationalCleansing(); // Depricated
		int replacement(int discardedBoards, int userDeclaredSize); // Depricated
		void newBoardCreation();
		void determineGenerationStats();
		void printGenerationStats();
};

