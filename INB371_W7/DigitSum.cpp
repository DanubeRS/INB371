#include <iostream>

using namespace std;

int DigitSum(int n);

int main()
{

    cout << "Sum of digits in 1 = " << DigitSum(1) << endl;
    cout << "Sum of digits in 12 = " << DigitSum(12) << endl;
    cout << "Sum of digits in 123 = " << DigitSum(123) << endl;
    cout << "Sum of digits in 1234 = " << DigitSum(1234) << endl;
    cout << "Sum of digits in 12345 = " << DigitSum(12345) << endl;
    cout << "Sum of digits in 123456 = " << DigitSum(123456) << endl;
    cout << "Sum of digits in 1729 = " << DigitSum(1729) << endl;
    cout << "Sum of digits in 9271 = " << DigitSum(9271) << endl;

    return 0;
}

/*
    Takes an integer and returns the sum of its digits;
 */
int DigitSum(int n)
{

    int currentDigit = n % 10;

    //Check if we have only 1 digit.
    if (n >= 10)
    {
        return currentDigit + DigitSum((n - currentDigit) / 10);
    }
    else
    {
        return currentDigit;
    }


}