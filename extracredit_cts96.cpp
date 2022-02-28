// File Name: extracredit_cts96.cpp
//
// Author: Cameron Stepanski
// Date: 3/23/2020
// Assignment Number: extra credit
// CS 1428.253 Spring 2020
// Instructor: Jill Seaman
//
// This program generates a random number between 1 and 100 and lets the user
// guess the number while tallying the number of tries.

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int main(){

    int randomNumber; // stores computer generated random number
    int userNumber; // stores user's guess
    int tries = 1; // counts number of guesses

    //generates a random number between 1 and 100
    srand(time(NULL));
    randomNumber = rand() % 100 + 1;

    cout << "Please enter a number between 1 and 100: ";
    cin >> userNumber;

    while(randomNumber != userNumber)
    {
        if(userNumber < randomNumber)
        {
            cout << "Too low, try again." << endl;;
        }
        else
        {
            cout << "Too high, try again." << endl;
        }

        cout << "Please enter a number between 1 and 100: ";
        cin >> userNumber;
        tries++;
    }

    cout << "Correct. You guessed " << tries << " times.";

    return 0;
}
