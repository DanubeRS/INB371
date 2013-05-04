/*
    A hand is considered a special case of a deck.
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cmath>


#include "deck.h"
#include "card.h"
#include "random.h"

#include "hand.h"
#include "CardComparer.h"

using namespace std;

const int HANDSIZE = 5;

/*
    Constructs a hand with ID
 */
Hand::Hand(int ID)
{
    m_ID = ID;
}

/*
    Deconstructor
    (Currently not required)
 */
Hand::~Hand()
{
}

/*
    Adds a card to the hand. Catches error if more cards are dealt than needed.
 */
void Hand::AddCard(Card *c)
{

    if (!(cardsReceived >= HANDSIZE))
    {
        cards.push_back(c);
    }
    else
    {
        cout << "An internal dealer error has occoured." << endl;
    }
}


/*
    Returns the value of the players hand. Used for calculating hand places when deeciding a winner.
 */
int Hand::getHandValue()
{

    /*
        The premise behind the score evaluation process is to create a boolean array signifying if a card has been tallied up. Only cards which are still
        valie (i.e: true) are considered.
     */

    //Make sure that the hand is sorted before calculating its value!
    sort(cards.begin(), cards.end(), CardComparer());
    std::vector<bool> counted (cards.size(), true);

    int score = 0;
    int iterate;

    switch (this->getHandType())
    {
    case HIGHCARD:  //All cards get tallied
        for (int i = 0; i < cards.size(); i++)
        {
            score += ((int)(cards.at(i)->GetRank()) * (int)pow((double)10, (double)cards.size() - 1 - i));
        }
        break;
    case ONEPAIR:   //Find the pair, then calculate it. After this, calculate the rest.
        //find pair for calculation
        iterate = cards.size() - 1;

        for (int i = 0; i < (cards.size() - 1); i++)
        {
            if (cards.at(i)->GetRank() == cards.at(i + 1)->GetRank())
            {
                score += (int)cards.at(i)->GetRank() * (int)pow((double)10, (double)iterate);
                counted.at(i) == false;
                counted.at(i + 1) == false;
                iterate--;
            }
        }
        for (int i = 0; i < cards.size(); i++)
        {
            if (counted.at(i))
            {
                score += ((int)cards.at(i)->GetRank()) * (int)pow((double)10, (double)iterate);
                iterate--;
            }

        }
        break;
    case THREEOFAKIND:   //Find the pair, then calculate it. After this, calculate the rest.
        //find pair for calculation
        iterate = cards.size() - 2;

        for (int i = 0; i < (cards.size() - 2); i++)
        {
            if (cards.at(i)->GetRank() == cards.at(i + 1)->GetRank() == cards.at(i + 2)->GetRank())
            {
                score += (int)cards.at(i)->GetRank() * (int)pow((double)10, (double)iterate);
                counted.at(i) == false;
                counted.at(i + 1) == false;
                counted.at( i + 2) == false;
                iterate--;
            }
        }
        for (int i = 0; i < cards.size(); i++)
        {
            if (counted.at(i))
            {
                score += ((int)cards.at(i)->GetRank()) * (int)pow((double)10, (double)iterate);
                iterate--;
            }

        }
        break;
    case FOUROFAKIND:   //Find the pair, then calculate it. After this, calculate the rest.
        //find pair for calculation
        iterate = cards.size() - 3;

        for (int i = 0; i < (cards.size() - 2); i++)
        {
            if (cards.at(i)->GetRank() == cards.at(i + 1)->GetRank() == cards.at(i + 2)->GetRank() == cards.at(i + 3)->GetRank())
            {
                score += (int)cards.at(i)->GetRank() * (int)pow((double)10, (double)iterate);
                counted.at(i) == false;
                counted.at(i + 1) == false;
                counted.at( i + 2) == false;
                counted.at(i + 3) == false;
                iterate--;
            }
        }
        for (int i = 0; i < cards.size(); i++)
        {
            if (counted.at(i))
            {
                score += ((int)cards.at(i)->GetRank()) * (int)pow((double)10, (double)iterate);
                iterate--;
            }

        }
        break;
    case STRAIGHT:
        score = (int)cards.at(0)->GetRank();
        break;

    case TWOPAIR:
        //This case needs us to find the highest value of the two pairs.
        Rank previousHighest;
        Rank currentPair;
        for (int i = 0; i < (cards.size() - 1); i++)
        {
            if (cards.at(i)->GetRank() == cards.at(i + 1)->GetRank())
            {
                previousHighest = currentPair;
                currentPair = cards.at(1)->GetRank();
                counted.at(i) == false;
                counted.at(i + 1) == false;
                if (currentPair > previousHighest)
                {

                    score = (currentPair) * (int)pow((double)10, (double)2) +
                            (previousHighest) * (int)pow((double)10, (double)1);
                }
                else if (currentPair < previousHighest)
                {
                    score = (previousHighest) * (int)pow((double)10, (double)2) +
                            (currentPair) * (int)pow((double)10, (double)1);
                }
            }
        }
        for (int i = 0; i < (cards.size()); i++)
        {
            if (counted.at(i))
            {
                score += (int)cards.at(i)->GetRank();
            }
        }

    default:
    {
        //Nothing
    }
    }
    return score;


}

