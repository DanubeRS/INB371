/*
    Header file for an undirected, weighted graph object.
 */

#ifndef _graph_h_
#define _graph_h_

#include <iostream>
#include <vector>
#include <priority_queue>

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

    /*
        Method which sets up the process of Depth-First Searching, and calls the private mehtod which completes the searchning
     */
    void DFSRecursive(unsigned int start);

    /*
        Method which iteratively performs a Depth-first search
     */
    void DFS(unsigned int start);

    /*
        Method which performs a Breadth-first search across the graph
     */
    void BFS(unsigned int start);



private:

    void PrivDFSRecursive(int current);
    double **links;    //Adjacency matrix
    int  dimension;    //Number of Vertices in the graph
    vector< vector<int> > adjacencyList;   //Adjacency list

    //Visited array, used for searching the graph
    bool *visited;

    //An edge list
    std::priority_queue<Edge*, vector<Edge*>, EdgeCompare> edgeList;
};

#endif