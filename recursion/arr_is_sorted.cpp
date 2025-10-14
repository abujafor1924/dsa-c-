#include <iostream>
using namespace std;

bool isSorted(int arr[], int n) {
    if (n == 1) return true;
    return (arr[n - 1] >= arr[n - 2]) && isSorted(arr, n - 1);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(int);
    if (isSorted(arr, n))
        cout << "Array is sorted." << endl;
    else
        cout << "Array is not sorted." << endl;
    return 0;
}