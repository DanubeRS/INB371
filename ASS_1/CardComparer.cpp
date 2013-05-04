#include <iostream>
#include <iomanip>

#include "CardComparer.h"
#include "card.h"


bool CardComparer::operator()(Card* c1, Card* c2)
{

    return c1->GetRank() > c2->GetRank();

}


