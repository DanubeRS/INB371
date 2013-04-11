/*
    cardvector (c) Daniel Park 2013

    A program which uses the OOP features of c++ to define a point object

    v0.1
    ====
    -Initial creation

*/


#include "cardvector.h"
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <sstream>
#include <string>
#include <iostream>

using namespace std;

/*
    Creates an empty CardVector object
 */
CardVector::CardVector()
{

    //Default Constructor
    m_elements = new Card[DEFAULT_INITIAL_CAPACITY];
    cout << "Creating CardVector " << endl;
    count = 0;
    capacity = DEFAULT_INITIAL_CAPACITY;
}

/*
    Creates a CardVector object with n spaces
 */
CardVector::CardVector(int n)
{

    //Predefined storage CardVector
    m_elements[n];
    count = 0; capacity = n;    //Set capacity to the argued int.
}

/*
    Deconstructs the CardVector object
 */
CardVector::~CardVector()
{
    delete[] m_elements;
}

/*
    returns the size of the CardVector (i.e: cards in the hand, deck, etc...)
 */
int CardVector::size()
{
    return count;
}

/*
    returns true if the current Cardvector is empty
 */
bool CardVector::isEmpty()
{
    return (count == 0);
}

/*
    Returns the card object at position n. Performs bound checking for safety.
 */

Card CardVector::getCard(unsigned int ind)
{
    if (ind > size())
    {
        cerr << "Attempted to acces a non-existent card." << endl;
        return Card();
    }
    else
    {

        return m_elements[ind];
    }
}

/*
    Places (or replaces) a card at the specified index with the argumented card
    Usage:
        cv.set(newC)

 */
void CardVector::set(unsigned int ind, Card newC)
{

    //Bound checking
    if (ind > size())
    {
        cerr << "Attempted to acces a non-existent card." << endl;
        return;
    }
    else
    {
        m_elements[ind] = newC;
    }
}

/*
    Adds a new card to the top of the stack. Will dynamically expand the vector if capacity has been reached
 */
void CardVector::add(Card c)
{
    if (count == capacity)
    {
        cout << "Increasing capacity..." << endl;
        cout << "Count: " << count << endl;
        increaseCapacity(DEFAULT_GROWTH_SIZE);
    }
    m_elements[count] = c;
    cout << "Added " << m_elements[count].getCardName() << endl;
    cout << "Count increased from " << count << " to " << count + 1;
    count++;

}

/*
    Inserts a card at the provided position. Useful for shuffling applications when combined with a "pop()" method.
    Usage:
        cv.insert(10, card);
 */
void CardVector::insert(unsigned int ind, Card c) {}

/*
    Removes the card at the specified index
    Usage:
        cv.remove(10);
 */
void CardVector::remove(unsigned int ind) {}

/*
    Clears the velctor of all card objects.
 */
void CardVector::clear() {}

/*
    Increases the capacity of the CV by n. Performs an array copy, and re-reference
 */
void CardVector::increaseCapacity(int n)
{

    //Add n to the current amount of card capacity
    int newCapacity = count + n;
    cout << newCapacity << endl;
    capacity = newCapacity;
    Card *newElements = new Card[newCapacity];

    //Place all cards in the new collection
    for (unsigned int i = 0; i < count; i++)
    {
        cout << "assigned [" << i << "] "<< m_elements[i].getCardName();
        cout << " to " << newElements[i].getCardName();
        newElements[i] = m_elements[i];
        cout << " ==> " << newElements[i].getCardName() << endl;;

    }


    delete[] m_elements;
    m_elements = newElements;
}


