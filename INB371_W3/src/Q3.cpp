/*
    Weekdays (c) Daniel Park 2013

    A simple program that calculates the prime numbers within a range, returning
    both the values themselves, and the cumulative number of them.

    v0.1 Primary
    Changelog++

    0.1
    ===
    -Initial Creation
*/


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>    //For filling entire array with set value    

using namespace std;

//Function Prototypes
int* findPrimes(bool primes, int length);   //Find all primes within a range
void listPrimes(bool primes, int length);    //List all primes directly via std::cout
int  countPrimes(bool primes, int length);

int main()
{

    //Inform the user of the program:
    cout << "================================" << endl;
    cout << "|         PrimeFinderTM        |" << endl;
    cout << "================================" << endl;
    cout << "|    (c)  Daniel Park 2013     |" << endl;
    cout << "|     ***INB371_S1_W3_Q1***    |" << endl;
    cout << "================================" << endl << endl;

    //Initialise global variables, and constants
    int range;      //Range (within values holding int) to search for primes.

    cout << "Please enter an upper limit of which you wish to find primes (Starting from zero)" << endl;
    cin >>  int;

    //Create an array of which the upper bound coincides with the inputted int
    bool primes[range+1];
    fill(primes[0], primes[range + 1], true); //Fill array using <algorithm>std::fill

    findPrimes(primes, range + 1);   //Pass to function BY REFERENCE
    listPrimes(primes, range + 1);
    countPrimes(primes, range + 1);
    
}

int* findPrimes(bool primes, int length){

    //Using Eratosthenes method of prime elimination, use an iterative process to find primes
    

}

    