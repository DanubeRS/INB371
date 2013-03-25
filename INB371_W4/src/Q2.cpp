/*
    Heads and Tails (c) Daniel Park 2013

    A program which uses the interfacing features of c++ to generate a heads-or-tails
    probability simulation.

    v0.1
    ====
    -Initial creation

    v1.0
    ====
    -Completed aplliaction
    -Added verbosity prompt

*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "supplied/random.h"

using namespace std;

//Function Prototypes

string VerboseResult(bool res); //Used to convert a boolean to a string representation
void DeviationAnalysis(int th, int tr); //Checking for individual result verbosity
bool CheckForIndividualVerbosity();

//Program Entry Point
int main()
{

    //Inform the user of the program:
    cout << "================================" << endl;
    cout << "|        Heads or Tails        |" << endl;
    cout << "================================" << endl;
    cout << "|    (c)  Daniel Park 2013     |" << endl;
    cout << "|     ***INB371_S1_W3_Q5***    |" << endl;
    cout << "================================" << endl << endl;

    int trials = 0; int totalHeads = 0; //FOr tracking of trialResult
    bool verbIndividual;  //Verbose individual results
    const double CHANCE = 0.5;  //AVOID MAGIC NUMBERS!

    cout << "How many trials?:" << endl;
    cin >> trials;
    cout << "Verbose individual results? (y/n):" << endl;
    verbIndividual = CheckForIndividualVerbosity();

    bool trialResults[trials];  //Store in array for possible finer result analysis

    Randomize();    //Reseed the randomisation engine
    for (int i = 0; i < trials; i++)
    {
        trialResults[i] = RandomChance(CHANCE);
    }

    //Count the amount of heads (and as such, reverse calculate tails)
    for (int i = 0; i < trials; i++)
    {
        if (trialResults[i])
        {
            totalHeads++;
        }
    }

    //Print Results
    if (verbIndividual)
    {
        for (int i = 0; i < trials; i++)
        {
            cout << "Toss " << i << " gave " << VerboseResult(trialResults[i]) << endl;
        }
    }
    cout << "Totals:" << endl << "\t Heads: " << totalHeads << "\t Tails :" << trials - totalHeads << endl;
    DeviationAnalysis(totalHeads, trials);
    return 0;

}
/*
  A function which takes a boolean value, and returns the name of a coin face.
*/
string VerboseResult(bool res)
{
    if (res)
    {
        return "Head";
    }
    else if (!res)
    {
        return "Tail";
    }
    else
    {
        return "";    //Add an exception possibly?
    }
}
void DeviationAnalysis(int th, int tr)
{
    double probabilityCalc = (double) th / (double) tr;
    double fiftyFifty = 0.5;
    cout << "Heads gave tested probability of " << probabilityCalc << endl;
    cout << "This was a " << fiftyFifty - probabilityCalc << " deviation from 50\%" << endl;
}
bool CheckForIndividualVerbosity()
{
    string ans = "";
    cout << "Prompt>>";
    cin >> ans;
    if (ans == "y")
    {
        return true;
    }
    else if (ans == "n")
    {
        return false;
    }
    else
    {
        cout << "Invalid response. Please try again." << endl;
        CheckForIndividualVerbosity();
    } //Cycle function
}
