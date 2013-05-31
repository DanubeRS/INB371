/*
 * File: stackimpl.cpp
 * -------------------
 * This file contains the linked-list implementation of the
 * Stack class.
 */
#ifdef _stack_h

template <typename ElemType>
Stack<ElemType>::Stack() {
    list = NULL;
    count = 0;

}

template <typename ElemType>
Stack<ElemType>::~Stack(){
    clear();
}

template <typename ElemType>
int Stack<ElemType>::size() {
    return count;
}

template <typename ElemType>
bool Stack<ElemType>::isEmpty() {
    return count == 0;
}

template <typename ElemType>
void Stack<ElemType>::push(ElemType value) {
    Cell *cell = new Cell;
//    cout << "pushing " << value << endl;
    cell->data = value;
    cell->link = list;
    list = cell;
    count++;
}

template <typename ElemType>
ElemType Stack<ElemType>::pop() {
    ElemType value;
    if (isEmpty()) {
  //      cerr << "Attempting to pop an empty stack" << endl;
    } else {
        value = list->data;
        Cell *cell = list;
        list = list->link;
        count--;
        delete cell;
    }
    return value;
}

template <typename ElemType>
ElemType Stack<ElemType>::peek() {
    if (isEmpty()) {
    //    cerr << "Attempting to peek an empty stack" << endl;
    } else {
        return list->data;
    }
}

template <typename ElemType>
void Stack<ElemType>::clear() {
    while (count > 0) {
        pop();
    }
}

#endif
