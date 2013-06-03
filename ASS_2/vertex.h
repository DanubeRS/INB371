/*
    Header file for the Vertex Class
 */


#include <iostream>
#include <vector>
#include <string>

#include "point.h"

#ifndef _vertex_h_
#define _vertex_h_



class Vertex {
public:
    /*
        Creates a vertex wiht the provided ID
     */
    Vertex(int id, Point* v);

    /*
        Deconstructs the vertex object
     */
    ~Vertex();

    /*
        Returns the ID of the vertex
     */
    int getID();

    /*
        Adds a pointer to anohter vertex, of which this vertex connects to
     */
    void addAdjacency(Vertex *dst);

    /*
        Returns a vector of vertex pointers adjacent to this node
     */
    std::vector<Vertex *> getAdjacencies();

    /*
        Returns a string representation of the vertex
     */
    std::string toString();

    /*
    	Returns a reference to the point of which this vertex is based upon
     */
    Point* getValue();

private:

    std::vector<Vertex *> adjacentVertices;			//Adjacent vertices as required by the MST
    int ID;			//ID of the vertex. Should be unique.
    Point* value;	//Reference to the point in which this vertex encompasses

};

#endif