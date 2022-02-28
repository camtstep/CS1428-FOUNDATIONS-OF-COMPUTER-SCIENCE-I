// File Name: assign7_cts96.cpp
//
// Author: Cameron Stepanski
// Date: 4/26/2020
// Assignment Number: 7
// CS 1428.253 Spring 2020
// Instructor: Jill Seaman
//
// This program manages a grade book for a history course. It computes a
// student's final average and letter grade and outputs it for the entire class.
// It outputs the class average and student with the highest average and what
// the highest average is.

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Student
{
    string lastName; // student last name
    float finalAverage; // final number grade
    string letterGrade; // final letter grade
};

void calculateAverages(Student roster[]);
void dataTable(Student roster[]);
float classAverage(Student roster[]);
int highestAverage(Student roster[]);

const int NUMBER_OF_STUDENTS = 5; // number of students in class
const float MIDTERM_WEIGHT = .4; // weight of midterm on final average
const float FINAL_WEIGHT = .6; // weight of final exam on final average

int main()
{
    Student roster[NUMBER_OF_STUDENTS]; // array of 5 student structures

    // initialize the roster
    roster[0] = {"Cooper", 0.0, "U"};
    roster[1] = {"Fields", 0.0, "U"};
    roster[2] = {"Garcia", 0.0, "U"};
    roster[3] = {"Parson", 0.0, "U"};
    roster[4] = {"Suarez", 0.0, "U"};

    cout << fixed << setprecision(1);

    // input grades and calculate averages and letter grades
    calculateAverages(roster);
    cout << endl;

    // output student names, averages, and letter grades
    dataTable(roster);
    cout << endl;

    // calculate class average
    cout << "The class average: " << classAverage(roster);
    cout << endl << endl;

    // find the student with the highest average
    cout << "The student who earned the highest grade is: "
         << roster[highestAverage(roster)].lastName
         << " " << roster[highestAverage(roster)].finalAverage << endl;

    return 0;

}

//***********************************************************
// calculateAverages: calculates the average for each student and assigns a
// letter grade
// roster the array of student structures
//***********************************************************

void calculateAverages(Student roster[])
{
    float midterm; // midterm grade
    float finalExam; // final exam grade

    cout << "Enter the midterm and final exam score for each student:" << endl;

    for(int i=0; i<NUMBER_OF_STUDENTS; i++)
    {
        cout << roster[i].lastName << ": ";
        cin >> midterm >> finalExam;

        // assign number grade
        roster[i].finalAverage = (midterm * MIDTERM_WEIGHT) +
                                 (finalExam * FINAL_WEIGHT);

        // assign letter grade
        if(roster[i].finalAverage >= 89.5)
            roster[i].letterGrade = "A";
        else if(roster[i].finalAverage >= 79.5)
            roster[i].letterGrade = "B";
        else
            roster[i].letterGrade = "EP";
    }
}

//***********************************************************
// dataTable: outputs the student names, averages, and letter grades
// roster the array of student structures
//***********************************************************

void dataTable(Student roster[])
{
    cout << "Class Roster:" << endl;

    for(int j=0; j<NUMBER_OF_STUDENTS; j++)
    {
        cout << roster[j].lastName << "..." << roster[j].finalAverage << "..."
             << roster[j].letterGrade << endl;
    }
}

//***********************************************************
// classAverage: calculates the class average
// roster the array of student structures
// returns the class average
//***********************************************************

float classAverage(Student roster[])
{
    float total = 0; // used to add up all student grades

    for(int k=0; k<NUMBER_OF_STUDENTS; k++)
    {
        total += roster[k].finalAverage;
    }

    return total / NUMBER_OF_STUDENTS;
}

//***********************************************************
// highestAverage: determines the highest average in the class
// roster the array of student structures
// returns the index in the roster array that corresponds to the student with
// the highest average
//***********************************************************

int highestAverage(Student roster[])
{
    int highest = 0; // used to find the index with the highest average

    for(int l=1; l<NUMBER_OF_STUDENTS; l++)
        if(roster[l].finalAverage > roster[highest].finalAverage)
            highest = l;

    return highest;
}
