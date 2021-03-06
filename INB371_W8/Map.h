/*
    Header file for the MAP ADT.
 */

#include "BST.h"

#ifndef _map_h_
#define _map_h_


class Map {

    //Private Methods and Data
public:

    //Constructor
    Map();

    //Destructor
    ~Map();

    /*
        Returns true if the map has no key-value pairs
     */
    bool isEmpty();

    /*
        Returns the emelent count of the map
     */
    int Size();

    /*
        Returns true if the key is contained within the map
     */
    bool ContainsKey(KeyType);

    /*
        Adds the key and associates a value to it, or if the key exists, the value is added to it
     */
    void Put(KeyType, ValueType);

    /*
        Gets the value of the associated key. Returns NULL if the key does nt exist
     */
    ValueType Get(KeyType);

    /*
        Removes the key if it exists
     */
    void Remove(KeyType);

    void Traverse();


    //Public Methods and Data
private:

    BST mapStructure;

};


#endif