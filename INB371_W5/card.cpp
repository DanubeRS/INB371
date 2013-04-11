/*  ===IMPLEMENTATION FILE===

    Card (c) Daniel Park 2013

    A program which uses the OOP features of c++ to define a card object

    v0.1
    ====
    -Initial creation

*/

//User libraries
#include "card.h"
#include <sstream>

//System/Standard libraries
#include <iostream>

using namespace std;

//===============
// PUBLIC METHODS
//===============

/*
    Default construtor. Not to be used in most cases
 */
Card::Card()    //DEFAULT CONSTRUCTOR
{
    //Default card constructor. Not recommended for production use.
    //cout << "INFO: Empty constructor used for card object. Not recommended for production use." << endl;
    m_suit = (SUIT)0;
    m_rank = (RANK)0;
}

/*
    Card constructor. Uses two seperate enum types to classify the card.
 */
Card::Card(SUIT s, RANK r)
{
    //Constructs a card with the argumented paramaters assigned as the cards properties
    m_suit = s;
    m_rank = r;

    //DEBUG
    cout << "Generated card: " << getRankLiteral(m_rank) << getSuitLiteral(m_suit) << endl;

}

/*
    Deconstructor for a card object
 */
Card::~Card()
{

    //TO BE IMPLEMENTED
}

/*
    Returns the rank of a card. (see enum RANK)
 */
string Card::getRank()
{
    return getRankLiteral(m_rank);
}

/*
    Returns the suit of a card (see enum SUIT)
 */
string Card::getSuit()
{
    return getSuitLiteral(m_suit);
}

/*
    Returns a string containing the card name as a string literal.
 */
string Card::getCardName()
{

    stringstream stream;
    stream << getRankLiteral() << getSuitLiteral();
    return stream.str();
}

//=================
// PRIVATE METHODS
//=================
string Card::getRankLiteral(RANK r)
{
    switch (r)
    {
    case ACE:
        return "A";
    case TWO:
        return "2";
    case THREE:
        return "3";
    case FOUR:
        return "4";
    case FIVE:
        return "5";
    case SIX:
        return "6";
    case SEVEN:
        return "7";
    case EIGHT:
        return "8";
    case NINE:
        return "9";
    case TEN:
        return "10";
    case JACK:
        return "J";
    case QUEEN:
        return "Q";
    case KING:
        return "K";
    default:
        cout << "Internal Error. " << "Value of " << r << endl;
        return "!"; //Return an error symbol

    }
}
string Card::getSuitLiteral(SUIT s)
{
    switch (s)
    {
    case CLUB:
        return "C";

    case DIAMOND:
        return "D";

    case HEART:
        return "H";

    case SPADE:
        return "S";

    default:
        cout << "Internal Error. " << "Value of " << s << endl;
        return "!"; //Returns an error symbol if incorrect argument is passed
    }

}

/*
    Instantised method for calling overloaded method based on instance called
 */
string Card::getSuitLiteral()
{
    return getSuitLiteral(m_suit);
}

/*
    Instantised method for calling overloaded method based on instance called
 */
string Card::getRankLiteral()
{
    return getRankLiteral(m_rank);
}
