#include <iostream>
#include <iomanip>

#include "HandComparer.h"
#include "hand.h"

bool HandComparer::operator()(Hand *h1, Hand *h2)
{

    //Catch same hand types. We have to compare the hand score if this is the case
    if (h1->getHandType() == h2->getHandType())
    {
        // If there are two flushes, we need to do a card-by-card comparison.
        //Nice and easy if we have a notn-flush
        if (h1->getHandType() != FLUSH)
        {

            return h1->getHandValue() < h2->getHandValue();
        }
        //Compare card-by-card for a flush
        else if (h1->getHandType() == FLUSH)
        {
            for (int i = 0; i < h1->getHandSize(); i++)
            {
                //If a card in the other deck, at the same position is greater for all cards, then we immidiately know to swap
                if (h1->getCard(i)->GetRank() < h2->getCard(i)->GetRank())
                    return false;
            }
            //Otherwise its a higher hand
            return true;
        }

    }
    else
    {
        return (h1->getHandType() > h2->getHandType());
    }

}



