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

#endif
