/*  ===HEADER FILE===

    Card (c) Daniel Park 2013

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
enum SUIT {CLUB = 0, DIAMOND, HEART, SPADE, SUITS = 4};	//Four suit classes
enum RANK {ACE = 0, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING, RANKS = 13};	//13 card ranks

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
	string getRank();

	/*
		Returns the suit of a card (see enum SUIT)
	 */
	string getSuit();

	/*
		Returns a string containing the card name as a string literal.
	 */
	string getCardName();

private:

	enum SUIT m_suit;
	enum RANK m_rank;

	/*
		Returns a literal of the card rank. This will always be one or two letters in length.
	 */
	string getRankLiteral();

	/*
		Returns a literal of the card suit. In all cases this is a single letter
	 */
	string getSuitLiteral();

	/*
	Instantised method for calling overloaded method based on instance called
 */
string getSuitLiteral(SUIT s);

/*
	Instantised method for calling overloaded method based on instance called
 */
string getRankLiteral(RANK r);
};

#endif



