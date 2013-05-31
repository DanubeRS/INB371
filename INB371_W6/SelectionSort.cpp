/*
 * File:  SelectionSort.cpp
 * Provides an implementation and usage of SelectionSort algorithm.
 */

#include <iostream>
#include "random.h"

using namespace std;

const int N = 100;

/*
 * Sorts an array of int using the selection sort algorithm.
 * Performance is O(N^2)
 */
template<typename ValueType>
void SelectionSort(ValueType *);

int main() {

	// fill an array with random integers
	int intValues[N];
	float floatValues[N];

	//Init the random number generator captian!
	Random random;

	for (int i = 0; i < N; i++) {
		intValues[i] = random.RandomInteger(0, N);
	}

	for (int i = 0; i < N; i++) {
		floatValues[i] = random.RandomInteger(0, N)* 0.123f * random.RandomInteger(0, 10);
	}



	// sort
	SelectionSort(intValues);
	SelectionSort(floatValues);

	// output
	for (int i = 0; i < N; i++) {
		cout << intValues[i] << " ";
	}

	for (int i = 0; i < N; i++) {
		cout << floatValues[i] << " ";
	}
	cout << endl;

	return 0;
}

/*
 * Sorts an array of int using the selection sort algorithm.
 * Performance is O(N^2)
 */
template <typename ValueType>
void SelectionSort(ValueType *values) {

	// for each position in the array
	for (int lh = 0; lh < N; lh++) {

		// find the smallest value in the unsorted portion of the array
		int rh = lh;
		
		for (int i = lh + 1; i < N; i++) {
			if (values[i] < values[rh]) 
				rh = i;
		}

		// swap the values
		ValueType temp = values[lh];
		values[lh] = values[rh];
		values[rh] = temp;
	}
}
