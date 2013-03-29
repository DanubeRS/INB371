/*
 * intStackList.h
 * This interface defines an IntStack class to demonstrate how a stack works.
 */
 
#ifndef _intstacklist_h
#define _intstacklist_h

class IntStack {

public:
	/* 
	 * Constrcutor: IntStack         
	 * Usage: IntStack       
	 * Initialises a new empty vector that can contain ints
	 */
	IntStack();

	/* 
	 * Destructor: ~IntStack
	 * Usage: (usually implicit)
	 * Deallocates storage associated with this stack.
	 */
	~IntStack();
	
	/* 
	 * Method: size
	 * Usage: nElems = intStack.size()
	 * Returns the number of elements in the stack.
	 */
	int size();

	/* 
	 * Method: isEmpty
	 * Usage: status = intStack.isEmpty()
	 * Returns true if the stack is empty.
	 */
	bool isEmpty();
	
	/* 
	 * Method: push
	 * Usage: intStack.push(value)
	 * Returns the element at index in the vector.
	 */
	void push(int value);
	
	/* 
	 * Method: pop
	 * Usage: intStack.pop()
	 * Removes the element on top of the stack.
	 */
	void pop();

	/* 
	 * Method: peek
	 * Usage: value = intStack.peek()
	 * Gets a copy of the top of the stack.
	 */
	int peek();
	
	/* 
	 * Method: clear
	 * Usage: intStack.clear()
	 * Removes all elements from the stack.
	 */
	void clear();

private:
    
    /* Type definition for linked list cells */
    struct Cell {
        int data;
        Cell *link;
    };
    
    /* Beginning of list of elements */
    Cell *list;
    
    /* Number of elements in list */
    int count;
	
};
 
 
#endif
