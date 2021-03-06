#include <iostream>

using namespace std;

int GCD(int x, int y);

int main() {
	
	cout << "GCD(4, 9) = " << GCD(4, 9) << endl;
	cout << "GCD(4, 64) = " << GCD(4, 64) << endl;
	cout << "GCD(132, 242) = " << GCD(132, 242) << endl;
	cout << "GCD(9, 4) = " << GCD(9, 4) << endl;
	cout << "GCD(64, 4) = " << GCD(64, 4) << endl;
	cout << "GCD(242, 132) = " << GCD(242, 132) << endl;

	return 0;
}

int GCD(int x, int y) {

	//We need to figure out which number is smallest
	
	int small, large;
	if (x > y){
		small = y;
		large = x;
	} else {
		small = x;
		large = y;
	}

	//If evenly divisible
	if (large % small == 0){
		return small;
	} else {
		return GCD(large % small, small);
	}
}