/*
    Implementation and analysis of simple binary search algorithm.
 */

#include <iostream>
#include "random.h"
#include <vector>

using namespace std;

const int N = 10;

//Prototype for BinarySearch
int BinarySearch(vector<int> v, int key);

int main()
{

    vector<int> intVector;

    Random r;

    for (int i = 1; i < N*10; i++)
    {
    	intVector.push_back(r.RandomInteger(0, N));
    }

    int pos;
    int key = N;
    pos = BinarySearch(intVector, key);

    //Return results
    cout << "Key " << key << " is at position " << pos << endl;



}

int BinarySearch(vector<int> v, int key){
	int first = 1, last = v.size();

	while (first <= last){
		int mid = (first + last) / 2;

		if (key == v[mid]){
			return mid;
		}
		else if (key < v[mid]){
			last = mid-1;
		}
		else if (key > v[mid]){
			first = mid + 1;
		}
	}

	//Failed search
	return -1;
	
}