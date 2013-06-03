/*
    vertex Class implementation file.
 */

//C STD includes
#include <iostream>
#include <sstream>

//User includes
#include "vertex.h"

/*
	Constructs a vertex object, in which an ID is provided, and an object to which it relates to.
 */
Vertex::Vertex(int id, Point* v) {
    this->ID = id;
    this->value = v;
}

/*
	Destructor (Not required)
 */
Vertex::~Vertex() {
    //No heaped variables, thus no special action needed
}

/*
	Returns the ID of the vertex
 */
int Vertex::getID() {
    return this->ID;
}

/*
	Returns a reference to the object in which this vertex is based upon
 */
Point* Vertex::getValue(){
	return this->value;
}

/*
	Adds an adjacent vertex to the list of connected vertices
 */
void Vertex::addAdjacency(Vertex *dst) {

    this->adjacentVertices.push_back(dst);

}

/*
	This function creates a string representation (multi-line) of a vertex object
 */
std::string Vertex::toString() {
    std::stringstream buffer;

    //Provide string title
    buffer << "Vertex " << this->getID() << " Connects to: \n";

    //Iterate through the entries in the vector of adjacent vertices
    for(std::vector<Vertex*>::iterator it = adjacentVertices.begin(); it != adjacentVertices.end(); ++it){
    	buffer << "\t - Vertex " << (*it)->getID() << "\n";	//Collects the vertex ID
    }

    return buffer.str();
}