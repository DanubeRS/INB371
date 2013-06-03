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
#include <cstring>

//Header
#include "weightedgraph.h"
//#include "edgecomparer.h"

using namespace std;

const int INF = 9999;     //Maximum int range
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

    //Populate the adjacency list with empty vectors
    adjacencyList.resize(dimension);

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
void Graph::AddEdge(Edge *e) {


    //Fill in adjacency table

    links[e->getSource()->getID()][e->getDestination()->getID()] = e->getWeight();
    links[e->getDestination()->getID()][e->getSource()->getID()] = e->getWeight();

}

/*
    Displays the adjacency matrix of the graph
 */
void Graph::Display() {

    for (int i = 0; i < dimension; i++) {
        for (int j = 0; j < dimension; ++j) {
            if (links[i][j] == INF) {
                cout << setw(10) << "-";
            } else {
                cout << setw(10) << links[i][j];
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

/*
    A method which attempts to choose which TSP method would be best suited to the size of the problem.
 */
double Graph::OptimalTSP() {

    //If Brute-force method is possible
    if (false) {

        //Declare the visited array
        bool *visited = new bool[dimension];

        //reset the visited array
        for (int i = 0; i < dimension; i++) {
            visited[i] = false;
        }

        //Count first element as visited
        visited[0] = true;

        //Temporarily allocate so we can perform mem mgmt
        bool result = TSPBruteForce(0, visited);
        delete[] visited;   //Clean up some space

        return result;

    } else if (true) {
        //Create the memoisation table
        memo = new int*[dimension];
        for (int i = 0; i < dimension; i++) {
            memo[i] = new int[(1 << dimension)];
        }

        float result = TSPDP(0, 1);

        return result;
    } else {
        return ApproximateTSP();
    }
}

/*
    Adds a vertex to the scope of the graph. Returns the index for usage if required. Note that edge lengths should be recalculated once the immediate set of vertices have been added

 */
int Graph::AddVertex(Vertex *v) {
    verticesInGraph.push_back(v);
    return verticesInGraph.size() - 1;
}

/*
    TBI
 */
double Graph::ApproximateTSP() {
    return 0;
}

/*
    Brute force calculation of the optimal route.
    Guarantees a result that is potimal, but is highly ineficient - log(N!)
 */
double Graph::TSPBruteForce(int current, bool *visited) {
    bool allVisited = true;

    //Check if all stations visited
    for (int i = 0; i < dimension; i++) {
        allVisited = (allVisited && visited[i]);
    }

    if (allVisited) {
        return verticesInGraph[current]->getValue()->DistanceTo(verticesInGraph[0]->getValue());
    }

    //Copy array
    bool visitedCopy[dimension];
    std::copy(&visited[0], &visited[dimension - 1], visitedCopy);

    //Set minimum distance to infinity
    float minDistance = (float)INF;

    //For adjacent vertices across the graph
    for (int adj = 0; adj < dimension; adj++) {

        if (current != adj && !visited[adj]) {
            visitedCopy[adj] = true;
            float dist = verticesInGraph[current]->getValue()->DistanceTo(verticesInGraph[adj]->getValue()) +
                         TSPBruteForce(adj, visitedCopy);
            float minDistance = min(minDistance, dist);
            visitedCopy[adj] = false;
        }
    }
    return minDistance;
}

double Graph::TSPDP(int current, int bitmask) {
    if (memo[current][bitmask] != 0) {
        return memo[current][bitmask];
    }
    if (bitmask == ((1 << dimension) - 1)) {
        return verticesInGraph[current]->getValue()->DistanceTo(verticesInGraph[0]->getValue());
    }

    float minDistance = (float)INF;
    for (int adj = 0; adj < dimension; adj++) {
        if (current != adj && ((bitmask & (1 << adj)) == 0)) {
            float dist = verticesInGraph[current]->getValue()->DistanceTo(verticesInGraph[adj]->getValue()) +
                         TSPDP(adj, (bitmask | (1 << adj)));
            minDistance = min(minDistance, dist);
        }
    }

    memo[current][bitmask] = minDistance;
    return minDistance;
}
