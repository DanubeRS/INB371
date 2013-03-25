/*
    Cards (c) Daniel Park 2013
    
    A program which uses the interfacing features of c++ to create a card classification.

    v0.1
    ====
    -Define header file and interface

*/

    #ifndef _cards_h
    #define _cards_h


//Structures
    struct Card {

  Rank rank;
  Suit suit;
};
//Enumerators
enum SUIT {CLUB, DIAMOND, HEART, SPADE};	//Four suit classes
enum RANK {ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING};	//13 card ranks

    /*
 * Function: GetCardSuitLiteral
 * Usage: n = GetCardSuitLiteral(Card c);
 * ------------------------------------
		This function returns the literal of a cards suit as a single character.
 */
		char GetCardSuitLiteral(Card c);

		    /*
 * Function: GetCardRankLiteral
 * Usage: n = GetCardRankLiteral(Card c);
 * ------------------------------------
		This function returns the literal of a cards rank as a single character.
 */
		char GetCardRankLiteral(Card c);

				    /*
 * Function: NewDeck
 * Usage: d[] = NewDeck()
 * ------------------------------------
		This function returns an array with every deck member in the array.
 */
		Card* NewDeck();

						    /*
 * Function: Shuffle
 * Usage: Shuffle(int iter, Card[] deck)
 * ------------------------------------
		Shuffles a deck randomly, with "iter" movements.
 */
		Card* Shuffle(int iter, Card[] deck);



