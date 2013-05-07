#include <iostream>
#include <vector>

#include "random.h"

using namespace std;

void MergeSort(vector<int> &vec);
void Merge(vector<int> &vec, vector<int> &v1, vector<int> &v2);

const int NUM_VALUES = 100;

int main() {

    Random rand;
	vector<int> values;
	for (int i = 0; i < NUM_VALUES; i++) {
		values.push_back(rand.RandomInteger(0, 100));
		cout << values[i] << " ";
	}
	cout << endl;

	MergeSort(values);
	//Quicksort(values, 0, values.size() - 1);

	for (int i = 0; i < NUM_VALUES; i++) {
		cout << values[i] << " ";
	}
	cout << endl;
}

void MergeSort(vector<int> &vec) {
	int n = vec.size();
	if (n <= 1)
		return;
	vector<int> v1;
	vector<int> v2;
	for (int i = 0; i < n; i++) {
		if (i < n/2) {
			v1.push_back(vec[i]);
		} else {
			v2.push_back(vec[i]);
		}
	}
	MergeSort(v1);
	MergeSort(v2);
	vec.clear();
	Merge(vec, v1, v2);
}

void Merge(vector<int> &vec, vector<int> &v1, vector<int> &v2) {
	int n1 = v1.size();
	int n2 = v2.size();
	int p1 = 0;
	int p2 = 0;
	while (p1 < n1 && p2 < n2) {
		if (v1[p1] < v2[p2]) {
			vec.push_back(v1[p1++]);
		} else {
			vec.push_back(v2[p2++]);
		}
	}
	while (p1 < n1) vec.push_back(v1[p1++]);
	while (p2 < n2) vec.push_back(v2[p2++]);
}
