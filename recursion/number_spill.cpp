#include <iostream>
using namespace std;

string spell[10] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

void printNumber(int n)
{
    // Base case
    if (n == 0)
        return;

    // Recursive case
    int lastDigit = n % 10;
    printNumber(n / 10);
    cout << spell[lastDigit] << " ";
}


int main()
{
    int number;
    cout << "Enter a number: ";
    cin >> number;

    if (number == 0)
        cout << spell[0] << endl; // Handle the case for 0 explicitly
    else
    {
        printNumber(number);
        cout << endl;
    }

    return 0;
}