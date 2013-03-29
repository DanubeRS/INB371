/*
 * CharStack.cpp
 * Implements CharStack class using IntVector.
 */
#include <iostream>
#include "charStack.h"

using namespace std;
 
CharStack::CharStack() {
    // nothing to do
}

CharStack::~CharStack(){
    // nothing to do
}

int CharStack::size() {
    return stack.size();
}

bool CharStack::isEmpty() {
    return stack.isEmpty();
}

void CharStack::push(char value) {
    stack.add(value);
}

void CharStack::pop() {
    if (stack.isEmpty()) {
        cerr << "Cannot pop from empty stack" << endl;
    } else {
        stack.remove(stack.size() - 1);
    }
}

char CharStack::peek() {
    if (stack.isEmpty()) {
        cerr << "Cannot pop from empty stack" << endl;
        return '0';
    } else {
 	    return stack.get(stack.size() - 1);
    }
}

void CharStack::clear() {
    stack.clear();
}

