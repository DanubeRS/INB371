/*
    Driver file for Assignment 2 - INB371_2013_S1
    (c) Daniel Park 2013
 */

//C STD Lib Includes
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

//User Defined libraries
#include "random.h"
#include "point.h"
#include "weightedgraph.h"
#include "timer.cpp"

//Program Wide Constants
const unsigned int MAX_POINT_RANGE  = 100;
const unsigned int NUMBER_OF_POINTS = 10;

//Debug Info flags
const bool TIMER_TEST               =   true;
const bool DEBUG_MESSAGES           =   true;
const bool LIST_RANDOM_POINTS       =   false;
const bool TEST_EUCLIDEAN_DISTANCE  =   false;
const bool LIST_EDGES               =   false;
const bool EDGE_TEST                =   false;

std::ostringstream debugSS; //Debug SS for passing to InformationMessage()

void InformationMessage(string msg);

//Core datatypes
vector<Point *> randomPoints;       //Collection of Randomly generated points
Graph *connectedPoints;             //Graph of connected points as per randompoints
Timer *timer;                       //Timer for measuring performance

//Program-based Prototypes
vector<Point *> RandomPoints(unsigned int n);



//Program Entry Point//
//===================//
int main(int argc, char const *argv[]) {


    cout << "================================" << endl;
    cout << "|    The Travelling Salesman   |" << endl;
    cout << "================================" << endl;
    cout << "|    (c)  Daniel Park 2013     |" << endl;
    cout << "|  ***INB371_S1_2013_ASS2***   |" << endl;
    cout << "================================" << endl << endl;

    //Create a timer for timing applications
    timer = new Timer();

    //Create random points
    InformationMessage("Randomising Points...");
    randomPoints = RandomPoints(NUMBER_OF_POINTS);
    
    debugSS << NUMBER_OF_POINTS << " created";
    InformationMessage(debugSS.str());

    //Test distance computation between to points
    if (TEST_EUCLIDEAN_DISTANCE) {

        //Randomise two points
        Point *pointA = randomPoints[RandomInteger(0, NUMBER_OF_POINTS - 1)];
        Point *pointB = randomPoints[RandomInteger(0, NUMBER_OF_POINTS - 1)];

        //Print results of calculation
        cout << "Distance between " << pointA->Display() << " and " << pointB->Display() << " is " << pointA->DistanceTo(pointB) << endl;
    }

    //Construct a fully connected tree of all nodes.
    connectedPoints = new Graph(NUMBER_OF_POINTS);

    vector<Vertex * >pointsAsVert;
    InformationMessage("Creating vertices from randomised points");
    //Create our vertices, of which we can pass-by-reference to the graph
    for (int i = 0; i < NUMBER_OF_POINTS; i++) {
        pointsAsVert.push_back(new Vertex(i, randomPoints[i]));
    }

    InformationMessage("Adding vertices to the graph.");
    timer->Start();
    //Create a new vertex for all of the random points.
    for (std::vector<Vertex *>::iterator it = pointsAsVert.begin(); it != pointsAsVert.end(); it++) {
        connectedPoints->AddVertex(*it);
    }
    timer->Stop();

    //As all of our points have been added, we can go ahead and re-calculate our edges.
    for (int i = 0; i < pointsAsVert.size(); i++) {
        for (int j = 0; j < pointsAsVert.size(); j++) {
            connectedPoints->AddEdge(new
                                     Edge(pointsAsVert[i],
                                          pointsAsVert[j],
                                          pointsAsVert[i]->getValue()->DistanceTo(
                                              pointsAsVert[j]->getValue()
                                          )));
        }

    }

    //list first vertex, and its distance to a random point, and itself
    if (EDGE_TEST) {
        Vertex *randomVert = pointsAsVert[RandomInteger(0, NUMBER_OF_POINTS - 1)];
        cout << pointsAsVert[0]->getValue()->Display() << endl;
        cout << pointsAsVert[0]->getValue()->DistanceTo(randomVert->getValue()) << endl;
        cout << pointsAsVert[0]->getValue()->DistanceTo(pointsAsVert[0]->getValue()) << endl;
    }

    //List edge calculations
    if (LIST_EDGES) {
        for (int i = 0; i < pointsAsVert.size(); i++) {
            for (int j = 0; j < pointsAsVert.size(); j++) {
                cout << (Edge(pointsAsVert[i],
                              pointsAsVert[j],
                              pointsAsVert[i]->getValue()->DistanceTo(
                                  pointsAsVert[j]->getValue()
                              ))).toString() << endl;
            }

        }

    }

    connectedPoints->Display();
    InformationMessage("Performing TSP analysis");
    cout << connectedPoints->OptimalTSP() << endl;;




    return 0;
}

/*
    Method which returns a vector of pointers to heap-stored Point objects.
 */
vector<Point *> RandomPoints(unsigned int n) {

    vector<Point *> randomVector;

    //Create a vector of randomised points
    for (int i = 0; i < n; i++) {
        randomVector.push_back(new Point(RandomInteger(0, MAX_POINT_RANGE), RandomInteger(0, MAX_POINT_RANGE)));
    }

    //List point information
    if (LIST_RANDOM_POINTS) {

        cout << "Listing Random Points..." << endl;

        for (int i = 0; i < randomVector.size(); i++) {
            cout << randomVector[i]->Display();
            if (i > 0 && (i + 1) % 10 == 0) {
                cout << endl;
            }
        }
    }
    return randomVector;
}

/*
    Method which prints messages if the message pringting flag is set to true.
 */
void InformationMessage(string msg) {
    if (DEBUG_MESSAGES) {
        cout << msg << endl;
    }
}

// /*
//     Special case of information message, whereby a stringstream is passed
//  */
// void InformationMessage(std::ostringstream ss){
//     InformationMessage(ss.str());
//     ss.clear();
// }
