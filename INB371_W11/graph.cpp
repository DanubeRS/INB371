/*
    Implementaiton file for an undirected, unweighted graph object.
 */

//C STD Libraries
#include <cstdio>
#include <iostream>
#include <iomanip>

//Header
#include "graph.h"


/*
constructor for a graph object. Accepts unsigned int "nodes" as the preconfigured number of nodes
 */
Graph::Graph(unsigned int nodes) {

    this->dimension = nodes;

    //Create column pointers
    links = new bool*[dimension];

    //Populate the rows for each column
    for (int i = 0; i < dimension; i++) {
        links[i] = new bool[dimension];
    }

    //Default all nodes as unlinked
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; ++j) {
            links[i][j] = false;
        }
    }

}

/*
    Deconstructor for a Graph object
 */
Graph::~Graph() {

    for (int i = 0; i < dimension; i++) {
        delete[] links[i];
    }

    delete[] links;

}

/*
    Adds an edge to the graph
 */
void Graph::AddEdge(unsigned int src, unsigned int dst) {

    if ( !links[src][dst] || !links[dst][src]) {

        //Fill in adjacency table
        links[src][dst] = true;
        links[dst][src] = true;

    } else {
        cout << "Link already exists" << endl;
    }

}

/*
    Displays the adjacency matrix of the graph
 */
void Graph::Display() {

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; ++j) {
            if (links[i][j]) {
                cout << setw(2) << "Y";
            } else {
                cout << setw(2) << "N";
            }
        }

        cout << endl;
    }
}
