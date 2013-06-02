/*
    Implementation file for the Map ADT. This particular ADT uses the BST implementation as an underlying data structure.
 */

#include <iostream>
#include <string>
#include "Map.h"



//Constructor
Map::Map() {
    mapStructure = BST();   //Define a new mapping structure (BST)
}

Map::~Map() {
    //No destructor needed as object variables are stacked
}

bool Map::isEmpty() {
    return mapStructure.IsEmpty();
}

int Map::Size() {
    return mapStructure.Size();
}

bool Map::ContainsKey(KeyType key) {
    return mapStructure.Search(key);
}

void Map::Put(KeyType key, ValueType val) {

    //Check to sey if key exists;
    if (mapStructure.Search(key)) {
        mapStructure.Update(key, val);
    } else {
        mapStructure.Insert(key, val);
    }
}

ValueType Map::Get(KeyType key) {
    return mapStructure.GetValue(key);
}

void Map::Traverse() {
    mapStructure.InOrderTraversal();
}

void Map::Remove(KeyType key){
    mapStructure.Delete(key);
}