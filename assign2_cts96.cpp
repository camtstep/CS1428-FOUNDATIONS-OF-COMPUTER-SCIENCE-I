// File Name: assign2_cts96.cpp
//
// Author: Cameron Stepanski
// Date: 2/9/2020
// Assignment: Number 2
// CS 1428.253 Spring 2020
// Instructor: Jill Seaman
//
// This program calculates calories and percentages of macronutrients and the
// Protein:Energy ratio

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    int carbohydrate; // numerical value for grams of carbohydrate
    int fat; // numerical value for grams of fat
    int protein; //numerical value for grams of protein
    int calCarbohydrate; // numerical value for carbohydrate calories
    int calFat; // numerical value for fat calories
    int calProtein; // numerical value for protein calories
    int totalGrams; //numerical value for total grams of macronutrients
    int totalCalories; // numerical value for total calories of macronutrients

    cout << "Please enter the amount of carbohydrate in grams: ";
    cin >> carbohydrate;

    cout << "Please enter the amount of fat in grams: ";
    cin >> fat;

    cout << "Please enter the amount of protein in grams: ";
    cin >> protein;

    calCarbohydrate = carbohydrate * 4;
    calFat = fat * 9;
    calProtein = protein * 4;

    totalGrams = carbohydrate + fat + protein;
    totalCalories = calCarbohydrate + calFat + calProtein;

    cout << endl;
    cout << left << setw(15) << "Total Grams" << ": " << totalGrams << endl;
    cout << left << setw(15) << "Total Calories" << ": " << totalCalories
         << endl << endl;

    cout << "Percent of calories from each macronutrient:" << endl;
    cout << fixed << setprecision(1);
    cout << setw(14) << left << "Carbohydrate:"
         << (static_cast<double>(calCarbohydrate) / totalCalories) * 100 << "%"
         << endl;
    cout << setw(14) << left << "Fat:"
         << (static_cast<double>(calFat) / totalCalories) * 100 << "%" << endl;
    cout << setw(14) << left << "Protein: "
         << (static_cast<double>(calProtein) / totalCalories) * 100 << "%"
         << endl << endl;

    cout << "Protein: Energy Ratio : "
         << static_cast<double>(protein) / (fat + carbohydrate);

    return 0;
}
