#include<iostream>
#include<vector>
using namespace std;

int main()
{

     vector<int> arr={1,2,3,4,5};

     //add more elements by push_back
     arr.push_back(6);
     arr.push_back(7);
     arr.push_back(8);

     //remove last element by pop_back
     arr.pop_back();
     arr.pop_back();

//for all elements
     for(auto it:arr)
     {
          cout<<it<<" ";
     }
     cout<<endl;

     //print all elements
     for(int i=0;i<arr.size();i++)
     {
          cout<<arr[i]<<" ";
     }
     cout<<endl;
//print size and capacity
     cout << "Size: " << arr.size() << endl;
     cout << "Capacity: " << arr.capacity() << endl;


     return 0;
}
