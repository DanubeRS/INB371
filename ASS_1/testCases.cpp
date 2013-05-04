/*

    Test cases for various functionality elements.

 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

#include "deck.h"
#include "card.h"
#include "CardComparer.h"
#include "HandComparer.h"
#include "hand.h"


using namespace std;

int main(int argc, char *argv[])
{

    /////////////////////////////////////////////
    //  TEST 1 - CARD COMPARISON FOR SORTING   //
    /////////////////////////////////////////////

    cout << "Testing functionality" << endl;

    vector<Card *> test1;

    test1.push_back(new Card(FOUR, SPADES));
    test1.push_back(new Card(FOUR, CLUBS));
    test1.push_back(new Card(SEVEN, CLUBS));
    test1.push_back(new Card(KING, CLUBS));

    sort(test1.begin(), test1.end(), CardComparer());

    cout << "Returning cards in order..." << endl;
    int startSize = test1.size();
    for (int i = 0; i < startSize; i++)
    {
        cout << test1.back()->GetCardName() << endl;
        test1.pop_back();
    }


    /////////////////////////////////////////////
    //  TEST 2 - CREATING AND DEALING A DECK   //
    /////////////////////////////////////////////

    Deck deck;

    cout << " A new deck is being created... " << endl;
    deck.DisplayDeck();

    //Shuffle and Display...
    cout << " Deck is being shuffled... " << endl;
    deck.Shuffle();
    deck.DisplayDeck();

    // Create a new game with 5 players.
    cout << " Creating a game with 5 players..." << endl;

    vector<Hand *> players;
    int numPlayers = 5;

    for ( int p = 0; p < numPlayers; p++)
    {
        cout << " Creating player " << p + 1 << endl;
        players.push_back(new Hand(p + 1));
    }

    for (int i = 0; i < 5; i++)
    {
        for ( int p = 0; p < numPlayers; p++)
        {
            players.at(p)->AddCard(deck.DealNextCard());
        }
    }

    for ( int p = 0; p < numPlayers; p++)
    {
        players.at(p)->DisplayHand();
    }


    /////////////////////////////////////////////
    //  TEST 3 - EVALUATING A HANDS VALUE      //
    /////////////////////////////////////////////


    sort(players.begin(), players.end(), HandComparer());

    for (int p = 0; p < players.size(); p++)
    {
        cout << "Player " << players.at(p)->getID() << " has " << players.at(p)->toString() << " with score " << players.at(p)->getHandValue() << endl;
    }
}


