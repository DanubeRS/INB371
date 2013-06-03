//#include <iostream>
#include "priorityqueue.h"

const int UNUSED = -999;
const int ROOT = 0;

template <typename ElemType>
PriorityQueue<ElemType>::PriorityQueue() {
    heap.resize(1);
    heap[0] = UNUSED;
}

template <typename ElemType>
PriorityQueue<ElemType>::~PriorityQueue() {
    heap.clear();
}

template <typename ElemType>
void PriorityQueue<ElemType>::SiftUp() {
    int pos = heap.size() - 1;
    int parent = pos / 2;
    while (parent >= ROOT && heap[pos] < heap[parent]) {
        Swap(pos, parent);
        pos = parent;
        parent = parent/2;
    }
}

template <typename ElemType>
void PriorityQueue<ElemType>::Add(ElemType elem) {
    heap.push_back(elem);
    SiftUp();
}

template <typename ElemType>
void PriorityQueue<ElemType>::SiftDown(int pos) {

    // start to sift down
    bool siftDown = 2 * pos < heap.size();

    while (siftDown) {

        // Case 1:  No children - STOP
        if (2 * pos >= heap.size()) {
            siftDown = false;

            // Case 2:  Only a left child
        } else if (2 * pos >= heap.size()) {
            if (heap[pos] > heap[2 * pos]) {
                Swap(pos, 2 * pos);
            }
            pos = 2 * pos;
            siftDown = false;

            // Case 3:  two children
        } else {

            // left child is smaller
            if (heap[pos] > heap[2 * pos] && heap[2 * pos] <= heap[2 * pos + 1]) {
                Swap(pos, 2 * pos);
                pos = 2 * pos;

                // right child is smaller
            } else if (heap[pos] > heap[2 * pos + 1]) {
                Swap(pos, 2 * pos + 1);
                pos = 2 * pos + 1;

                // both children are bigger
            } else {
                siftDown = false;
            }
        }
    }
}

template <typename ElemType>
ElemType PriorityQueue<ElemType>::Poll() {
    if (!IsEmpty()) {

        // store the root value
        ElemType top = heap[ROOT];

        // copy last value into root and delete last element
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();
        SiftDown(ROOT);
        return top;
    }
    return NULL;
}

template <typename ElemType>
ElemType PriorityQueue<ElemType>::Peek() {
    if (!IsEmpty()) {
        return heap[ROOT];
    }
    return NULL;
}

template <typename ElemType>
bool PriorityQueue<ElemType>::IsEmpty() {
    return heap.size() == 1;
}

template <typename ElemType>
void PriorityQueue<ElemType>::Swap(int i, int j) {
    ElemType temp = heap[j];
    heap[j] = heap[i];
    heap[i] = temp;
}

//void PriorityQueue<ElemType>::Display() {
//    for (int i = 1; i < heap.size(); i++) {
//        cout << heap[i] << " ";
//    }
//    cout << endl;
//}
