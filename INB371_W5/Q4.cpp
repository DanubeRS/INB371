/*
    Heads and Tails (c) Daniel Park 2013

    A program which uses the OOP features of c++ to rewrite the random interface as used in W4 tasks.
    v0.1
    ====
    -Initial creation

*/

//Declarations
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <iostream>
//User includes
#include "random.h"
//Good ol' std namespace
using namespace std;
//Program Entry Point
int main()
{

    //Inform the user of the program:
    cout << "================================" << endl;
    cout << "|       Random Class Demo      |" << endl;
    cout << "================================" << endl;
    cout << "|    (c)  Daniel Park 2013     |" << endl;
    cout << "|     ***INB371_S1_W5_Q3***    |" << endl;
    cout << "================================" << endl << endl;

    Random randomClass = Random();

    int value = randomClass.RandomInteger(0,100);
    cout << "Class random value is: " << value << "." << endl;

    return 0;
}
