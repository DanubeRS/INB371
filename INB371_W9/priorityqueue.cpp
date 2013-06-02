//#include <iostream>
#include "priorityqueue.h"

const int UNUSED = -999;
const int ROOT = 1;

PriorityQueue::PriorityQueue() {
    heap.resize(1);
    heap[0] = UNUSED;
}

PriorityQueue::~PriorityQueue() {
    heap.clear();
}

void PriorityQueue::SiftUp() {
    int pos = heap.size() - 1;
    int parent = pos / 2;
    while (parent >= ROOT && heap[pos] < heap[parent]) {
        Swap(pos, parent);
        pos = parent;
        parent = parent/2;
    }
}

void PriorityQueue::Add(ElemType elem) {
    heap.push_back(elem);
    SiftUp();
}

void PriorityQueue::SiftDown(int pos) {

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

ElemType PriorityQueue::Poll() {
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

ElemType PriorityQueue::Peek() {
    if (!IsEmpty()) {
        return heap[ROOT];
    }
    return NULL;
}

bool PriorityQueue::IsEmpty() {
    return heap.size() == 1;
}

void PriorityQueue::Swap(int i, int j) {
    ElemType temp = heap[j];
    heap[j] = heap[i];
    heap[i] = temp;
}

//void PriorityQueue::Display() {
//    for (int i = 1; i < heap.size(); i++) {
//        cout << heap[i] << " ";
//    }
//    cout << endl;
//}
