/*
    Header file for an undirected, weighted graph object.
 */

#ifndef _graph_h_
#define _graph_h_

#include <iostream>
#include <vector>
#include <queue>

#include "edge.h"
#include "edgecomparer.cpp"
#include "disjointset.h"

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
    void AddEdge(Edge *e);

    /*
        Adds a vertex to the scope of the graph. Returns the index for usage if required
     */
    int AddVertex(Vertex *v);

    /*
        Displays the adjacency matrix via std::void
     */
    void Display();

    /*
        Internally chooses which shortest path approximation to use.
     */
    double OptimalTSP();

    /*
        Recalculates all the edge lengths. Assumes fully connected. Ignores if previously calculated.
        TODO: Check if exists, even if only via a linear probe search
     */
    
    void DisplayLinks();



private:

    /*
    Method which iteratively performs a Depth-first search
    */
    double DFS(unsigned int start);

    double **links;    //Adjacency matrix
    int  dimension;    //Number of Vertices in the graph
    vector< vector<int> > adjacencyList;    //Adjacency list
    vector<Vertex *> verticesInGraph;        //List of all vertices in the current graph

    //Visited array, used for searching the graph
    bool *visited;

    //An Edge List
    std::priority_queue<Edge *, vector<Edge *>, EdgeComparer> edgeList;

    //===========================//
    // TSP shortest-path solvers //
    //===========================//

    /*
        Uses the Approximation algorithm to calculate the optimal path length
     */
    double ApproximateTSP();

    /*
        Uses a brute-force method to solve the optimal path length
     */
    double TSPBruteForce(int node, bool *visited);

    /*
        Uses a synamic programming model for calculating the optimal path length
     */
    double TSPDP(int current, int bitmask);

    //Memo table for use in TSPDP
    int **memo;
};

#endif