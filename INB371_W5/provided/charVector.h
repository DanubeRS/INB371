/*
 * intVector.h
 * This interface defines an IntVector class to demonstrate how a vector works.
 */

#ifndef _charvector_h
#define _charvector_h

class CharVector {

public:
	/*
	 * Constrcutor: CharVector
	 * Usage: CharVector charVector
	 * Initialises a new empty vector that can contain chars
	 */
	CharVector();

	/*
	 * Destructor: ~CharVector
	 * Usage: (usually implicit)
	 * Deallocates storage associated with this vector.
	 */
	~CharVector();

	/*
	 * Method: size
	 * Usage: nElems = charVector.size()
	 * Returns the number of elements in the vector.
	 */
	int size();

	/*
	 * Method: isEmpty
	 * Usage: status = charVector.isEmpty()
	 * Returns true if the vector is empty.
	 */
	bool isEmpty();

	/*
	 * Method: get
	 * Usage: value = charVector.get(index)
	 * Returns the element at index in the vector.
	 */
	char get(unsigned int index);

	/*
	 * Method: set
	 * Usage: charVector.set(index, value)
	 * Sets the contents of the element at index to value.
	 */
	void set(unsigned int index, char value);

	/*
	 * Method: add
	 * Usage: charVector.add(value)
	 * Adds a new element with value to the vector.
	 */
	void add(char value);

	/*
	 * Method: insert
	 * Usage: charVector.insert(index, value)
	 * Inserts an element with value at index in the vector.
	 */
	void insert(unsigned int index, char value);

	/*
	 * Method: remove
	 * Usage: charVector.remove(index)
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

	char *elements;
	unsigned int capacity;
	unsigned int count;

	/*
	 * Increases capacity of vector when it fills up.
	 */
	void increaseCapacity();
};

#endif
