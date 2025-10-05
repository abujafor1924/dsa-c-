#include <iostream>
using namespace std;

void reverse_array(int arr[], int size)
{
     int s=0;
     int e=size-1;
     while (s<e)
     {
        swap(arr[s],arr[e]);
        s++;
        e--;     
     }

}

int main()
{

     int arr[]={2,4,6,8,10};
     int size=sizeof(arr)/sizeof(arr[0]);
     for (int i=0;i<size;i++)
     {
         cout<<arr[i]<<" ";
     }
     cout<<endl;

     reverse_array(arr,size);
     cout<<"Reversed array: ";
     for (int i=0;i<size;i++)
     {
        cout<<arr[i]<<" ";
     }
     cout<<endl;
    
    return 0;
}
