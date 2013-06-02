#include <iostream>
#include <string>
#include "hashtable.h"

using namespace std;

int main() {

    HashTable<string, Record> phoneBook(50);
    phoneBook.Insert(Record("Malcolm", "81923"));
    phoneBook.Insert(Record("Malcolm Corney", "81923"));
    phoneBook.Insert(Record("Joe Bloggs", "12345"));

    Record *rec = phoneBook.Find("Malcolm");
    if (rec != NULL)
        cout << rec->GetKey() << " - " << rec->GetNumber() << endl;
    phoneBook.Delete(phoneBook.Find("Malcolm"));
    return 0;
}
