/*
 * intVector.h
 * This interface defines an IntVector class to demonstrate how a vector works.
 */

#ifndef _intvector_h
#define _intvector_h

class IntVector {

public:
	/*
	 * Constrcutor: IntVector
	 * Usage: IntVector intVector
	 * Initialises a new empty vector that can contain ints
	 */
	IntVector();

	/*
	 * Destructor: ~IntVector
	 * Usage: (usually implicit)
	 * Deallocates storage associated with this vector.
	 */
	~IntVector();

	/*
	 * Method: size
	 * Usage: nElems = intVector.size()
	 * Returns the number of elements in the vector.
	 */
	int size();

	/*
	 * Method: isEmpty
	 * Usage: status = intVector.isEmpty()
	 * Returns true if the vector is empty.
	 */
	bool isEmpty();

	/*
	 * Method: get
	 * Usage: value = intVector.get(index)
	 * Returns the element at index in the vector.
	 */
	int get(unsigned int index);

	/*
	 * Method: set
	 * Usage: intVector.set(index, value)
	 * Sets the contents of the element at index to value.
	 */
	void set(unsigned int index, int value);

	/*
	 * Method: add
	 * Usage: intVector.add(value)
	 * Adds a new element with value to the vector.
	 */
	void add(int value);

	/*
	 * Method: insert
	 * Usage: intVector.insert(index, value)
	 * Inserts an element with value at index in the vector.
	 */
	void insert(unsigned int index, int value);

	/*
	 * Method: remove
	 * Usage: intVector.remove(index)
	 * Removes the element at index from the vector.
	 */
	void remove(unsigned int index);

	/*
	 * Method: clear
	 * Usage: intVector.clear()
	 * Removes all elements from the vector.
	 */
	void clear();

private:
	static const int INITIAL_CAPACITY = 10;

	int *elements;
	unsigned int capacity;
	unsigned int count;

	/*
	 * Increases capacity of vector when it fills up.
	 */
	void increaseCapacity();
};

#endif
