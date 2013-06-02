#include <iostream>
#include "hashtable.h"
#include "record.h"
#include "random.h"

using namespace std;

int main() {

    HashTable<string, Record> words(5003);
    Random random;

    string word = "aaaa";
    for (int i = 0; i < 5000; i++) {
        for (int j = 0; j < 4; j++) {
            word[j] = (char)(((int)'a' + random.GetRandomInteger(0, 100) % 26));
        }
        words.Insert(Record(word, word));
    }

    cout << "num records    " << words.CountRecords() << endl;
    cout << "collisions     " << words.CountCollisions() << endl;
    cout << "largest bucket " << words.LargestBucket() << endl;

    return 0;
}