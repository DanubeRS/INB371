/*  ===HEADER FILE===

    Point (c) Daniel Park 2013

    A program which uses the OOP features of c++ to define a card object

    v0.1
    ====
    -Initial creation

*/

#ifndef _card_h_
#define _card_h_

#include <string>

using namespace std;

//Enumerator Declaration
enum SUIT {CLUB = 0, DIAMOND, HEART, SPADE, _SUITS = 4};	//Four suit classes
enum RANK {ACE = 0, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, _RANKS = 13};	//13 card ranks

//FUNCTION DECLARATION
class Card{
public:
	/*
		Default construtor. Not to be used in most cases
	 */
	Card();

	/*
		Card constructor. Uses two seperate enum types to classify the card.
	 */
	Card(SUIT s, RANK r);

	/*
		Deconstructor for a card object
	 */
	~Card();

	/*
		Returns the rank of a card. (see enum RANK)
	 */
	RANK getRank();

	/*
		Returns the suit of a card (see enum SUIT)
	 */
	SUIT getSuit();

	/*
		Returns a string containing the card name as a string literal.
	 */
	string getCardName();

private:
	//No private properties required.
};

#endif



