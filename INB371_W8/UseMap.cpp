#include <iostream>
#include "Map.h"

using namespace std;

int main() {
    class Map wordFreq;
    wordFreq.Put("Hello", 1);
    wordFreq.Put("Apple", 1);
    wordFreq.Put("Zoo", 1);
    wordFreq.Put("Goodbye", 1);

    int freq = 0;
    if (wordFreq.ContainsKey("Hello")) {
        freq = wordFreq.Get("Hello");
    }
    cout << "Hello value = " << wordFreq.Get("Hello") << endl;
    wordFreq.Put("Hello", ++freq);
    cout << "Hello value = " << wordFreq.Get("Hello") << endl;
    wordFreq.Put("Hello", ++freq);
    cout << "Hello value = " << wordFreq.Get("Hello") << endl;

    cout << wordFreq.ContainsKey("Hello") << endl;
    cout << wordFreq.ContainsKey("Goodbye") << endl;

    wordFreq.Remove("Hello");
    cout << wordFreq.ContainsKey("Hello") << endl;
    cout << wordFreq.ContainsKey("Goodbye") << endl;

    wordFreq.Traverse();


    return 0;
}
