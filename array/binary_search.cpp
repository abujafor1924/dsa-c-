#include <iostream>
using namespace std;


int binary_search(int arr[], int size, int target)
{
   int s=0;
   int e=size-1;
   while (s<=e)
   {
     int mid=(s+e)/2;
     if (arr[mid]==target)
     {
        return mid;
     }
     else if (arr[mid]>target)
     {
        e=mid-1;
     }
     else
     {
        s=mid+1;
     }
   }

   return -1;
   
}

int main()
{
     int arr[]={2,4,6,8,10,12,14,16,18};
     int size=sizeof(arr)/sizeof(arr[0]);
     int target;
     cout<<"Enter the element to search: ";
     cin>>target;
     int result=binary_search(arr,size,target);
     if (result!=-1)
     {
         cout<<"Element found at index: "<<result<<endl;
     }
     else
     {
         cout<<"Element not found"<<endl;
     }
     return 0;
}