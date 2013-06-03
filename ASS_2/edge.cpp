/*
    Implementation file of the edge class
 */

//C STD Libs
#include <iostream>
#include <string>
#include <sstream>

//User libs
#include "edge.h"
#include "vertex.h"

/*
    Constructor
 */
Edge::Edge(Vertex *s, Vertex *d, double wt) {
    this->src = s;
    this->dst = d;
    this->weight = wt;
}
/*
    Destructor (Not used)
 */
Edge::~Edge() {
}

/*
    Accessors for the Source and Destination vertices
 */
Vertex *Edge::getSource() {
    return this->src;
}

Vertex *Edge::getDestination() {
    return this->dst;
}

double Edge::getWeight() {
    return this->weight;
}

std::string Edge::toString() {
    std::stringstream buffer;

    //Provide connection details
    buffer << "This edge connects the vertices " << this->src->getID() << " to " << this->dst->getID();

    return buffer.str();
}