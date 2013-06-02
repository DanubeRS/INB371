#include <cstddef>
#include "hashtable.h"
#include "record.h"

#ifdef _hashtable_h_
template <typename KeyType, typename DataType>
HashTable<KeyType, DataType>::HashTable() {
}

template <typename KeyType, typename DataType>
HashTable<KeyType, DataType>::HashTable(int tableSize) {
    table.resize(tableSize);
}

template <typename KeyType, typename DataType>
void HashTable<KeyType, DataType>::Insert(DataType record) {
    int index = record.GetHash(table.size());
    table[index].push_back(record);
}

template <typename KeyType, typename DataType>
DataType *HashTable<KeyType, DataType>::Find(KeyType key) {
    DataType tempRecord;
    tempRecord.SetKey(key);
    int index = tempRecord.GetHash(table.size());
    for (unsigned int i = 0; i < table[index].size(); i++)
        if (table[index][i].GetKey() == key)
            return &table[index][i];
    return NULL;
}

template <typename KeyType, typename DataType>
void HashTable<KeyType, DataType>::Delete(DataType *pos) {
    if (pos == NULL)
        return;
    int index = pos->GetHash(table.size());
    int i = 0;
    while (&table[index][i] != pos && i < table[index].size())
        i++;
    for (int j = 1; j < table[index].size() - 1; j++)
        table[index][j] = table[index][j + 1];
    table[index].pop_back();
}

//Exercise added implementations

/*
    This method counts the total number of records. As some collisions may occour, this method iterates through all 2D vector entries and increments the total count by the size of the correlating vector entry.
 */
template <typename KeyType, typename DataType>
int HashTable<KeyType, DataType>::CountRecords() {

    int numberOfRecords = 0;

    //Create an iterable loop using the iterability of the C++STL vector<T> class
    for (typename vector<vector <DataType> >::iterator iter_t = table.begin(); iter_t != table.end(); iter_t++) {

        numberOfRecords += iter_t.size();
    }

    return numberOfRecords;
}

/*
    This mehtod counts the number of buckets containing multiple records. It does this by iterating through each 2D vector entry, and incrementing by a corresponding amount if the size of that positional vector is nonempty, and greater than one.
 */
template <typename KeyType, typename DataType>
int HashTable<KeyType, DataType>::CountCollisions() {

    int numberOfCollisions = 0;

    //Create an iterable loop using the iterability of the C++STL vector<T> class
    for (typename vector< vector<DataType> >::iterator iter_t = table.begin(); iter_t != table.end(); iter_t++) {

        if (iter_t->size() > 0) {

            //Collisions occour when there is data in the cell, but there is more than one entry.
            numberOfCollisions += iter_t->size() - 1;
        }
    }

    return numberOfCollisions;
}

/*
    This method traverses the entire hashtable, and probes each bucket for multiple entries. If the bucket contains a number of entries larger than the current amount calculated, the bucket count is increased, and returned once the entire structure has been iterated through
 */
template <typename KeyType, typename DataType>
int HashTable<KeyType, DataType>::LargestBucket() {

    //As before iteratre through the 2D vector, and check bucket sizes. Only increase the count if the current bucket is larger than the rest
    int largestBucket = 0;

    //Create an iterable loop using the iterability of the C++STL vector<T> class
    for (typename vector< vector< DataType> >::iterator iter_t = table.begin(); iter_t != table.end(); iter_t++) {

        if (iter_t->size() > largestBucket) {
            largestBucket = iter_t->size();
        }
    }

    return largestBucket;

}

#endif
