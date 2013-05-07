/*
 * File: Cannonballs.cpp
 * Uses a recursive function to calculate the number of cannonballs in a
 * square pyramid if a given height.
 */
#include <iostream>
#include <cstdlib>
#include <cmath>


using namespace std;

int Cannonball(int);

int main()
{

    for (int i = 1; i < 10; i++)
    {
        cout << "For a stack " << i << " high, there are " << Cannonball(i) << " cannonballs." << endl;
    }

    return 0;
}

/* Recursive function to determine the number of cannonballs in a stack
 * shaped as a square pyramid. */
int Cannonball(int n)
{
    //This function returns the summed linearly-reducing square of cannonballs.
    //The stack is created by: n^2 + (n-1)^2 + ... + 2^2 + 1^2.
    //Recursion is used.

    int balls = 0;

    if (n == 1)
    {
        balls += 1;
    }
    else if (n > 1)
    {
        balls = Cannonball(n - 1) + pow(n, 2);
    }
    else
    {
        //Something bad happened!
        cout << "Internal error has occoured" << endl;
        exit(-1);
    }

    return balls;
}
