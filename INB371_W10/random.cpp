#include <cstdlib>
#include <ctime>

#include "random.h"

using namespace std;

Random::Random()
{
    Randomise();
}

Random::~Random()
{
    // leave empty
}

int Random::GetRandomInteger(int low, int high)
{
    double d = double(rand()) / (double(RAND_MAX) + 1);
    int k = int(d * (high - low  + 1));
    return low + k;
}

void Random::Randomise()
{
    srand(int(time(NULL)));
}
