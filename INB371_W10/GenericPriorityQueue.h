/*
    Generic Priority Queue - Header
 */

#include <vector>

#ifndef _GenericPriorityQueue_h_
#define _GenericPriorityQueue_h_


using namespace std;

template <typename ElemType>
class GenericPriorityQueue {

public:
    //Constructor
    GenericPriorityQueue();

    //Destructor
    ~GenericPriorityQueue();

    //Add delement to heap
    void Add(ElemType e);

    //Polls the top queue item for processing
    ElemType Poll();

    //Peeks at what element will come next if Poll() called.
    ElemType Peek();

    //Checks if the queue is empty
    bool isEmpty();

    // Heapifies the provided vector, such that "higher" values are boiled to the top, and lower values are reduced to the bottom
    // This method is implemented by a pass-by-address method, meaning the vector is changed in place, and not copied first.
    void Heapify(vector<ElemType> &);

private:

    //this heap variable forms the underlying data structure to the object
    vector<ElemType> heap;

    //Private utility methods used in the public methods

    //Swaps the elements in the provided indices
    void swap(int l, int r);

    // Sifts the tree up in order
    void SiftUp();

    //Sifts the element at the provided index down
    void SiftDown(int);
};

//Include implementation file
#include "GenericPriorityQueue.cpp"

#endif