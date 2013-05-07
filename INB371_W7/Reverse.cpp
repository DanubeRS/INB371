/*
 * File: Rverese.cpp
 * Uses a recursive function to reverse a string.
 */
#include <iostream>
#include <string>

using namespace std;

string Reverse(string);

int main()
{
    cout << "'program' reversed is '" << Reverse("program") << "'" << endl;
    cout << "'' reversed is '" << Reverse("") <<  "'" << endl;
    cout << "'abcdefghijklmnopqrstuvwxyz' reversed is '" << Reverse("abcdefghijklmnopqrstuvwxyz") <<  "'" << endl;
    cout << "'a man a plan a canal panama'  reversed is '" << Reverse("a man a plan a canal panama") <<  "'" << endl;

    return 0;
}

/* Recursive function to reverse a string. */
string Reverse(string str)
{

	if (str.length() == 0) {
		return "";
	} else {
		return str[str.length() - 1] + Reverse(str.substr(0, str.length() - 1));
	}
}

