/*
 * File: stackpriv.h
 * -----------------
 * This file contains the private section of the Stack template
 * class. Including this information in a separate file means
 * that clients don't need to look at these details.
 */

/*
 * Implementation notes: Stack data structure
 * ------------------------------------------
 * The elements of the stack are stored in a linked list of
 * the specified element type.
 */


/* Type definition for linked list cells */
struct Cell {
    ElemType data;
    Cell *link;
};

/* Beginning of list of elements */
Cell *list;

/* Number of elements in list */
int count;

/* Private method prototypes */

