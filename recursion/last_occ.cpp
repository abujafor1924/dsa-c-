#include <iostream>
using namespace std;

int lastOcc(int arr[], int n, int key)
{
    if (n == 0)
        return -1;

    int i = lastOcc(arr + 1, n - 1, key);

    if (i == -1)
    {
        if (arr[0] == key)
            return 0;
        else
            return -1;
    }
    return i + 1;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key;
    cin >> key;

    int index = lastOcc(arr, size, key);
    if (index != -1)
        cout << "Last occurrence of " << key << " is at index " << index << endl;
    else
        cout << key << " not found in the array." << endl;

    return 0;
}
