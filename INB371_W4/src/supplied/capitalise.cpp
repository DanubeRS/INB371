/*
 * File: capitalise.h
 * Implements the Capitalise function as described below.
 */

#include <iostream>
#include <cctype>

using namespace std;

/* Function Prototypes */


int main() {
    
    // testing - do not alter
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


