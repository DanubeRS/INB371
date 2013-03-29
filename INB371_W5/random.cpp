/*
    Implementation file attached to random.h
 */

//Header include
#include "random.h"
//Used for inplementation

#include <cstdlib>
#include <ctime>
    #include <cstdio>

//The good ol' std namespace
using namespace std;


using namespace std;

/*
    Constructor for a new Random instance. Will call the randomize()
    method prior to returning the reference.
 */
Random::Random()
{
    Randomize();
}
/*
    Destructor for Random class instance. Not yet implemented.
 */
Random::~Random()
{
    //TO BE IMPLEMENTED
}
/*
 * Function: RandomInteger
 * Usage: n = RandomInteger(low, high);
 * ------------------------------------
 * This function returns a random integer in the range low to high,
 * inclusive.
 */
int Random::RandomInteger(int low, int high)
{
    double d = double(rand()) / (double(RAND_MAX) + 1);
    int k = int(d * (high - low  + 1));
    return low + k;
}

/*
 * Function: RandomReal
 * Usage: d = RandomReal(low, high);
 * ---------------------------------
 * This function returns a random real number in the half-open
 * interval [low .. high), meaning that the result is always
 * greater than or equal to low but strictly less than high.
 */
double Random::RandomReal(double low, double high)
{
    double d = double(rand()) / (double(RAND_MAX) + 1);
    return low + d * (high - low);
}

/*
 * Function: RandomChance
 * Usage: if (RandomChance(p)) . . .
 * ---------------------------------
 * The RandomChance function returns true with the probability  indicated by p,
 * which should be a floating-point number between 0 (meaning never) and 1
 * (meaning always). Calling RandomChance(.30) returns true 30 percent of the time.
 */
bool Random::RandomChance(double p)
{
    return RandomReal(0, 1) < p;
}

/*
 * Function: Randomize
 * Usage: Randomize();
 * -------------------
 * This function initializes the random-number generator so that
 * its results are unpredictable. If this function is not called,
 * the other functions will return the same values on each run.
 */
void Random::Randomize()
{
    srand(int(time(NULL)));
}