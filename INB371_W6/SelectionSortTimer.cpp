/*
 * File:  SelectionSort.cpp
 * Provides an implementation and usage of SelectionSort algorithm.
 */

#include <iostream>
#include <iomanip>
#include "random.h"
#include <cmath>

using namespace std;

const int N = 1000;

/*
 * Sorts an array of int using the selection sort algorithm.
 * Performance is O(N^2)
 */
template<typename ValueType>
void SelectionSort(ValueType *);

int main()
{

    // fill an array with random integers
    float *intValues;

    Random random;
    clock_t ticks;

    //Init the random number generator captian!
    for (int ord = 1; ord < 1000; ord++)
    {
        intValues = new float[N*ord];

        for (int i = 0; i < N*ord; i++)
        {
            intValues[i] = random.RandomInteger(0, N*ord)*1.234f;
        }


        // sort
        ticks = clock();    //Start timer

        SelectionSort(intValues);

        ticks = ticks - clock();    //Stop clock

        cout << endl << "This operation took " << ticks << " seconds" << endl;

        // Remove output, as we really dont need it for timing
        // // output
        // for (int i = 0; i < N*ord; i++)
        // {
        //     cout << intValues[i] << " ";

        // }
    }

    return 0;
}

/*
 * Sorts an array of int using the selection sort algorithm.
 * Performance is O(N^2)
 */
template <typename ValueType>
void SelectionSort(ValueType *values)
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
        ValueType temp = values[lh];
        values[lh] = values[rh];
        values[rh] = temp;
    }
}
