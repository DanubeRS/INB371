/*
    IndexArray (c) Daniel Park 2013
    
    A program which uses the interfacing features of c++ to generate a random number

    v0.1
    ====
    -Initial creation
    v1.0
    ====
    -Partial solution commited
    v1.1
    ====
    -Attempted fix for Issue #1 (Randomize not working)


*/

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "supplied/random.h"

using namespace std;

//Function Prototypes

double SeedAndRand(double min, double max);		//Used to circumvent issue 1

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

   	Randomize(); // Randomise to only be called ONCE at start of program

   	for (int i = 0; i < runs; i++){
		/*	===FAILED TO WORK (See issue #1)
		Randomize();	//Reseed
		trials[i] = RandomReal(lower, upper);	//Implicitly cast to ensure compatability
		*/
		trials[i] = RandomReal(upper, lower);
		cout << "Trial " << i << " gave " << trials[i] << endl;
   	}

   	double runningTotal;
   	//find the average of all results
   	for (int i = 0; i < runs; i++){
   		runningTotal += trials[i];
   	}
   	cout << "Mean of all results: " << runningTotal / runs << endl;

}

/*
	Conglomorate function used in an attempt to solve Issue #1
	Accepts upper and lower limits for a randomisation, and will return the random value.
	Reseeds the randomisation pool before calling tool function.
*/
double SeedAndRand(double min, double max){
	return RandomReal(min, max);
}