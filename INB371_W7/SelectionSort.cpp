/*
 * File:  SelectionSort.cpp
 * Provides an implementation and usage of SelectionSort algorithm.
 */

#include <iostream>
#include <time.h>
#include <stdio.h>
#include "random.h"

using namespace std;

const int N = 26000;

/*
 * Sorts an array of int using the selection sort algorithm.
 * Performance is O(N^2)
 */
template <typename ElemType>
void SelectionSort(ElemType *);

int main()
{

    // fill an array with random integers
    int values[N];
    Random random;
    for (int i = 0; i < N; i++)
    {
        values[i] = random.RandomInteger(0, N * 10);
    }

    //Start timing
    clock_t timer = clock();
    // sort
    SelectionSort(values);
    //end timing
    timer = clock() - timer;

    cout << "Time taken: " << timer << " ticks" << endl;

    // output
    /*
    for (int i = 0; i < N; i++)
    {
        cout << values[i] << " ";
    }
    cout << endl;
    */

    return 0;
}

/*
 * Sorts an array of int using the selection sort algorithm.
 * Performance is O(N^2)
 */
template <typename ElemType>
void SelectionSort(ElemType *values)
{

    // for each position in the array
    for (int lh = 0; lh < N; lh++)
    {

        // find the smallest value in the unsorted portion of the array
        int rh = lh;
        for (int i = lh + 1; i < N; i++)
        {
            if (values[i] < values[rh])
                rh = i;
        }

        // swap the values
        ElemType temp = values[lh];
        values[lh] = values[rh];
        values[rh] = temp;
    }
}
