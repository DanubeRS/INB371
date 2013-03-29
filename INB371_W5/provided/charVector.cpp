#include <iostream>
#include "charVector.h"

using namespace std;


CharVector::CharVector() {
	elements = new char[INITIAL_CAPACITY];
	count = 0;
	capacity = INITIAL_CAPACITY;
}

CharVector::~CharVector() {
	delete[] elements;
}

int CharVector::size() {
	return count;
}

bool CharVector::isEmpty() {
	return count == 0;
}

char CharVector::get(unsigned int index) {
	char out;
	if (index >= count) {
		cerr << "Attempting to access an element beyond current size" << endl;	
	}
	
	// on error this will return garbage
	return elements[index];
}

void CharVector::set(unsigned int index, char value) {
	if (index >= count) {
		cerr << "Attempting to set an element beyond current size" << endl;	
	} else {
		elements[index] = value;
	}
}

void CharVector::add(char value) {
	if (count == capacity) {
		increaseCapacity();
	}
	elements[count++] = value;
}

void CharVector::insert(unsigned int index, char value) {
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

void CharVector::remove(unsigned int index) {
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

void CharVector::clear() {
	count = 0;
}

void CharVector::increaseCapacity() {
	
	// make bigger array
	char *newElements = new char[capacity * 2];
	
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

