/*
    Custom implementation of the MergeSort algorithm for generic types. Uses STL vector.
    (c) Daniel Park 2013.

    Implemented via Pass-by-Reference for memory IOPS efficiency.
 */

#include <iostream>
#include <vector>

#include "random.h"

using namespace std;

//Function Decl.
void MergeSort(vector<int> &vec);
void Merge(vector<int> &vec, vector<int> &v1, vector<int> &v2);

//Const
const int VALUES_TO_GEN = 100;

//MAIN
int main(){
	cout << "MergeSort Generic" << endl;

	//This implementation works on a vector of random integers
	Random rand;
	vector<int> values;

	for (int i = 0; i < VALUES_TO_GEN; i++){
		values.push_back(rand.RandomInteger(0, 100));	//Randomly fill
		cout << values[i] << " ";
	}

	cout << endl;

	MergeSort(values);

	for (int i = 0; i < VALUES_TO_GEN; i++){
		cout << values[i] << " ";
	}

	cout << endl;
}

/*
	Generic MergeSort implementation
 */

void MergeSort(vector<int> &vec){

	//get size for halving calc
	int n = vec.size();

	//Declare our vector pair
	vector<int> v1;
	vector<int> v2;


	//Catch scalar, or empty vector
	if ( n <= 1){
		return;
	}

	for (int i = 0; i < n; i++){
		if (i < n/2){
			v1.push_back(vec[i]);
		} else {
			v2.push_back(vec[i]);
		}
	}

	//Now that our vector has been split, sort these sub-vectors
	MergeSort(v1);
	MergeSort(v2);

	
	//Clear the parent vector before merging. 
	//Information should not be lost as the vecot has been split and saved
	vec.clear();
	
	//Merge the vectors together (based on first-vaue comparison)
	Merge(vec, v1, v2);

	//Function ends and returns to parent caller
}

/*
	Merge function. Should only be called within MergeSort
 */
void Merge(vector<int> &vec, vector<int> &v1, vector<int> &v2){

	//extract vector lengths
	int n1 = v1.size();
	int n2 = v2.size();

	//Declare indexes for iteration
	int p1 = 0;
	int p2 = 0;

	//Iterate through the vectors, pulling the largest value at the front out.
	while (p1 < n1 && p2 < n2){
		if (v1[p1] < v2[p2]){
			vec.push_back(v1[p1++]);
		} else {
			vec.push_back(v2[p2++]);
		}
	}

	//as loop exists when one of the vectors is fully exhausted, we must catch the rest of the non-empty
	//vector and add it to the end
	while (p1 < n1){vec.push_back(v1[p1++]);}
	while (p2 < n2){vec.push_back(v2[p2++]);}

}