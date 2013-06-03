/*
    A simple program chich constructs a graph from the argumed text file
 */

//@lib
//C STD Libraries
#include <iostream>
#include <fstream>

//User generated includes
#include "graph.h"


int main(int argc, char const *argv[]) {
    //Load file from command line
    ifstream ifile;

    //Open the argued file
    ifile.open(argv[1]);
    if (ifile.fail()) {
        cerr << "Opening file failed" << endl;
        return -1;
    }

    //Read the file, entering vertices, and creating links
    int numVertices, numEdges, src, dst;

    ifile >> numVertices;
    ifile >> numEdges;

    Graph *graph = new Graph(numVertices);

    for (int edge = 0; edge < numEdges; edge++) {
        ifile >> src >> dst;

        graph->AddEdge(src, dst);
    }

    graph->Display();

    return 0;
}