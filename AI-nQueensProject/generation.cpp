// William Munshaw
// generation.cpp

#include "generation.h"
#include <iostream>
#include <random>

void generation::intialGeneration(int userDeclaredSize, int species)
{
	speciesNumber = species;
	boardWithOutCaptures = false;
	generationNumber = 1;
	for (int i = 0; i < initialPopulation; i++)
	{
		chessBoard* tempBoard = new chessBoard;
		tempBoard->creation(userDeclaredSize);
		chessBoardVector.push_back(*tempBoard);
		delete tempBoard;
	}
	determineGenerationStats();
	printGenerationStats();
	if (!boardWithOutCaptures)
		generationNext(userDeclaredSize, species);
}

void generation::generationNext(int userDeclaredSize, int species)
{	
	generationNumber++;

	newBoardCreation();
	determineGenerationStats();
	printGenerationStats();
	if (!boardWithOutCaptures)
	{
		if (chessBoardVector.size() < 100) // If population drops below 100, it is determined that the "specices" has failed to be fit enough and is replaced entirely
		{
			cout << lowPopWarningMSG << endl;
			species++;
			intialGeneration(userDeclaredSize, species);
		}
		else
			generationNext(userDeclaredSize, species);
	}
}

void generation::newBoardCreation()
{
	mt19937 randomNumber; // Decided to use a more modern approach to random numbers for the selection of the second parent. Old method will still be used elsewhere in the program
	randomNumber.seed(random_device()());
	vector<chessBoard> tempVector;
	int fitnessThreshold = avgFitness;
	for (int i = 0; i < initialPopulation; i++) // Reproduction with random parents
	{
		uniform_int_distribution<int> distribution(0, chessBoardVector.size() - 1);
		int parent1 = distribution(randomNumber);
		int parent2 = distribution(randomNumber);		
		if (chessBoardVector[parent1].getFitness() > fitnessThreshold && chessBoardVector[parent2].getFitness() > fitnessThreshold) //Only accept parents with greater than average fitness
		{
			chessBoard* tempBoard = new chessBoard;
			tempBoard->reproduction(chessBoardVector[parent1], chessBoardVector[parent2]);
			tempVector.push_back(*tempBoard);
			delete tempBoard;
		}
	}
	chessBoardVector.erase(chessBoardVector.begin(), chessBoardVector.end()); // Delete the old board
	for (int i = 0; i < tempVector.size(); i++) // Put new board into the generation
	{
		chessBoardVector.push_back(tempVector[i]);
	}
}

void generation::determineGenerationStats()
{
	int currentMax = 0;
	int currentMin = intialFitness;
	int currentAVG = 0;
	int allFitness = 0;
	for (int i = 0; i < chessBoardVector.size(); i++)
	{
		if (currentMax < chessBoardVector[i].getFitness())
		{
			currentMax = chessBoardVector[i].getFitness();
		}
		if (currentMin > chessBoardVector[i].getFitness())
		{
			currentMin = chessBoardVector[i].getFitness();
		}
		allFitness += chessBoardVector[i].getFitness();
		if (chessBoardVector[i].getFitness() == intialFitness)
		{
			cout << winnerMSG << endl;
			chessBoardVector[i].printBoard();
			boardWithOutCaptures = true;
			cout << winnerGenMSG << endl;
		}
	}
	maxFitness = currentMax;
	minFitness = currentMin;
	currentAVG = allFitness / chessBoardVector.size();
	if (currentAVG != avgFitness)
	{
		generationSinceLastAVGFitnessChange = generationNumber;
	}
	avgFitness = currentAVG;
}

void generation::printGenerationStats()
{
	cout << currentGenMSG << generationNumber << currentSpeciesMSG << speciesNumber << endl;
	cout << genPopMSG << chessBoardVector.size() << endl;
	cout << maxFitMSG << maxFitness << endl;
	cout << minFitMSG << minFitness << endl;
	cout << avgFitMSG << avgFitness << endl << endl;
}