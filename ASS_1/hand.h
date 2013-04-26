/*  ===HEADER FILE===

    Hand (c) Daniel Park 2013

    A class which emulates the holding of a poker hand. A hand contains exactly 5 cards, 
    and contains an inbuilt hand evaluator

    v0.1
    ====
    -Initial creation

*/

#ifndef _hand_h_
#define _hand_h_

#include <string>
#include "card.h"

using namespace std;

//FUNCTION DECLARATION
class Deck
{

public:
    /*
        Initialises the object, creating an empty hand to be filled at a later point
     */
    Hand();

    /*
        Deconstructs the hand, releasing resources
     */
    ~Hand();    //TO BE IMPLEMENTED

    /*
        Accepts a card from the dealer. Returns false if the hand is full to indicate an internal dealing error
     */
    bool AcceptCard(Card c)

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
    void Swap(Card* cards[], unsigned int c1, unsigned int c2);
};

#endif