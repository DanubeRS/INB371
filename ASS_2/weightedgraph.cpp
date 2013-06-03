/*
    Implementaiton file for an undirected, weighted graph object.
 */

//C STD Libraries
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <limits>
#include <stack>
#include <queue>

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
    links = new double*[dimension];

    //Populate the rows for each column
    for (int i = 0; i < dimension; i++) {
        links[i] = new double[dimension];
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

    //Create the wisited array for keeping track of various searching methods
    visited = new bool[dimension];

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

/*
    Sets up the Depth-First searching process for traversing a graph
 */
void Graph::DFSRecursive(unsigned int start) {
    cout << "Performing Depth-First search..." << endl;
    //Reset the visited tracking array.
    for (int i = 0; i < dimension; i++) {
        visited[i] = false;
    }

    //Call the private function to perform the recursive search
    PrivDFSRecursive(start);
}

void Graph::PrivDFSRecursive(int current) {
    cout << "Visited " << current << endl;
    visited[current] = true;
    for (int i = 0; i < dimension; i++) {
        if ( !(links[current][i] == INF || visited[i]) ) {
            PrivDFSRecursive(i);
        }
    }
}

void Graph::DFS(unsigned int start) {

    //Declare the stack in which the visited stations are recorded
    stack<int> visitOrder;
    int current;

    cout << endl << "Visit Order: " << endl;

    //Zero the visited array
    for (int i = 0; i < dimension; i++) {
        visited[i] = false;
    }
    visitOrder.push(start);
    visited[start] = true;

    while (!visitOrder.empty()) {
        current = visitOrder.top();
        visitOrder.pop();

        cout << setw(3) << current;

        for (int i = 0; i < dimension; i++)
            if ( !(links[current][i] == INF || visited[i])) {
                visitOrder.push(i);
                visited[i] = true;
            }
    }

    cout << endl;
}

void Graph::BFS(unsigned int start) {
    queue<int> breadthQueue;
    int current;

    cout << endl << "Visit Order: " << endl;

    //Zero the visited array
    for (int i = 0; i < dimension; i++) {
        visited[i] = false;
    }

    //Place start on the queue
    breadthQueue.push(start);

    visited[start] = true;

    while (!breadthQueue.empty()) {
        current = breadthQueue.front();
        breadthQueue.pop();

        cout << setw(3) << current;

        for (int i = 0; i < dimension; i++) {
            if ( !(links[current][i] == INF || visited[i])) {
                breadthQueue.push(i);
                visited[i] = true;
            }
        }
    }

    cout << endl;


}

