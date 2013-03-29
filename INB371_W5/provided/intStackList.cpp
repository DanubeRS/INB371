#include <iostream>

#include "intStackList.h"

using namespace std;

IntStack::IntStack() {
    list = NULL;
    count = 0;
}

IntStack::~IntStack(){
    clear();
}

int IntStack::size() {
    return count;
}

bool IntStack::isEmpty() {
    return count == 0;
}

void IntStack::push(int value) {
    Cell *cell = new Cell;
    cell->data = value;
    cell->link = list;
    list = cell;
    count++;
}

void IntStack::pop() {
    if (isEmpty()) {
        cerr << "Attempting to pop an empty stack" << endl;
    } else {
        Cell *cell = list;
        list = list->link;
        count--;
        delete cell;
    }
}

int IntStack::peek() {
    if (isEmpty()) {
        cerr << "Attempting to pop an empty stack" << endl;
    } else {
        return list->data;
    }
}

void IntStack::clear() {
    while (count > 0) {
        pop();
    }
}

