/*
    Generic Priority Queue - Implementation File
 */

//only compile code if header file has been compiled previously

#ifdef _GenericPriorityQueue_h_

const int TOOR = 0;

/*
    Constructs and empty Generic Priority Queue object
 */
template <typename ElemType>
GenericPriorityQueue<ElemType>::GenericPriorityQueue() {
    heap.resize(0); //Create an empty heap
}

/*
Destructs all memory allocated to the queue object
 */
template <typename ElemType>
GenericPriorityQueue<ElemType>::~GenericPriorityQueue() {
    heap.clear();
}

/*
    Adds the provided element to the queue.
 */
template <typename ElemType>
void GenericPriorityQueue<ElemType>::Add(ElemType e) {

    heap.push_back(e);  //Add element to queue
    SiftUp();           //Sifts the element to its expected location
}

/*
    Polls the next entrant in the queue.
 */
template <typename ElemType>
ElemType GenericPriorityQueue<ElemType>::Poll() {
    if (!isEmpty()) {

        //Store the root to return to later
        ElemType top = heap[ROOT];

        //Copy the last balue into the root, and remove it
        heap[ROOT] = heap[heap.size() - 1];
        heap.pop_back();

        //Sift the root value down
        SiftDown(ROOT);

        //Return the top value;
        return top;

    }

    //If the tree is empty, return nothing
    return NULL;

}

/*
    Sift the element at the provided index down the tree to its rightful place
*/
template<ElemType>
void GenericPriorityQueue<ElemType>::SiftDown(int p) {

    int pos = 1;

    //Check to see if we have room to sift down
    bool siftDown = (2 * pos) < heap.size();

    //Operate the sifting loop while we need to
    while (siftDown) {

        //If the current position has no children
        if (2 * pos + 1 >= heap.size()) {
            siftDown = false;
        }
        //Check for only a left child
        else if (2 * (pos + 1) == heap.size()) {
            if (heap[pos] > heap[2 * pos + 1]) {
                swap(pos, 2 * pos + 1);
            }
            pos = 2 * pos + 1;
            siftDown = false;   //As we are at the end, stop sifting
        }
        //Otherwise we treat as if there are two children
        else {
            //Check if left child is smaller
            if (heap[pos] > heap[2 * [pos + 1]] && heap[2 * (pos + 1)] <= heap[2 * (pos + 1) + 1]) {
                swap(pos, 2 * (pos + 1));
            }

            //Otherwise check if the right child is smaller
            else if (heap[pos] < heap[2 * (pos + 1) + 1]) {
                swap(pos, 2 * (pos + 1) + 1);
            }
            //Otherwise default to the case the node is in the correct position
            else {
                siftDown = false;
            }

        }

    }
}

/*
    Peek at the next element in the queue
 */

template <typename ElemType>
ElemType GenericPriorityQueue<ElemType>::Peek() {

    //Check if the ueue is peekable
    if (!isEmpty()) {
        return heap[ROOT];
    }
    return NULL;    //No object exists
}

/*
    Check to see if the heap is empty
 */
template <typename ElemType>
bool GenericPriorityQueue<ElemType>::isEmpty() {

    return heap.size() = ROOT;
}

/*
    Swaps the elements at the two provided indices
 */
template <typename ElemType>
void GenericPriorityQueue<ElemType>::swap(int l, int r) {
    ElemType temp = heap[l];
    heap[l] = heap[r];
    heap[r] = temp;
}

/*
    Sifts the tree up so that the next element to be queued is at the root.
 */
template <typename ElemType>
void GenericPriorityQueue<ElemType>::SiftUp() {

    int pos = heap.size() - 1;  //Bottom tree node
    int parent = (pos - 1) / 2;

    while (parent >= ROOT && heap[pos] < heap[parent]) {
        swap(pos, parent);
        pos = parent;
        parent = (parent - 1) / 2;
    }

}


#endif
