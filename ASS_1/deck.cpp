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
#include "cardvector.h"
#include "random.h"

using namespace std;

//FUNCTION DECLARATION

/*
    Initialises a new Deck object, filling (in order) 52 cards from a standard deck
 */
Deck::Deck()
{
    //Default Constructor. Empty deck
    deck = CardVector();
    cout << "DEBUG: Empty Deck created" << endl;
}

/*
    Some decks can be pre-confined to have a certain number of cards. This constructor allocates enough storage for exactly n cards.
 */
Deck::Deck(int n)
{
    deck = CardVector(n);
}

/*
    Creates a standard deck of 52 cards.
 */
void Deck::SetStandardDeck()
{

    //Iterating through the available cards, create the deck.
    for (int s = 0; s < SUITS; s++)
    {
        for (int r = 0; r < RANKS; r++)
        {

            Card c = Card((SUIT)s, (RANK)r);
            cout << "Creating card... " << c.getCardName() << endl;
            cout << "\t" << s << r << endl;
            deck.add(c);

        }
    }
}

/*
    De-constructs the deck, releasing resources
 */
Deck::~Deck() {}   //TO BE IMPLEMENTED

/*
    Performs a specified number of "swaps". Each iteration shuffles two cards.
    Usage:
        Shuffle(n)
 */
void Deck::Shuffle(int n)
{

    Card swap;      //Card to swap (from top to pos)
    int pos;        //Position (random int of size - 1)
    Random rand = Random();

    if (deck.size() <= 1)
    {
        return;   //If the deck is only one card, don't bother shuffling
    }

    //Using the random interface defined previously, grab the top card, and place it somewhere randomly in the stack.
    for (int i = 0; i < n; i++)
    {
        swap = Pop();
        pos = rand.RandomInteger(0, deck.size() - 1);
        deck.insert(pos, swap);
    }
}

/*
    Deals a cards from the top of the deck
    Usage:
        Card c = Deal();
 */
Card Deck::DealNextCard()
{
    return Pop();
}

/*
    Deal (int n)
    Deals n cards from the top of the deck
 */
//Card* DealNCards(int n);   TBI

/*
    Displays the remaining cards in the deck. prints to stdout
 */
void Deck::DisplayDeck()
{
    for (int i = 0; i < deck.size(); i++)
    {
        cout << deck.getCard(i).getCardName() << " ";
        if (i % 13 == 0)
        {
            cout << endl;   //Create a new line for each set of 13 cards displayed.
        }
    }
}


/*
    Swaps two elements int the stack. Used primarily for the "shuffle" method
 */
void Deck::Swap()
{

    //Unused method

}

/*
    Pops the top element in the stack
 */
Card Deck::Pop()
{

    //Check for an empty deck
    if (deck.isEmpty())
    {
        cerr << "Cannot pop empty stack" << endl;
        return Card();
    }
    else
    {
        //Get top card, and return it. Returned card will be popped off the top of the stack
        Card poppedCard = Peek();
        deck.remove(deck.size() - 1);
        return poppedCard;
    }
}

/*
    Takes a look at element n, and returns the object reference
 */
Card Deck::Peek()
{
    //Check for empty deck
    if (deck.isEmpty())
    {
        cerr << "Cannot peek at an empty deck" << endl;
        return Card();
    }
    else
    {
        return deck.getCard(deck.size() - 1);
    }
}

