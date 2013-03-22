/*
    Weekdays (c) Daniel Park 2013

    A simple program that calculates the prime numbers within a range, returning
    both the values themselves, and the cumulative number of them.

    v0.1 Primary
    Changelog++

    0.1
    ===
    -Initial Creation

    1.0
    ===
    -Completed program
*/


#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>    //For filling entire array with set value    

using namespace std;

//Function Prototypes
void findPrimes(bool *p, int l);   //Find all primes within a range
void listPrimes(bool *p, int l);    //List all primes directly via std::cout
int  countPrimes(bool *p, int l);
void fillTrue(bool *array, int l);

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
    cin >> range;

    //Create an array of which the upper bound coincides with the inputted int
    bool primes[range + 1];
    fillTrue(primes, range); //Fill array using <algorithm>std::fill
    primes[1] = false; primes[0] = false;   //We already know that 0 and 1 are not primes

    findPrimes(primes, range + 1);   //Pass to function BY REFERENCE
    listPrimes(primes, range + 1);
    cout << "There are " <<  countPrimes(primes, range + 1) << " primes from 0 to " << range << endl;
    
}

void findPrimes(bool *p, int l){

    //Using Eratosthenes method of prime elimination, use an iterative process to find primes

    //Iterate across all values
    for (int i = 0; i < l + 1; i++){
        
        //Only perform any operations on the values not already declared false
        if (p[i]){

            //DEBUG
            //cout << "Calculating " << i << endl;

            //set all prime multiples of i(indices herin known as n) to false
            for (int n = 2*i; n <= l; n += i){
                p[n] = false;
                
                //DEBUG
                //cout << n << " is not a prime" << endl;
            }
        }
    }

}

void fillTrue(bool *array, int l){

    //DEBUG
    //cout << "Filling with true" << endl;

    for (int i = 0; i <= l; i++){
        array[i] = true;
    }
    //DEBUG
    //out << "True filling finished " << endl;
}
void listPrimes(bool *p, int l){

    //Status message
    cout << "Primes are: ";
    for (int i = 0; i <= l; i++){
        if (p[i]){
            cout << i << " ";
        }
    }
    cout << endl << "Prime listing finished" << endl;

}
int  countPrimes(bool *p, int l){
    
    //Status message
    cout << "Counting Primes: ";
    int sum = 0;
    for (int i = 0; i <= l; i++){
        if (p[i]){
            sum++;
        }
    }
    cout << endl << "Prime Counting finished" << endl;
    return sum;
}