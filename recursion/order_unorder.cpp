#include<iostream>
using namespace std;

void printIncreasing(int n) {
    if (n == 0) return;
    printIncreasing(n - 1);
    cout << n << " ";
}

void printDecreasing(int n) {
    if (n == 0) return;
    cout << n << " ";
    printDecreasing(n - 1);
}

int main() {
    int n = 5;
    cout << "Increasing order: ";
    printIncreasing(n);
    cout << endl;

    cout << "Decreasing order: ";
    printDecreasing(n);
    cout << endl;

    return 0;
}
