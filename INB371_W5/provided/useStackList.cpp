#include <iostream>

// Choose one
//#include "intstack.h"
#include "intstacklist.h"

using namespace std;

int main() {

	IntStack stack;

	for (int i = 0; i < 10; i++) {
		stack.push(i);
	}

	for (int i = 0; i < 5; i++) {
	    cout << stack.peek() << endl;
	    stack.pop();
	}

	for (int i = 10; i < 15; i++) {
		stack.push(i);
	}

	for (int i = 0; i < 10; i++) {
	    cout << stack.peek() << endl;
	    stack.pop();
	}

	return 0;
}



