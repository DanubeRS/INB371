/*
    Implementaiton file for an undirected, weighted graph object.
 */

//C STD Libraries
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <limits>

//Header
#include "weightedgraph.h"

using namespace std;

const int INF = numeric_limits<int>::max();     //Maximum int range
const int LOOPBACK = 0;                         //Cost of linking a node to itself


/*
constructor for a graph object. Accepts unsigned int "nodes" as the preconfigured number of nodes
 */
Graph::Graph(unsigned int nodes) {

    this->dimension = nodes;

    //Create column pointers
    links = new int*[dimension];

    //Populate the rows for each column
    for (int i = 0; i < dimension; i++) {
        links[i] = new int[dimension];
    }

    //Default all nodes as unlinked
    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; ++j) {
            if (i == j) {
                links [i][j] = LOOPBACK;
            } else {
                links[i][j] = INF;
            }
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
void Graph::AddEdge(unsigned int src, unsigned int dst, int weight) {


    //Fill in adjacency table
    links[src][dst] = weight;
    links[dst][src] = weight;

}

/*
    Displays the adjacency matrix of the graph
 */
void Graph::Display() {

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; ++j) {
            if (links[i][j] == INF) {
                cout << setw(3) << "-";
            } else {
                cout << setw(3) << links[i][j];
            }
        }

        cout << endl;
    }
}
