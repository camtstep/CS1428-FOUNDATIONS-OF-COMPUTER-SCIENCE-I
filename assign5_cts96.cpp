// File Name: assign5_cts96.cpp
//
// Author: Cameron Stepanski
// Date: 4/4/2020
// Assignment Number: 5
// CS 1428.253 Spring 2020
// Instructor: Jill Seaman
//
// This program reads in cereal box weights and finds the average of the box
// weights, the standard deviation, the number of boxes below 20 ounces, the
// fine owed by the company for the underweight boxes, and the heaviest box.

#include <iostream>
#include <fstream>
#include <cmath>
#include <iomanip>
#include <string>

using namespace std;

int main(){

const int SIZE = 1000; // number of values in datafile
const int ADVERTISED_WEIGHT = 20; // weight in ounces each box is supposed to be
const int FINE = 250000; // fine in dollars for each box under 20 ounces
string datafile; // stores user input datafile name
ifstream inputFile; // input file stream to open datafile
double cerealData[SIZE]; // array that holds 1000 values from a datafile

cout << "Please enter the name of the data file: ";
cin >> datafile;

inputFile.open(datafile.c_str());

if(!inputFile)
{
    cout << "File open failure!";
    return -1;
}

// Input data from file into array

for(int i=0; i<SIZE; i++)
    inputFile >> cerealData[i];

inputFile.close();

cout << fixed << setprecision(3);

cout << endl << "Chocolate Frosted Sugar Bombs Statistics:" << endl << endl;

// Average weight

double totalForAverage = 0; // used to sum total weight of all boxes
double average; // average weight of boxes

for(int j=0; j<SIZE; j++)
    totalForAverage += cerealData[j];

average = totalForAverage / SIZE;

cout << "Average weight: " << average << endl;

// Standard deviation

double totalStandardDeviation = 0; // total used to calculate standard deviation
double averageStandardDeviation; // average used to calculate standard deviation
double standardDeviation; // standard deviation of boxes

for(int k=0; k<SIZE; k++)
    totalStandardDeviation += pow(cerealData[k] - average,2);

averageStandardDeviation = totalStandardDeviation / SIZE;

standardDeviation = sqrt(averageStandardDeviation);

cout << "Standard deviation: " << standardDeviation << endl << endl;

// Number of boxes below 20 ounces

int countBelow20 = 0; // accumulator for boxes under 20 ounces

for (int l=0; l<SIZE; l++)
    if(cerealData[l] < ADVERTISED_WEIGHT)
        countBelow20++;

cout << "Number of boxes below 20 ounces: " << countBelow20 << endl;

// Fine owed by company for underweight boxes

double totalFine = 0; // total fine for underweight boxes

for(int m=0; m<SIZE; m++)
    if(cerealData[m] < ADVERTISED_WEIGHT)
        totalFine += FINE;

cout << "The fine for this is: $" << setprecision(0) << totalFine << endl
     << endl;

// Max weight of the boxes

double max = cerealData[0]; // max weight of all boxes

for(int n=1; n<SIZE; n++)
    if(max < cerealData[n])
        max = cerealData[n];

cout << "Maximum weight of all boxes: " << setprecision(3) << max << endl;

return 0;
}
