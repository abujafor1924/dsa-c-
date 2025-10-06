#include <iostream>
using namespace std;



void bubbleSort(int arr[], int n)
{
     int i, j, temp;
     bool swapped;
     for (i = 0; i < n - 1; i++)
     {
          swapped = false;
          for (j = 0; j < n - i - 1; j++)
          {
               if (arr[j] > arr[j + 1])
               {
                    temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swapped = true;
               }
          }
          if (swapped == false)
               break;
     }
}

int main()
{
     int arr[] = {64, 34, 25, 12, 22, 11, 90};
     int n = sizeof(arr) / sizeof(int);
     bubbleSort(arr, n);
     cout << "Sorted array: \n";
     for (int i = 0; i < n; i++)
     {

          cout << arr[i] << " ";
     }
     cout << endl;
     return 0;
}