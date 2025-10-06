#include <iostream>
#include <algorithm>
using namespace std;

// user reverse or compare function
bool compare(int a, int b) {
    return a > b; // For ascending order
    // return a > b; // For descending order
}    
int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Using built-in sort function
//     sort(arr, arr + n); // For ascending order
     sort(arr, arr + n, greater<int>()); // For ascending order
//     sort(arr, arr + n, compare); // For ascending order
    // reverse(arr, arr + n); // To sort in descending order

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}