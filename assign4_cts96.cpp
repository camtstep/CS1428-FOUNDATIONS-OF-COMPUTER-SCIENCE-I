// File Name: assign4_cts96.cpp
//
// Author: Cameron Stepanski
// Date: 3/7/2020
// Assignment Number: 4
// CS 1428.253 Spring 2020
// Instructor: Jill Seaman
//
// This program generates a flu activity report for 3 types of flu for a user
// determined number of weeks.

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main(){

int weeks; // number of weeks to report flu activity
int totalCasesOverall = 0; // total number of flu cases for all weeks
const int CASES_PER_ASTERISK = 250; // number of cases per asterisk on chart

ofstream fout;
fout.open("flu_report.txt");

fout << "Week  Total Cases  Activity        Chart" << endl;

cout << "How many weeks will go in the report? ";
cin >> weeks;

for(int i = 1; i <= weeks; i++)
{
    int fluCases; // cases of each type of flu each week the user inputs
    int totalWeeklyCases = 0; // total cases per week
    int asterisk; // number of asterisks to output to the chart

    for(int j = 0; j <= 2; j++)
    {
        char type = 'A' + j; // flu type

        cout << "Week " << i << " Enter the number of cases of type " << type
             << " ";
        cin >> fluCases;

        totalWeeklyCases += fluCases;
        totalCasesOverall += fluCases;
    }

    fout << setw(3) << i << setw(10) << totalWeeklyCases << setw(16);

    // Determines the severity of flu activity
    if(totalWeeklyCases < 500)
        fout << "Low";
    else if(totalWeeklyCases < 2000)
        fout << "Moderate";
    else
        fout << "Widespread";


    // Determines number of asterisks on chart
    asterisk = totalWeeklyCases / CASES_PER_ASTERISK;

    fout << setw(6) << "|";
    for(int k = 1; k <= asterisk; k++)
        fout << "*";
    fout << endl;

}

cout << "This report is stored in the file flu_report.txt";

fout << "-------------------------------------------------" << endl;
fout << "The total number of cases reported: " << totalCasesOverall;

fout.close();

return 0;
}
