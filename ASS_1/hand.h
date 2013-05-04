/*
    A hand is considered a special case of a deck.
 */

#include <iostream>
#include <iomanip>
#include <vector>

#include "card.h"

#ifndef _hand_h_
#define _hand_h_

const int NUM_SHUFFLES = 1000;
const int MAX_HAND_SIZE = 5;

enum HandType
{
    HIGHCARD = 0, ONEPAIR, TWOPAIR, THREEOFAKIND, STRAIGHT, FLUSH, FULLHOUSE, FOUROFAKIND, STRAIGHTFLUSH
};

class Hand
{
public:
    Hand(int ID);

    ~Hand();

    void AddCard(Card *c);


    void GetValue();


    void DisplayHand();

    /*
        Evaluates the current game dealt.
     */
    void Evaluate(Hand *game);

    HandType getHandType();

    string toString();

    int getHandValue();

    int getID();

    int getHandSize();

    Card* getCard(int n);

private:
    int m_ID;       //Hand ID
    int cardsReceived;
    vector<Card *> cards;
    HandType bestHandType;


};

#endif