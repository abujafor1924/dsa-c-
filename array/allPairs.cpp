#include <iostream>
using namespace std;

void allPairs(int arr[], int size)
{
    for (int i=0;i<size;i++)
    {
        for (int j=i+1;j<size;j++)
        {
            cout<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
        }
    }
}

int  main()
{
    int arr[] = {10,20,30,40,50,60};
    int size = sizeof(arr) / sizeof(arr[0]);
    allPairs(arr, size);
    return 0;
}