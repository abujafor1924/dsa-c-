#include <iostream>
using namespace std;

int firstOcc(int arr[], int size, int key)
{
    if (size == 0)
        return -1;

    if (arr[0] == key)
        return 0;

    int ans = firstOcc(arr + 1, size - 1, key);
    if (ans == -1)
        return -1;
    else
        return ans + 1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 2;

    int index = firstOcc(arr, size, key);
    if (index != -1)
        cout << "First occurrence of " << key << " is at index " << index << endl;
    else
        cout << key << " not found in the array." << endl;

    return 0;
}