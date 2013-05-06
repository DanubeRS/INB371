#include <iostream>
#include <vector>

#include "random.h"

using namespace std;

void Quicksort(vector<int> &vec, int left, int right);

const int NUM_VALUES = 100;

int main() {

    Random rand;
	vector<int> values;
	for (int i = 0; i < NUM_VALUES; i++) {
		values.push_back(rand.GetRandomInteger(0, 100));
		cout << values[i] << " ";
	}
	cout << endl;

	Sort(values);
	//Quicksort(values, 0, values.size() - 1);

	for (int i = 0; i < NUM_VALUES; i++) {
		cout << values[i] << " ";
	}
	cout << endl;
}

void Quicksort(vector<int> &vec, int left, int right) {
	int i = left, j = right;
	int tmp;
	int pivot = vec[(left + right)/2];

	while (i <= j) {
		while (vec[i] < pivot) i++;
		while (vec[j] > pivot) j--;
		if (i <= j) {
			tmp = vec[i];
			vec[i] = vec[j];
			vec[j] = tmp;
			i++;
			j--;
		}
	}

	if (left < j) Quicksort(vec, left, j);
	if (i < right) Quicksort(vec, i, right);

}
