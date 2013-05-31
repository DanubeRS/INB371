/*
* File: stack.h
* -------------
* This interface defines a general stack abstraction that uses
* templates so that it can work with any element type.
*/

#ifndef _stack_h
#define _stack_h

/*
 * Template class: Stack<ElemType>
 * -------------------------------
 * This class template models a stack, which is a linear collection
 * of values stacked one on top of the other. Values are added and
 * removed only from the top of the stack. The fundamental stack
 * operations are push (add to top) and pop (remove from top).
 * Because values are added and removed from the same end of the
 * stack, the last value pushed on a stack is the first value that
 * is popped. Stacks therefore operate in a last-in-first-out (LIFO)
 * order. For maximum generality, the Stack class is defined using
 * a template that allows the client to define a stack that contains
 * any type of value, as in Stack<string> or Stack<stateT>.
 */
template<typename ElemType>
class Stack {
public:

  /*
   * Constructor: Stack
   * Usage: Stack<int> stack;
   * ------------------------
   * The constructor initializes a new empty stack containing
   * the specified value type.
   */
   Stack<ElemType>();


  /*
   * Destructor: ~Stack
   * Usage: (usually implicit)
   * -------------------------
   * The destructor deallocates any heap storage associated
   * with this stack.
   */
   ~Stack<ElemType>();

  /*
   * Method: size
   * Usage: nElems = stack.size();
   * -----------------------------
   * Returns the number of elements in this stack.
   */
   int size();

  /*
   * Method: isEmpty
   * Usage: if (stack.isEmpty()) . . .
   * ---------------------------------
   * Returns true if this stack contains no elements, and false
   * otherwise.
   */
   bool isEmpty();

  /*
   * Method: clear
   * Usage: stack.clear();
   * ---------------------
   * This method removes all elements from this stack.
   */
   void clear();

  /*
   * Method: push
   * Usage: stack.push(elem);
   * ------------------------
   * Pushes the specified element onto this stack.
   */
   void push(ElemType elem);

  /*
   * Method: pop
   * Usage: topElem = stack.pop();
   * -----------------------------
   * Removes the top element from this stack and returns it.
   * Raises an error if called on an empty stack.
   */
   ElemType pop();

  /*
   * Method: peek
   * Usage: topElem = stack.peek();
   * ------------------------------
   * Returns the value of top element from this stack without
   * removing it. Raises an error if called on an empty stack.
   */
   ElemType peek();




private:

#include "stackpriv.h"

};

#include "stackimpl.cpp"

#endif

