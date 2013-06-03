/*
    Header file for an undirected, weighted graph object.
 */

#ifndef _graph_h_
#define _graph_h_

#include <iostream>

using namespace std;


class Graph {
public:
    //Constructor
    Graph(unsigned int nodes);

    //Destructor
    ~Graph();

    /*
        Adds an edge to the graph by assigning true to the adjacency matrix. Note that src and dst must be within the dimensions of the allowable graph space
     */
    void AddEdge(unsigned int src, unsigned int dst, int weight);

    /*
        Displays the adjacency matrix via std::void
     */
    void Display();

private:

	int** links;
	int  dimension;
};

#endif
