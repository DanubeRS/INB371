/*
    Header file for the edge class
 */

//C STD Libs
#include <iostream>

//User libs
#include "vertex.h"


#ifndef _edge_h_
#define _edge_h_

class Edge {
public:
    /*
        Constructs and edge object, connecting two vertices (passed as references) with a given weight.
     */
    Edge(Vertex *src, Vertex *dst, double wt);

    /*
    	Destructs the edge object (not required)
     */
    ~Edge();

    /*
    	Returns a reference to the vertex of which this path sources from
     */
    Vertex* getSource();

    /*
    	Returns a reference to the vertex of which this path leads to
     */
    Vertex* getDestination();

    /*
    	Returns the weight of this edge
     */
    double getWeight();

    /*
    	Returns a string representation of the edge
     */
    std::string toString();

private:
	Vertex* src;
	Vertex* dst;
	double weight;
};

#endif