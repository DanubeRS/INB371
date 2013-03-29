#include <iostream>
#include "intVector.h"

using namespace std;


IntVector::IntVector() {
	elements = new int[INITIAL_CAPACITY];
	count = 0;
	capacity = INITIAL_CAPACITY;
}

IntVector::~IntVector() {
	delete[] elements;
}

int IntVector::size() {
	return count;
}

bool IntVector::isEmpty() {
	return count == 0;
}

int IntVector::get(unsigned int index) {
	if (index >= count) {
		cerr << "Attempting to access an element beyond current size" << endl;	
	}
	
	// on error this will return garbage
	return elements[index];
}

void IntVector::set(unsigned int index, int value) {
	if (index >= count) {
		cerr << "Attempting to set an element beyond current size" << endl;	
	} else {
		elements[index] = value;
	}
}

void IntVector::add(int value) {
	if (count == capacity) {
		increaseCapacity();
	}
	elements[count++] = value;
}

void IntVector::insert(unsigned int index, int value) {
	if (count == capacity) {
		increaseCapacity();
	}
	
	// shuffle elements up
	for (unsigned int i = count; i > index; i--) {
		elements[i] = elements[i - 1];
	}
	elements[index] = value;
	count++;
}

void IntVector::remove(unsigned int index) {
	if (index >= count) {
		cerr << "Attempting to remove an element beyond current size" << endl;	
	} else {
		
		// shuffle elements down
		for (unsigned int i = index + 1; i <= count; i++) {
			elements[i - 1] = elements[i];
		}
		count--;
	}
}

void IntVector::clear() {
	count = 0;
}

void IntVector::increaseCapacity() {
	
	// make bigger array
	int *newElements = new int[capacity * 2];
	
	// copy existing elements to new array
	for (unsigned int i = 0; i < count; i++) {
		newElements[i] = elements[i];
	}
	
	// clean up
	delete[] elements;
	
	//reassign
	elements = newElements;
	capacity *= 2;
}

