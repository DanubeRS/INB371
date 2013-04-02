/*  ===DRIVER FILE===

    W5 - Q8/9 (c) Daniel Park 2013

    driver file for both testing, and proof-of-concept for Q8/9

    v0.1
    ====
    -Initial creation

*/

#include <iostream>
#include "card.h"
    #include "deck.h"

using namespace std;

int main()
{

    //Inform the user of the program:
    cout << "================================" << endl;
    cout << "|        Card Class Demo       |" << endl;
    cout << "================================" << endl;
    cout << "|    (c)  Daniel Park 2013     |" << endl;
    cout << "|   ***INB371_S1_W5_Q8/9***    |" << endl;
    cout << "================================" << endl << endl;


    //TEST1 - creating a card
    Card c1 = Card();

    //TEST2 - Create a filled card
    Card c2 = Card(DIAMOND, ACE);

    //TEST3 - Print a string representation of c2
    cout << c2.getCardName() << endl;

    //TEST4 - Individual card properties
    cout << c2.getRank() << " and " << c2.getSuit() << endl;

    //TEST5 - Generate new deck
    Deck d = Deck();
    d.SetStandardDeck();
    d.DisplayDeck();

}