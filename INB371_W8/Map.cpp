/*
    Implementation file for the Map ADT. This particular ADT uses the BST implementation as an underlying data structure.
 */

#include <cstdio>
#include "BST.h"
#include "Map.h"

using namespace std;


//Constructor
Map::Map() {
    mapStructure = new BST();   //Define a new mapping structure (BST)
}

Map::~Map() {
    delete mapStructure;
}

bool Map::isEmpty() {
    return mapStructure->IsEmpty();
}

int Map::Size() {
    return mapStructure->Size();
}

bool Map::ContainsKey(KeyType key) {
    return mapStructure->Search(key);
}

void Map::Put(KeyType key, ValueType val) {

    //Check to sey if key exists;
    if (ContainsKey(key)) {
        mapStructure->Update(key, val);
    } else {
        mapStructure->Insert(key, val);
    }
}

ValueType Map::Get(KeyType key){
	return mapStructure->Search(KeyType key)
}