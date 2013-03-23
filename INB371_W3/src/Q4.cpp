/*
    GetDomain (c) Daniel Park 2013
    
    Simple program to calculate the domain of a supplied array

    v0.1
    ====
    -Initial creation

    v1.0
    ====
    -Completed program


*/


#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

//Function Prototypes
void MinMax(int a[], int l, int &lower, int &upper);        //Returns the minimum and maximum bounds of a passed array

//Program Entry Point
int main()
{

    //Inform the user of the program:
    cout << "================================" << endl;
    cout << "|         PrimeFinderTM        |" << endl;
    cout << "================================" << endl;
    cout << "|    (c)  Daniel Park 2013     |" << endl;
    cout << "|     ***INB371_S1_W3_Q1***    |" << endl;
    cout << "================================" << endl << endl;

    //Code derived from MinMax.cpp by Malcom Corney
    
    int min, max;

    // test arrays  
    int values1[] = { 67, 78, 75, 70, 71, 80, 69, 86, 65, 54, 76, 78, 70, 68, 77 };
    int values2[] = { 50 };
    int values3[] = { 50, 50, 50, 50, 50, 50, 50};


    MinMax(values1, sizeof values1 / sizeof values1[0], min, max);
    cout << "minimum = " << min << endl;
    cout << "maximum = " << max << endl;

    cout << endl;
    MinMax(values2, sizeof values2 / sizeof values2[0], min, max);
    cout << "minimum = " << min << endl;
    cout << "maximum = " << max << endl;

    cout << endl;
    MinMax(values3, sizeof values3 / sizeof values3[0], min, max);
    cout << "minimum = " << min << endl;
    cout << "maximum = " << max << endl;

    return 0;
    

}

/*
    Determines the domain of values within a specified array. Passed by reference. Length specified
*/
void MinMax(int a[], int l, int &lower, int &upper){

    lower = a[0]; upper = a[0]; //Starting with the first element, compare hereon in

    //Iterate through the array
    for (int i = 1; i < l; i++){
        if(a[i] < lower){ lower = a[i];}   //Get the lower value if it is smaller
        if(a[i] > upper){ upper = a[i];}   //Get the lower value if it is smaller
    }

}