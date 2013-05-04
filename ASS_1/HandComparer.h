#include "hand.h"

#ifndef _HandComparer_h_
#define _HandComparer_h_

class HandComparer
{
public:
    bool operator()(Hand *h1, Hand *h2);
};

#endif