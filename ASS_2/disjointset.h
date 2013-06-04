/*
    Header file of a Disjoint Set for minimum cost spanning tree
 */

#ifndef _disjointset_h_
#define _disjointset_h_

#include <iostream>
#include <vector>

class DisjointSet {
public:
    /*
        Initialises a new Disjoint Set with maximum size;
     */
    DisjointSet(int size);

    /*
        Deconstructor
        (Not Required)
     */
    ~DisjointSet();

    /*
        Finds the parent element of the node.
     */
    int Find(int);

    /*
        Creates a union between two disjoint sets. the two sets are denoted by the indices argued
     */
    void Union(int setA, int setB);

    /*
        Returns true if the two elements fall into the same set
     */
    bool SameComponent(int elementA, int elementB);
private:
    //note that the index of parents[] is the Id of the node checked.
    std::vector<int> parents;	//Keeps track of the links in the set
    std::vector<int> treeDepth;		//Keeps track of how deep the tree to this node is

    /*
    	Method which finds the oldest linked ancestor of an index
     */
    int OldestAncestor(int element);
};
#endif