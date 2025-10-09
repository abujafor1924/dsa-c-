#include<iostream>
using namespace std;

int main() {
    int a = 5;
    int* p = &a;
    int y=10;
    int* q=&y;

    int z=11;

    int *ptr=&z;

    cout << "Address of a: " << &a << endl; // address of a
    cout << "Address stored in p: " << p << endl; // p holds the address of a
     cout << "Value pointed to by p: " << *p << endl; // dereferencing p to get the value of a

    cout << "Address of y: " << &y << endl; // address of y
    cout << "Address stored in q: " << q << endl; // q holds the address of y
    cout << "Value pointed to by q: " << *q << endl; // dereferencing q to get the value of y

    cout << "Address of z: " << &z << endl;
    cout << "Value pointed to by z: " << *(&z) << endl; // dereferencing &z to get the value of z
     cout << "Address stored in ptr: " << ptr << endl; // ptr holds the address of z
     cout << "Value pointed to by ptr: " << *ptr << endl;  // dereferencing ptr to get the value of z
     cout << "Value of ptr itself: " << &ptr << endl; // address of ptr

    return 0;
}