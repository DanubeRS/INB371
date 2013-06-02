#ifndef _random_h
#define _random_h

class Random
{
public:
    Random();
    ~Random();
    int GetRandomInteger(int low, int high);
    void Randomise();

private:
//    void Randomise();

};
#endif
