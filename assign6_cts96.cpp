// File Name: assign6_cts96.cpp
//
// Author: Cameron Stepanski
// Date: 4/18/2020
// Assignment Number: 6
// CS 1428.253 Spring 2020
// Instructor: Jill Seaman
//
// This program computes earnings on an initial investment at a user-input
// interest rate for a user-input number of years. It also outputs how many
// years it will take to double and what year the investment will reach one
// million dollars.

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//***********************************************************
// getInput: prompts user to input initial investment amount, interest rate, and
// number of years the investment will grow
// investment the initial investment
// rate the interest rate
// years number of years the investment will grow
//***********************************************************

void getInput(double &investment,double &rate,int &years)
{
    cout << "Enter your initial investment amount: ";
    cin >> investment;
    while(investment < 100 || investment > 1000000)
    {
        cout << "Please enter a valid investment amount: ";
        cin >> investment;
    }

    cout << "Enter the annual interest rate: ";
    cin >> rate;
    while(rate <= 0 || rate > 50)
    {
        cout << "Please enter a valid annual interest rate: ";
        cin >> rate;
    }

    cout << "Enter the number of years for the investment: ";
    cin >> years;
    while(years <= 0 || years > 80)
    {
        cout << "Please enter a valid number of years for the investment: ";
        cin >> years;
    }

    cout << endl;
}

//***********************************************************
// calculateFV: calculates future value of investment
// investment the initial investment
// rate the interest rate
// years number of years the investment will grow
// returns: future value of investment
//***********************************************************

double calculateFV(double investment,double rate,int years)
{
    return investment * pow(((rate) + 1),years);
}

//***********************************************************
// yearsToDouble: calculates how many years to double an investment
// rate the interest rate
// returns: number of years to double investment rounded up to nearest whole
// number
//***********************************************************

double yearsToDouble(double rate)
{
    return ceil(.727 / (rate));
}

//***********************************************************
// yearsToOneMillion: calculates how many years for an investment to reach one
// million dollars
// investment the initial investment
// rate the interest rate
// returns: number of years to reach one million dollars rounded up to nearest
// whole number
//***********************************************************

int yearsToOneMillion(double investment,double rate)
{
    return ceil((log(1000000) - log (investment)) / log(1 + (rate)));
}

//***********************************************************
// outputTable: outputs a table of the initial investment at year 0 and then
// each subsequent year and the value of the investment at that point all the
// way until the user-input number of years to let the investment grow. It also
// outputs the number of years for the investment to double and the year that
// the investment will have grown to one million dollars
// investment the initial investment
// rate the interest rate
// years number of years the investment will grow
//***********************************************************

void outputTable(double investment,double rate,int years)
{
    cout << "Year" << setw(20) << "Balance" << endl;
    cout << "----  ------------------" << endl;
    cout << fixed << setprecision(2);

    for(int i=0; i<=years; i++)
    {
        cout << setw(4) << i << setw(20) << calculateFV(investment,rate,i)
             << endl;
    }
}

int main(){

const double PERCENT_TO_DECIMAL = .01; // makes percent decimal when multiplied
const int CURRENT_YEAR = 2020; // current year

double investment; // initial investment amount in dollars
double rate; // interest rate compounded annually
int years; // number of years the investment grows

cout << fixed << setprecision(2);

getInput(investment,rate,years);

// Convert the percent rate to decimal so it's usable in formulas

rate = rate * PERCENT_TO_DECIMAL;

cout << "Future value of investment: $" << calculateFV(investment,rate,years)
     << endl << endl;

outputTable(investment,rate,years);

cout << endl;

cout << "Investment will double in " << setprecision(0) << yearsToDouble(rate)
     << " years";

cout << endl << endl;

cout << "One million dollar year: "
     << (yearsToOneMillion(investment,rate) + CURRENT_YEAR) << endl;

return 0;
}
