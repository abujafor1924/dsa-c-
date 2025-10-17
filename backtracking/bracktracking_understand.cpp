#include <iostream>
using namespace std;

void binaryStrings(int *arr, int i, int n) {
    if(i == n) {
        for(int j = 0; j < n; j++) {
            cout << arr[j] << " ";
        }
        cout << endl;
        return;
    }
    
    // 0 বসানো
    arr[i] = 0;
    binaryStrings(arr, i + 1, n);
    
    // 1 বসানো  
    arr[i] = 1;
    binaryStrings(arr, i + 1, n);
}

int main() {
    int n;
    cout << "Enter the size: ";
    cin >> n;
    int *arr = new int[n];
    binaryStrings(arr, 0, n);
    delete[] arr;
    return 0;
}