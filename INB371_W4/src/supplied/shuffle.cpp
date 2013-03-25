/*
 * File: shuffle.cpp
 * Creates a deck of cards, shuffles them and displays them.
 */

#include <iostream>
#include <iomanip>

#include "card.h"
#include "random.h"

using namespace std;

/* Constants */

const int NUM_CARDS = 52;
const int NUM_SUITS = 4;
const int NUM_RANKS = 13;
const int NUM_SHUFFLES = 1000;

/* Function Prototypes */

/* Creates the deck of cards */

/* Shuffles the deck of cards */

/* Swaps the location of cards in deck at idx1 and idx 2 */

/* Displays the current configuration of the deck */

int main() {
	
	Card *deck;
	
	Randomize();
	deck = CreateDeck();

	DisplayDeck(deck);
	cout << endl;

	Shuffle(deck);
	DisplayDeck(deck);
	
	return 0;
}

