#ifndef _random_h
#define _random_h

class Random
{
public:
    Random();
    ~Random();
    int RandomInteger(int low, int high);

private:
    void Randomise();

};
#endif
