#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>

#include "deck.h"
#include "card.h"
#include "hand.h"
#include "handcomparer.h"

using namespace std;

const int PLAYERS = 10;
const int CARDS_PER_PLAYER = 5;

int main(int argc, char *argv[]) {

    // Declare Deck and vector of pointer to Hand

    // create Hand for each player

    // allow for testing from file
    if (argc == 2) {

        // open the file and check it exists
        ifstream infile;
        infile.open(argv[1]);
        if (infile.fail()) {
            cerr <<  "Error: Could not find file" << endl;
            return 1;
        }

        // read the cards into the hands
        int rank, suit;
        for (int card = 0; card < CARDS_PER_PLAYER; card++) {
            for (int i = 0; i < PLAYERS; i++) {
                infile >> rank >> suit;
                Card *card = new Card((Rank)rank, (Suit)suit);
                hands[i]->AddCard(card);
            }
        }

        // close the file
        infile.close();
    } else {

        // shuffle

        // deal the cards
    }

    // evaluate the hands

    // sort the hands

    // output the hands

    return 0;

}
