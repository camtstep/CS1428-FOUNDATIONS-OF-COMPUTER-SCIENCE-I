// File Name: assign3_cts96.cpp
//
// Author: Cameron Stepanski
// Date: 2/26/2020
// Assignment Number: 3
// CS 1428.253 Spring 2020
// Instructor: Jill Seaman
//
// This program calculates your monthly bill based on your voice plan and
// minutes used.

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    char plan; // represents voice plan chosen
    int minutes; // total minutes used during the month
    double totalBill; // bill for the month if over minutes included in plan
    double savings; // savings if you were on the next tier voice plan

    const double PLAN_A_COST = 39.99;
    const double PLAN_B_COST = 59.99;
    const double PLAN_C_COST = 69.99;

    const int MINUTES_INCLUDED_IN_PLAN_A = 450;
    const int MINUTES_INCLUDED_IN_PLAN_B = 900;

    const float PLAN_A_ADDITIONAL_MINUTE_COST = .45;
    const float PLAN_B_ADDITIONAL_MINUTE_COST = .40;

    cout << "Voice Plans:\n";
    cout << "A. The 450 minute plan\n";
    cout << "B. The 900 minute plan\n";
    cout << "C. The unlimited plan\n";
    cout << "Enter which voice plan the customer subscribes to: ";

    cin >> plan;

    cout << "Enter the total number of minutes used during the month: ";

    cin >> minutes;

    cout << fixed << setprecision(2);

    if (minutes < 0 || minutes > 44640)
    {
        cout << "That is not a valid amount for the minutes.";
    }
    else
    {
        if (plan == 'A')
        {
            if (minutes <= MINUTES_INCLUDED_IN_PLAN_A)
            {
                cout << endl;
                cout << "The amount due for the month is $" << PLAN_A_COST;
            }
            else
            {
                totalBill = PLAN_A_COST + ((minutes - MINUTES_INCLUDED_IN_PLAN_A)
                            * PLAN_A_ADDITIONAL_MINUTE_COST);

                cout << endl;
                cout << "The amount due for the month is $" << totalBill  << endl;

                if (totalBill > PLAN_B_COST)
                {
                    savings = totalBill - PLAN_B_COST;

                    cout << "Amount saved if you were on Plan B: $" << savings;
                }
            }
        }
        else if (plan == 'B')
        {
            if (minutes <= MINUTES_INCLUDED_IN_PLAN_B)
            {
                cout << endl;
                cout << "The amount due for the month is $" << PLAN_B_COST;
            }
            else
            {
                totalBill = PLAN_B_COST + ((minutes - MINUTES_INCLUDED_IN_PLAN_B)
                            * PLAN_B_ADDITIONAL_MINUTE_COST);

                cout << endl;
                cout << "The amount due for the month is $" << totalBill << endl;

                if (totalBill > PLAN_C_COST)
                {
                    savings = totalBill - PLAN_C_COST;

                    cout << "Amount saved if you were on Plan C: $" << savings;
                }
            }
        }
        else if (plan == 'C')
        {
            cout << "The amount due for the month is $" << PLAN_C_COST;
        }
        else
        {
            cout << "The voice plan entered is invalid.";
        }
    }

    return 0;
}
