#include <iostream>
#include <string>
#include "GenericPriorityQueue.h"
#include "random.h"

using namespace std;

int main() {

    GenericPriorityQueue<string> pq;
    vector<string> words;

    /* Create some random four letter words and add to priority queue */
    Random random;
    string word = "aaaa";
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 4; j++) {
            word[j] = (char)(((int)'a' + random.GetRandomInteger(0, 100) % 26));
        }
        cout << "Adding " << word << endl;
        pq.Add(word);
        words.push_back(word);
    }

//    HeapSort(words);


    /* Empty the priority Queue by polling */
    while (!pq.IsEmpty()) {
        cout << pq.Poll() << endl;
    }

    return 0;
}
