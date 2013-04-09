/*
    Factorial

    A Simple program which uses the idea of recursive method calling to calculate the factorial of a valid integer

    v0.1
    ====
    -Initial creation

*/
#include <iostream>

using namespace std;

//Function Prototypes
int Factorial (int n);

int main()
{


    //Inform the user of the program:
    cout << "================================" << endl;
    cout << "|           Factorial          |" << endl;
    cout << "================================" << endl;
    cout << "|    (c)  Daniel Park 2013     |" << endl;
    cout << "|     ***INB371_SNIPPETS***    |" << endl;
    cout << "================================" << endl << endl;

    int factorial;

    cout << "Please enter an int: \n\t";

    cin >> factorial;

    cout << "Number is : " << Factorial(factorial) << endl;

    return  0;
    
}

int Factorial (int n){
    if (n == 0){
        return 1;
    } else {
        return n * Factorial(n-1);
    }
}
