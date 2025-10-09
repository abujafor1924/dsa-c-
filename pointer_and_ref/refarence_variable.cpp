#include<iostream>
using namespace std;

int main() {
    int a = 5;
    int& ref = a;  // reference variable

    ref++;  // incrementing the reference variable
    cout << "Value of a: " << a << endl;
    cout << "Value of ref: " << ref << endl;

    ref = 10;  // modifying the value using reference
    ref++;
    cout << "Value of a after modification: " << a << endl;
    cout << "Value of ref after modification: " << ref << endl;

    return 0;
}