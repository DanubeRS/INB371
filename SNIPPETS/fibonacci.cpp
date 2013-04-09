/*
    Fibonacci

    A Simple program which uses the idea of recursive method calling to calculate the Fibonacci sequence of a valid integer

    v0.1
    ====
    -Initial creation

*/
#include <iostream>

using namespace std;

//Function Prototypes
int Fibonacci (int n);

int main()
{


    //Inform the user of the program:
    cout << "================================" << endl;
    cout << "|           Fibonacci          |" << endl;
    cout << "================================" << endl;
    cout << "|    (c)  Daniel Park 2013     |" << endl;
    cout << "|     ***INB371_SNIPPETS***    |" << endl;
    cout << "================================" << endl << endl;

    int factorial;

    int n = 1;


    while (true)
    {
        cout << "Sequence step " << n << " is: ";
        cout << Fibonacci(n) << endl;
        n++;
    }

    return  0;

}

int Fibonacci (int n)
{
    if (n < 2)
    {
        return n;
    }
    else
    {
        return Fibonacci(n - 1) + Fibonacci(n - 2);
    }
}
