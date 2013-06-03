/*
    Timer class for timing processing time. Pity the bloody thing doesnt fare so well for *nix based systems...
    see: http://stackoverflow.com/questions/9871071/why-c-clock-returns-0
 */

#include <time.h>
#include <iostream>

class Timer {
public:
    /*
        Constructs an default
     */
    Timer();

    /*
        Destructor
     */
    ~Timer();

    /*
        Stopwatch functions
     */
    void Start();
    void Stop();
    void Split();


private:
    clock_t start, end;

    /*
        Calculates the time taken in ms
     */
    float CalcTime(clock_t t);

    /*
        Calculates the time taken in CPU cycles
     */
    double CalcTicks(clock_t t);
};

/*
    Constructor
 */
Timer::Timer() {
    start = 0;
    end = 0;
}

Timer::~Timer() {
    //Not required
}

void Timer::Start() {
    start = clock();
}

void Timer::Stop() {
    this->end = clock();
    std::cout << "Time taken: " << CalcTime(end) << "(" << CalcTicks(end) << " ticks)" << std::endl;
}

void Timer::Split(){
    std::cout << "Time taken: " << CalcTime(clock()) << "(" << CalcTicks(clock()) << " ticks)" << std::endl;
}

double Timer::CalcTicks(clock_t t){
	return (t - start);
}

float Timer::CalcTime(clock_t t){
	return (float) (CalcTicks(t) / CLOCKS_PER_SEC);
}