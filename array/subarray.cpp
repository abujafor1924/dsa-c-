#include <iostream>
#include <climits>  // INT_MIN এর জন্য
using namespace std;

void subarray(int arr[], int size)
{
    int maxSum = arr[0];  // সঠিক নাম
    
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; j++)
        {
            int currsum = 0;
            
            // সাবঅ্যারের যোগফল 계산
            for (int k = i; k <= j; k++)
            {
                currsum += arr[k];
            }
            
            cout << "Subarray sum: " << currsum << endl;
            
            // সর্বোচ্চ যোগফল আপডেট
            if (currsum > maxSum)
            {
                maxSum = currsum;
            }
        }
    }
    
    // ফাইনাল রেজাল্ট একবার প্রিন্ট
    cout << "Final Max sum is: " << maxSum << endl;
}

int main()
{
    int arr[] = {1, 2, 3, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    subarray(arr, size);
    return 0;
}