/*  ===HEADER FILE===

    Point (c) Daniel Park 2013

    A program which uses the OOP features of c++ to define a dynamic card vector object.

    v0.1
    ====
    -Initial creation

*/

#ifndef _cardvector_h_
#define _cardvector_h_

#include "card.h"

class CardVector
{
public:
    /*
        Creates an empty CardVector object
     */
    CardVector();

    /*
        Deconstructs the CardVector object
     */
    ~CardVector();

    /*
        returns the size of the CardVector (i.e: cards in the hand, deck, etc...)
     */
    int size();

    /*
        returns true if the current Cardvector is empty
     */
    bool isEmpty();

    /*
        Returns the card object at position n. Performs bound checking for safety.
     */

    Card getCard(unsigned int ind);

    /*
        Places (or replaces) a card at the specified index with the argumented card
        Usage:
            cv.set(newC)

     */
    void set(Card newC);

    /*
        Adds a new card to the top of the stack. Will dynamically expand the vector if capacity has been reached
     */
    void add(Card c);

    /*
        Inserts a card at the provided position. Useful for shuffling applications when combined with a "pop()" method.
        Usage:
            cv.insert(10, card);
     */
    void insert (unsigned int ind, Card c);

    /*
		Removes the card at the specified index
		Usage:
			cv.remove(10);
     */
    void remove(unsigned int ind);

    /*
    	Clears the velctor of all card objects.
     */
    void clear();
private:
	
	static const int INITIAL_CAPACITY = 10;

	Card *elements;			//Location of CV array
	unsigned int count;		//Count of cards in the CV
	unsigned int capacity;	//The number of cards that the CV can currently hold without expansion

	/*
		Increases the capacity of the CV. Performs an array copy, and re-reference
	 */
	
	void increaseCapacity();

}




