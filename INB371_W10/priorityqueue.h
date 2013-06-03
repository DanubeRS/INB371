#ifndef _priorityqueue_h
#define _priorityqueue_h

#include <vector>
#include <string>

using namespace std;

template <typename ElemType>
class PriorityQueue {
public:

    /* Constructor */
    PriorityQueue();

    /* Destructor */
    ~PriorityQueue();

    /* Adds an element to the Priority Queue and ensures that
     * minimum element (or maximum) is at the head of the queue */
    void Add(ElemType);

    /* Returns the head of the Priority Queue and
     * removes it from the Priority Queue */
    ElemType Poll();

    /* Returns a copy of the element at the head of the Priority Queue */
    ElemType Peek();

    /* Returns true if the Priority Queue is empty */
    bool IsEmpty();

    void Heapify(vector<ElemType>&);


private:
    vector<ElemType> heap;
    void Swap(int, int);
    void SiftUp();
    void SiftDown(int);
};


#endif // _priorityqueue_h
