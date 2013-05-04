#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

#include "deck.h"
#include "card.h"
#include "hand.h"
#include "HandComparer.h"

using namespace std;

const int PLAYERS = 10;
const int CARDS_PER_PLAYER = 5;

int main(int argc, char *argv[])
{

    // Declare Deck and vector of pointer to Hand
    Deck deck;

    cout << " A new deck is being created... " << endl;
    //deck.DisplayDeck();

    // Create a new game with 5 players.
    cout << " Creating a game with 5 players..." << endl;

    vector<Hand *> players;
    int numPlayers = 5;

    for ( int p = 0; p < numPlayers; p++)
    {
        //cout << " Creating player " << p + 1 << endl;
        players.push_back(new Hand(p + 1));
    }
    // allow for testing from file
    if (argc == 2)
    {

        // open the file and check it exists
        ifstream infile;
        infile.open(argv[1]);
        if (infile.fail())
        {
            cerr <<  "Error: Could not find file" << endl;
            return 1;
        }

        // read the cards into the hands
        int rank, suit;
        for (int card = 0; card < CARDS_PER_PLAYER; card++)
        {
            for (int i = 0; i < PLAYERS; i++)
            {
                infile >> rank >> suit;
                Card *card = new Card((Rank)rank, (Suit)suit);
                players.at(i)->AddCard(card);
            }
        }

        // close the file
        infile.close();
    }
    else
    {

        //Shuffle and Display...
        cout << " Deck is being shuffled... " << endl;
        deck.Shuffle();
        //deck.DisplayDeck();

        // deal the cards
        //Deal out the cards
        for (int i = 0; i < 5; i++)
        {
            for ( int p = 0; p < numPlayers; p++)
            {
                players.at(p)->AddCard(deck.DealNextCard());
            }
        }
    }

    // Sort the players in ascending order of hand worth
    sort(players.begin(), players.end(), HandComparer());
    for (int p = 0; p < players.size(); p++)
    {
        players.at(p)->DisplayHand();
        cout <<  "has " << players.at(p)->toString() << endl;
    }

    return 0;

}
