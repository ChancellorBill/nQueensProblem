// William Munshaw
// Header.h

#pragma once
#include <string>

using namespace std;

//Program Messages
string const welcomeMSG = "Welcome to n Queens Solver!";
string const requestInfoMSG = "Please enter a number greater than 3 and smaller than or equal to 50 for the size of the problem you would like to solve:";
string const outOfBoundsMSG = "Number must be in the range of 4-50. Try again:";
string const winnerMSG = "Board without Captures Found! It is: ";
string const winnerGenMSG = " and it belonged to the following generation:";
string const maxFitMSG = "The Maximinum Fitness is: ";
string const minFitMSG = "The Minimum Fitness is: ";
string const avgFitMSG = "The Average Fitness is: ";
string const currentGenMSG = "The Stats for Generation ";
string const currentSpeciesMSG = " of Species ";
string const genPopMSG = "The size of this generation is: ";
string const lowPopWarningMSG = "Population is too small to continue! New species needed!";
//////////////////

//Global Constants
int const initialPopulation = 20000;
int const minAcceptedValue = 4;
int const maxAcceptedValue = 50;
int const intialFitness = maxAcceptedValue * 2;
int const mutationFactor = 1; // Precent Chance of Mutation
//////////////////

//Prototype Definitions:
int welcomeAndUserInput();
///////////////////////