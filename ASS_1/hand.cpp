/*  ===IMPLEMENTATION FILE===

    Deck (c) Daniel Park 2013

    A program which uses the OOP features of c++ to define a deck object. A deck is treated as a stack ADT, with shuffling

    v0.1
    ====
    -Initial creation

*/

#include <string>
#include <iostream>

#include "card.h"
#include "deck.h"
#include "random.h"

using namespace std;
const unsigned int STANDARD_DECK = 52;

//FUNCTION DECLARATION

/*
    Initialises a new Deck object, filling (in order) 52 cards from a standard deck
 */
Deck::Deck()
{
    deckContents = new Card* [STANDARD_DECK];   //Throw cards on the heap, enabling sizing at runtime
    for (int suit = 0; suit < SUITS; suit++)
    {
        for (int rank = 0; rank < RANKS; rank++)
        {
            //Reference to a new heaped card
            deckContents[suit * RANKS + rank] = new Card((SUIT)suit, (RANK)rank);
        }
    }

    cardsInDeck = STANDARD_DECK;
}


/*
    De-constructs the deck, releasing resources
 */
Deck::~Deck()
{
    for (int i = 0; i < STANDARD_DECK; i++)
    {
        delete deckContents[i]; //Remove referenced cards from the heap
    }
    delete[] deckContents;      //Remove card array pointer from the heap
}

/*
    Performs a specified number of "swaps". Each iteration shuffles two cards.
    Usage:
        Shuffle(n)
 */
void Deck::Shuffle(int n)
{
    unsigned int c1, c2;
    Random randGen;

    for (int i = 0; i < n; i++)
    {
        c1 = randGen.RandomInteger(0, STANDARD_DECK - 1);
        c2 = randGen.RandomInteger(0, STANDARD_DECK - 1);
        Swap(deckContents, c1, c2);
    }
}

/*
    Deals a cards from the top of the deck
    Usage:
        Card c = Deal();
 */
Card Deck::DealNextCard()
{
    return *deckContents[cardsInDeck--];
}

/*
    Deal (int n)
    Deals n cards from the top of the deck
 */
//Card* DealNCards(int n);   TBI

/*
    Displays the remaining cards in the deck. prints to stdout
 */
void Deck::DisplayHand()
{
    for (int i = 0; i < cardsInDeck; i++)
    {
        cout << deckContents[i]->getCardName() << " ";
    }
}


/*
    Swaps two elements int the stack. Used primarily for the "shuffle" method
 */
void Deck::Swaps(Card* cards[], unsigned int c1, unsigned int c2)
{
    Card* tmp = deckContents[c1];  //Allocate tempoary pointer for swap holding
    deckContents[c1] = deckContents[c2];
    deckContents[c2] = tmp;
}


