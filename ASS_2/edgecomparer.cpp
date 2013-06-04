/*
    Edgecomparer is a simple class, containing an operator overide. This overide (operator()) returns true if the first argument is shorter/smaller than the second
 */

#ifndef _edgecomparer_h_
#define _edgecomparer_h_

#include "edge.h"

class EdgeComparer {

public:

    /*
        Comparitor method which returns true if the first edge (e1) is shorter/smaller than the second (e2)
     */
    bool operator() (Edge *e1, Edge *e2) {
        return e1->getWeight() < e2->getWeight();
    }


};


#endif