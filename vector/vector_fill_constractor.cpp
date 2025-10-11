#include<iostream>
#include<vector>
using namespace std;

int main()
{
     vector<int> arr(7, 10); // Fill constructor
     for(int i=0;i<arr.size();i++)
     {
          cout<<arr[i]<<" ";
     }
     cout<<endl;
     //add element at the end
     arr.push_back(20);
     arr.push_back(30);

     //remove last element
     arr.pop_back();

     //print the vector
     for(int i=0;i<arr.size();i++)
     {
          cout<<arr[i]<<" ";
     }
     cout<<endl;

     return 0;
}