Card *Hand::getCard(int n)
{
    return cards.at(n);
}

int Hand::getHandSize(){
    return cards.size();
}

void Hand::DisplayHand()
{
    sort(cards.begin(), cards.end(), CardComparer());

    cout << "Player " << m_ID << ": [";

    for (int i = 0; i < cards.size(); i++)
    {
        cout << cards.at(i)->GetCardName() << " ";

    }
    cout << "] ";
}


/*
    Evaluates the current game dealt.
 */
void Hand::Evaluate(Hand *game)
{

}

string Hand::toString()
{

    switch (getHandType())
    {
    case HIGHCARD:
        return "High Card";
    case ONEPAIR:
        return "One Pair";
    case TWOPAIR:
        return "Two pairs";
    case THREEOFAKIND:
        return "Three of a Kind";
    case STRAIGHT:
        return "Straight";
    case FLUSH:
        return "Flush";
    case FULLHOUSE:
        return "Full Hosue";
    case FOUROFAKIND:
        return "Four of a kind";
    case STRAIGHTFLUSH:
        return "Straight Flush";
    }
}

int Hand::getID()
{
    return m_ID;
}

/*
        The idea behind HandType is to progressively work through the hand types specified.
 */
HandType Hand::getHandType()
{
    /*
        Calculate the best hand type. As it is near impossible to check with total generecism, multiple cases need to be examined.
     */

    //Sorting is required to easily test the set.
    sort(cards.begin(), cards.end(), CardComparer());


    // Calculate simmilar cards by "binning" them into rank.
    int *bins = new int[(int)RANKS];

    for (int i = 0; i < cards.size(); i++)
    {
        bins[(int)(cards.at(i)->GetRank())]++;
    }


    //Calculate number of pairs
    int pairs = 0;
    for (int i = 0; i < RANKS; i++)
    {
        if ( bins[i] == 2)
        {
            pairs++;
        }
    }

    //Check if set contains a triplet (Maximum of one can occour)
    bool triplet = false;
    for (int i = 0; i < RANKS; i++)
    {
        if ( bins[i] == 3)
        {
            triplet = true;
        }
    }
    bool quadruplet = false;
    //Check if set contains a quadruplet (Maximum of one can occour)
    for (int i = 0; i < RANKS; i++)
    {
        if ( bins[i] == 4)
        {
            quadruplet = true;
        }
    }


    //check for a straight
    bool straight = true;
    for (int i = 0; i < cards.size() - 1; i++)
    {
        straight = straight && ((int)(cards.at(i)->GetRank()) == (int)(cards.at(i + 1)->GetRank()) + 1);    //Evaluates to false as soon as a sequence is broken.
    }

    //Check for a flush
    bool flush = true;
    for (int i = 0; i < cards.size() - 1; i++)
    {
        flush = flush && (cards.at(i)-> GetSuit() == cards.at(i + 1)->GetSuit());       //Evaluates to false as soon as a sequence is broken.
    }

    //Test all hand properties to derive what type of hand it is (Simmilar to traversing a logic tree)
    switch (pairs)
    {
    case 0:
        bestHandType = HIGHCARD;

        //Check for non-sequential hand types
        if (flush)
        {
            if (straight)
            {
                bestHandType = STRAIGHTFLUSH;
                break;
            }
            else
            {
                bestHandType = STRAIGHT;
                break;
            }
        }
        else if (straight)
        {
            bestHandType = FLUSH;
            break;
        }
        else
        {
            bestHandType = HIGHCARD;
        }
        break;

    case 1:

        bestHandType = ONEPAIR;                 //One Pair
        if ( triplet )
        {
            bestHandType = FULLHOUSE;           //Full house (A pair, plus a triplet)
        }
        break;
    case 2:
        bestHandType = TWOPAIR;
        break;
    }

    return bestHandType;
}
