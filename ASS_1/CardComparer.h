#include "card.h"

#ifndef _CardComparer_h_
#define _CardComparer_h_

class CardComparer
{
public:
    bool operator()(Card *c1, Card *c2);
};

#endif