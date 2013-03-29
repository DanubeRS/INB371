/*
 * File:  reverseString.cpp
 * Prompts the user for a string and reverses it using a CharStack
 */

#include <string>
#include <iostream>
#include "charStack.h"

using namespace std;

/* Reverses a string */
string reverse(string);

int main()
{

    string text;
    cout << "Enter a string without spaces: ";
    cin >> text;

    cout << text << " reversed is " << reverse(text) << endl;

    return 0;
}

/* Reverses a string */
string reverse(string in)
{

    CharStack normalString;
    for (char & c : in)
    {
    	//DEBUG
    	//cout << endl << "adding char " << c;
        normalString.push(c);

    }

    string reverseString;
    //DEBUG
    //cout << endl << "Stack is " << normalString.size() << " long." << endl;

    int stackSize = normalString.size();

    for (int i = 0; i < stackSize; i++){
    	reverseString.append(1, normalString.peek());
    	normalString.pop();
    }

    return reverseString;
}
