#ifndef _record_h
#define _record_h

#include <string>

using namespace std;

class Record {
public:
    Record();
    Record(string, string);
    string GetKey();
    string GetNumber();
    void SetKey(string);
    void SetNumber(string);
    unsigned int GetHash(int M);
private:
    string name;
    string number;
};

#endif // _record_h
