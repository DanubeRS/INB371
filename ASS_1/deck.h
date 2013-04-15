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
        Deconstructs the deck, releasing resources
     */
    ~Deck();    //TO BE IMPLEMENTED

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
    Card** deckContents;    //Pointer to card array. Array containts pointers to enable easy shuffling
    int cardsInDeck;        //Remaining cards in the deck (52 if full)

    //PRIVATE INSTANCE METHODS
    /*
        Swaps two elements int the stack. Used primarily for the "shuffle" method
     */
    void Swap();
};

#endif