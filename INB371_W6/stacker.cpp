/*
 * File: stacker.cpp
 * Uses generic implementaion of Stack ADT with ints and strings.
 */

#include <iostream>
#include "stack.h"

using namespace std;

int main() {

    Stack<int> intStack;
    Stack<string> stringStack;

    string words[] = {"a", "an", "pan", "pant", "paint", "taping", "plating", "pleating" };

    for (int i = 1; i < 10; i++) {
        intStack.push(i);
    }

    for (int i = 0; i < 8; i++) {
        stringStack.push(words[i]);
    }

    while (!intStack.isEmpty()) {
        cout << intStack.pop() << endl;;
    }

    while (!stringStack.isEmpty()) {
        cout << stringStack.pop() << endl;;
    }

    return 0;
}
