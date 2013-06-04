/*
    Implementation file of a Disjoint Set for minimum cost spanning tree
 */

#include <iostream>
#include <vector>

#include "disjointset.h"

/*
    Initialises a new Disjoint Set with maximum size;
 */
DisjointSet::DisjointSet(int size) {
    for (int i = 0; i < size; i++) {
        parents.push_back(i);   //Asign each element as its own parent
        treeDepth.push_back(i);
    }
}

/*
    Deconstructs the object (not required)
 */
DisjointSet::~DisjointSet() {
    //No objects to remove from heap
}

/*
    Finds the parent element of the node. Will return its own index if it is at the top of the tree
 */
int DisjointSet::Find(int i) {
    return parents[i];
}

void DisjointSet::Union(int setA, int setB) {

    //Check to see if they are already in the same set
    if (SameComponent(setA, setB)) {
        return;
    }

    //Find oldest ancestors of the nodes
    int i = OldestAncestor(setA);
    int j = OldestAncestor(setB);

    parents[i] = j;
    //Attach the shortest node to the longest nodes parent
    //     if (treeDepth[i] < treeDepth[j] ) {
    //         parents[i] = j;
    //         treeDepth[j] += treeDepth[i];
    //     } else  {
    //         parents[j] = i;
    //         treeDepth[i] += treeDepth[j];
    //     }
}

/*
    An extension of the Find() method. ##TBI This also implements path-compression as it searches to make future trancendances for efficient## */
int DisjointSet::OldestAncestor(int element) {
    int oldestAncestor = element;

    //While the tree still can be travelled down
    while (Find(element) != element) {
        element = Find(element);
    }

    return oldestAncestor;
}

/*
    Checks to see if the oldest ancestors of the elements is the same
 */
bool DisjointSet::SameComponent(int setA, int setB) {
    return ( OldestAncestor(setA) == OldestAncestor(setB));
}


