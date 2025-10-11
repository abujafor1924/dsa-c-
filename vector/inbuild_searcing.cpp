#include <bits/stdc++.h>
using namespace std;


int main()
{

     vector<int> arr={1,2,3,4,5};
     int key=4;
     //searching key in vector
     vector<int>::iterator it=find(arr.begin(),arr.end(),key); // using find algorithm, returns iterator to the element if found, otherwise returns arr.end()
     if(it!=arr.end())
     {
          cout<<"Element found: "<<*it<<endl;
     }
     else
     {
          cout<<"Element not found"<<endl;
     }
     return 0;
}