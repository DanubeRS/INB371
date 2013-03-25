/*
    Heads and Tails (c) Daniel Park 2013

    A program which uses the interfacing features of c++ to generate a heads-or-tails
    probability simulation.

    v0.1
    ====
    -Initial creation (Provided by Malcom Corney)

    v1.0
    ====
    -Completed aplliaction

*/

#include <iostream>
#include <cctype>

using namespace std;

/* Function Prototypes */
string Capitalise(string in);

int main()
{

    //Inform the user of the program:
    cout << "================================" << endl;
    cout << "|        Heads or Tails        |" << endl;
    cout << "================================" << endl;
    cout << "|    (c)  Daniel Park 2013     |" << endl;
    cout << "|     ***INB371_S1_W3_Q5***    |" << endl;
    cout << "================================" << endl << endl;

    // testing - do not alter (Provided by Malcom Corney)
    cout << Capitalise("BOOLEAN") << endl;
    cout << Capitalise("boolean") << endl;
    cout << Capitalise("the first word in this sentence should be capitalised.") << endl;
    cout << Capitalise("THE FIRST WORD IN THIS SENTENCE SHOULD BE CAPITALISED.") << endl;
    cout << Capitalise("") << endl;
    cout << Capitalise("A") << endl;
    cout << Capitalise("a") << endl;
    cout << Capitalise("21 - 13 + 45 * 6 = 278") << endl;
    cout << Capitalise("21 days ago") << endl;
    cout << Capitalise("21 DAYS AGO") << endl;
    cout << Capitalise("This sentence should not be changed.") << endl;
    cout << Capitalise("thIS SenTence SHould bE cHANGED.") << endl;

    return 0;
}

/*
 * Converts the input string as follows: If the first character of the string is
 * alphabetic it is capitalised if it is not already a capital.  If other characters
 * in the string are in upper case, the are converted to lower case.  Non-alphabetic
 * characters are not altered.
 */

string Capitalise(string in)
{
    //Convert ONLY the first character if it a letter, and lower
    string outString = in;
    if (isalpha(outString[0]) && !isupper(outString[0]))
    {
        outString[0] = (char)toupper(outString[0]);
    }

    //Capialise from the first letter onwards, if alpha and lower.
    int i = 1;  //Start the string iterator
    while (outString[i])
    {
        if (isalpha(outString[i]) && isupper(outString[i]))
        {
            outString[i] = (char)tolower(outString[i]);
        }

        i++;    //Next character

    }

    return outString;
}

