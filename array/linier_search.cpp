#include <iostream>
using namespace std;

int linear_search_array(int arr[], int n, int key)
{
    for(int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;  // Return index if found
        }
    }
    return -1;  // Return -1 if not found
}

int main()
{
    int arr[] = {12, 43, 56, 7, 3, 4, 2};  // Added missing semicolon
    
    int n = sizeof(arr) / sizeof(int);
    
    int key;
    cin >> key;
    
    int index = linear_search_array(arr, n, key);
    
    if (index != -1)
    {
        cout << key << " is present at index " << index << endl;  // Fixed variable name
    }
    else
    {
        cout << key << " not found in this array" << endl;
    }
    
    cout << endl;
    return 0;
}