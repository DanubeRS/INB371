/*  ===HEADER FILE===

    Point (c) Daniel Park 2013

    A program which uses the OOP features of c++ to define a deck object. A deck is treated as a stack ADT, with shuffling

    v0.1
    ====
    -Initial creation

*/

#ifndef _deck_h_
#define _deck_h_

#include <string>
#include "card.h"
#include "cardvector.h"

using namespace std;

//FUNCTION DECLARATION
class Deck
{

public:
    /*
        Initialises a new Deck object, filling (in order) 52 cards from a standard deck
     */
    Deck();

    /*
        Some decks can be pre-confined to have a certain number of cards. This constructor allocates enough storage for exactly n cards.
     */
    Deck(int n);

    /*
        Deconstructs the deck, releasing resources
     */
    ~Deck();    //TO BE IMPLEMENTED
    
    /*
        Creates a standard deck of 52 cards.
     */
    void SetStandardDeck();

    /*
        Performs a specified number of "swaps". Each iteration shuffles two cards.
        Usage:
            Shuffle(n)
     */
    void Shuffle(int n);

    /*
        Deals a cards from the top of the deck
        Usage:
            Card c = Deal();
     */
    Card DealNextCard();

    /*
        Deal (int n)
        Deals n cards from the top of the deck
     */
    //Card* DealNCards(int n);   TBI

    /*
        Displays the remaining cards in the deck. prints to stdout
     */
    void DisplayDeck();

private:

    //INSTANCE VARIALBES
    CardVector deck;

    //PRIVATE INSTANCE METHODS
    /*
        Swaps two elements int the stack. Used primarily for the "shuffle" method
     */
    void Swap();

    /*
        Pops the top element in the stack
     */
    Card Pop();

    /*
        Takes a look at element n, and returns the object reference
     */
    Card Peek();

};

#endif