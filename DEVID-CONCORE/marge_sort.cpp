#include <bits/stdc++.h>
using namespace std;

void merge(vector<int>& arr, int s, int e) 
     {
          int i = s;
          int mid = s + (e - s) / 2;
          int j = mid + 1;
          vector<int> temp;
          while (i <= mid && j <= e) 
          {
               if (arr[i] <= arr[j]) 
               {
                    temp.push_back(arr[i]);
                    i++; 
               }
               else
               {
                    temp.push_back(arr[j]);
                    j++;
               }
          }
          while (i <= mid)
          {
               temp.push_back(arr[i]);
               i++;
          }
          while (j <= e)
          {
               temp.push_back(arr[j]);
               j++;
          }
          for (int k = 0; k < temp.size(); k++)
          {
               arr[s + k] = temp[k];
          }
     }

void mergeSort(vector<int>& arr, int s, int e) 
     {
          if (s >= e)
               return;
          int mid = s + (e - s) / 2;
          mergeSort(arr, s, mid); //
          mergeSort(arr, mid + 1, e);
          merge(arr, s, e);
     }

int main() 
     {
          vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
          int n = arr.size();
          cout << "Original array: ";
          for (int i = 0; i < n; i++)
               cout << arr[i] << " ";
          cout << endl;

          mergeSort(arr, 0, n - 1);

          cout << "Sorted array: ";
          for (int i = 0; i < n; i++)
               cout << arr[i] << " ";
          cout << endl;

          return 0;
     }

// using namespace std;


// void merge(int arr[], int left, int mid, int right) {
//      // Find sizes of two subarrays to be merged
//     int n1 = mid - left + 1;
//     int n2 = right - mid;
// // Create temp arrays
//     int* L = new int[n1];
//     int* R = new int[n2];
// // Copy data to temp arrays L[] and R[]
//     for (int i = 0; i < n1; i++)
//         L[i] = arr[left + i];
//     for (int j = 0; j < n2; j++)
//         R[j] = arr[mid + 1 + j];
// // Merge the temp arrays back into arr[left..right]
//     int i = 0;
//     int j = 0;
//     int k = left;
// // Initial index of first sub-array
//     while (i < n1 && j < n2) {
//         if (L[i] <= R[j]) {
//             arr[k] = L[i];
//             i++;
//         } else {
//             arr[k] = R[j];
//             j++;
//         }
//         k++;
//     }
// // Copy the remaining elements of L[], if there are any
//     while (i < n1) {
//         arr[k] = L[i];
//         i++;
//         k++;
//     }
// // Copy the remaining elements of R[], if there are any
//     while (j < n2) {
//         arr[k] = R[j];
//         j++;
//         k++;
//     }
// // Free the allocated memory
//     delete[] L;
//     delete[] R;
// }

// void mergeSort(int arr[], int left, int right) {
//     if (left < right) {
//         int mid = left + (right - left) / 2;
// // Sort first and second halves
//         mergeSort(arr, left, mid);
//         mergeSort(arr, mid + 1, right);
// // Merge the sorted halves
//         merge(arr, left, mid, right);
//     }
// }

// int main() {
//     int arr[] = {38, 27, 43, 3, 9, 82, 10};
//     int arrSize = sizeof(arr) / sizeof(arr[0]);

//     cout << "Original array: ";
//     for (int i = 0; i < arrSize; i++)
//         cout << arr[i] << " ";
//     cout << endl;

//     mergeSort(arr, 0, arrSize - 1);

//     cout << "Sorted array: ";
//     for (int i = 0; i < arrSize; i++)
//         cout << arr[i] << " ";
//     cout << endl;

//     return 0;
// }