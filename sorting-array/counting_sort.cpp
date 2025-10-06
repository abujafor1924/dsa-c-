#include <iostream>
#include <vector>
using namespace std;

void counting_sort(int arr[], int n) {
    int max_val = -1;
    for (int i = 0; i < n; i++) {
       max_val = max(max_val, arr[i]);
}

    vector<int> freq(max_val + 1, 0);

    for (int i = 0; i < n; i++) {
        freq[arr[i]]++;
    }

    int index = 0;
    for (int i = 0; i <= max_val; i++) {
        while (freq[i] > 0) {
            arr[index++] = i;
            freq[i]--;
        }
    }
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    counting_sort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}