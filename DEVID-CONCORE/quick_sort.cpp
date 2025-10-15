#include <iostream>
#include <vector>
using namespace std;

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];  // Choose last element as pivot
    int i = low - 1;        // Index of smaller element
    
    for (int j = low; j < high; j++) {
        // If current element is smaller than or equal to pivot
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;  // Return partitioning index
}

void quick_sort(vector<int>& arr, int low, int high) {
    if (low < high) {
        // pi is partitioning index, arr[pi] is now at right place
        int pi = partition(arr, low, high);
        
        // Recursively sort elements before and after partition
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}

void printArray(const vector<int>& arr) {
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << "Original array: ";
    printArray(arr);

    quick_sort(arr, 0, n - 1);

    cout << "Sorted array: ";
    printArray(arr);

    return 0;
}