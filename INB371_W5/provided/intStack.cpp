/*
 * intStack.cpp
 * Implements IntStack class using IntVector.
 */
#include <iostream>
#include "intStack.h"

using namespace std;
 
IntStack::IntStack() {
    // nothing to do
}

IntStack::~IntStack(){
    // nothing to do
}

int IntStack::size() {
    return stack.size();
}

bool IntStack::isEmpty() {
    return stack.isEmpty();
}

void IntStack::push(int value) {
    stack.add(value);
}

void IntStack::pop() {
    if (stack.isEmpty()) {
        cerr << "Cannot pop from empty stack" << endl;
    } else {
        stack.remove(stack.size() - 1);
    }
}

int IntStack::peek() {
    if (stack.isEmpty()) {
        cerr << "Cannot pop from empty stack" << endl;
        return 0;
    } else {
 	    return stack.get(stack.size() - 1);
    }
}

void IntStack::clear() {
    stack.clear();
}

