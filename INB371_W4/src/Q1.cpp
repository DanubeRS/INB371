/*
    IndexArray (c) Daniel Park 2013
    
    A program which uses the interfacing features of c++ to generate a random number

    v0.1
    ====
    -Initial creation


*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "supplied/random.h"

using namespace std;

//Function Prototypes


//Program Entry Point
int main()
{

    //Inform the user of the program:
    cout << "================================" << endl;
    cout << "|          IndexArray          |" << endl;
    cout << "================================" << endl;
    cout << "|    (c)  Daniel Park 2013     |" << endl;
    cout << "|     ***INB371_S1_W3_Q5***    |" << endl;
    cout << "================================" << endl << endl;

    //DEBUG
    
   	int runs;
   	cout << "How many runs?" << endl;
   	cin >> runs;

   	double trials[runs];	//Build an array with space for every run
   	double upper = 1.0; double lower = 0.0;

   	for (int i = 0; i < runs; i++){
		Randomize();	//Reseed
		trials[i] = RandomReal(lower, upper);	//Implicitly cast to ensure compatability
		cout << "Trial " << i << " gave " << trials[i] << endl;
   	}

   	double runningTotal;
   	//find the average of all results
   	for (int i = 0; i < runs; i++){
   		runningTotal += trials[i];
   	}
   	cout << "Mean of all results: " << runningTotal / runs << endl;

}