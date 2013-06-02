#include "record.h"

Record::Record() {
}

Record::Record(string name, string number) {
    this->name = name;
    this->number = number;
}

string Record::GetKey() {
    return name;
}

string Record::GetNumber() {
    return number;
}

void Record::SetKey(string key) {
    name = key;
}

void Record::SetNumber(string number) {
}

unsigned int Record::GetHash(int M) {
    string key = GetKey();
    unsigned int index = 1;
    unsigned int prime = 31;
    for (unsigned int i = 0; i < key.length(); i++) {
        index = prime * index + (unsigned int) key[i];
    }
    return index % M;
}
