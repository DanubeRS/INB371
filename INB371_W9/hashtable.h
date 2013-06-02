#ifndef _hashtable_h_
#define _hashtable_h_

#include <vector>

using namespace std;

template <typename KeyType, typename DataType>
class HashTable {
public:
    HashTable();
    HashTable(int tableSize);
    void Insert(DataType record);
    DataType *Find(KeyType key);
    void Delete(DataType *pos);

private:
    vector< vector<DataType> > table;
};

#include "hashtable.cpp"

#endif // _hashtable_h_

