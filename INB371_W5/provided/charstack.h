/*
 * CharStack.h
 * This interface defines an CharStack class to demonstrate how a stack works.
 */
 
#ifndef _charstack_h
#define _charstack_h

#include "charVector.h"

class CharStack {

public:
	/* 
	 * Constrcutor: CharStack         
	 * Usage: CharStack       
	 * Initialises a new empty vector that can contain ints
	 */
	CharStack();

	/* 
	 * Destructor: ~CharStack
	 * Usage: (usually implicit)
	 * Deallocates storage associated with this stack.
	 */
	~CharStack();
	
	/* 
	 * Method: size
	 * Usage: nElems = stack.size()
	 * Returns the number of elements in the stack.
	 */
	int size();

	/* 
	 * Method: isEmpty
	 * Usage: status = stack.isEmpty()
	 * Returns true if the stack is empty.
	 */
	bool isEmpty();
	
	/* 
	 * Method: push
	 * Usage: stack.push(value)
	 * Adds the value to the top of the stack.
	 */
	void push(char value);
	
	/* 
	 * Method: pop
	 * Usage: stack.pop()
	 * Removes the element on top of the stack.
	 */
	void pop();

	/* 
	 * Method: peek
	 * Usage: value = stack.peek()
	 * Gets a copy of the top of the stack.
	 */
	char peek();
	
	/* 
	 * Method: clear
	 * Usage: stack.clear()
	 * Removes all elements from the stack.
	 */
	void clear();

private:
    
    CharVector stack;
    
    /* Number of elements in list */
    int count;
	
};
 
#endif
