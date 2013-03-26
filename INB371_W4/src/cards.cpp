/*
    Cards (c) Daniel Park 2013
    
    A program which uses the interfacing features of c++ to create a card classification.

    v0.1
    ====
    -Initial creation

*/
#include <cstdlib>
#include <algorithm>	//Used for element swapping
#include "cards.h"
#include "supplied/random.h"

        /*
 * Function: GetCardSuitLiteral
 * Usage: n = GetCardSuitLiteral(Card c);
 * ------------------------------------
		This function returns the literal of a cards suit as a single character.
 */
		char GetCardSuitLiteral(Card c){
			switch (c.suit){
				case CLUB:
					return 'C';
					
				case DIAMOND:
					return 'D';
					
				case HEART:
					return 'H';
					
				case SPADE:
					return 'S';
					
				default:
					cout << "Internal Error." << endl;
					return '!';	//Returns an error symbol if incorrect argument is passed
					
			}
		}

		    /*
 * Function: GetCardRankLiteral
 * Usage: n = GetCardRankLiteral(Card c);
 * ------------------------------------
		This function returns the literal of a cards rank as a single character.
 */
		char GetCardRankLiteral(Card c){
			switch (c.rank) {
				case ACE:
					return 'A';
				case TWO:
					return '2';
				case THREE:
					return '3';
				case FOUR:
					return '4';
				case FIVE:
					return '5';
				case SIX:
					return '6';
				case SEVEN:
					return '7';
				case EIGHT:
					return '8';
				case NINE:
					return '9';
				case TEN:
					return 'T';
				case JACK:
					return 'J';
				case QUEEN:
					return 'Q';
				case KING:
					return 'K';
				default:
					cout << "Internal Error." << endl;
					return '!';	//Return an error symbol

			}
		}

				    /*
 * Function: NewDeck
 * Usage: d[] = NewDeck()
 * ------------------------------------
		This function returns an array with every deck member in the array.
 */
		Card *NewDeck(){

			Card *retArr;
			int i = 0;		//Card in deck.
			for (int s = 0; s < _SUITS; s++){	//Iterate through suits.
				for (int r = 0; r < _RANKS, r++ ){	//Iterate through ranks.
					retArr[i].rank = (RANK)r;	//Apply RANK
					retArr[i].suit = (SUIT)s;	//Apply SUIT
					i++;						//Increment deck index.
				}
			}
			return retArr;	//Pass back created object reference
		}

						    /*
 * Function: Shuffle
 * Usage: Shuffle(int iter, Card[] deck)
 * ------------------------------------
		Shuffles a deck randomly, with "iter" movements.
 */
		void Shuffle(int iter, Card* deck, int deckSize){
			int elementA, elementB;		//two random elements to swap.
			for (int i = 0; i < iter; i++){
				
				//randomly select any two cards from within the deck (duplicates possible)
				elementA = RandomInteger(0, deckSize - 1);
				elementB = RandomInteger(0, deckSize - 1);
				
				//Note that selecting two elements that reference 
				//the same indel is the same as a dealer pulling 
				//a card and putting it back in exactly the same place
				if (elementA != elementB){	//If different elements are randomly selected
					swap(deck[elementA], deck[elementB]);	//Swap
				}

			}

		}