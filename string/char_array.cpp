#include <iostream>
#include<cstring>
using namespace std;

int main() {
   char arr[]= "abcdefghig";            //{'a','b','c','d','e','\0'};
   cout << arr << endl; // prints the string until null terminator
   cout << "Array: " << strlen(arr) << endl;  // strlen counts characters until null terminator,number of visible characters
   cout << "String: " << sizeof(arr) << endl; // +1 for null terminator, sizeof counts all elements in the array

char b[100];
cin>>b;
cout<<b<<endl;
//cout<<strlen(b)<<endl;
//cout<<sizeof(b)<<endl; //100
//   cout<<sizeof(arr)<<endl; //10
//   cout<<strlen(arr)<<endl; //9
//   cout<<sizeof(arr)/sizeof(char)<<endl; //10
//   cout<<sizeof(b)/sizeof(char)<<endl; //100
//   cout<<sizeof(b)/sizeof(b[0])<<endl; //100
//   cout<<sizeof(arr)/sizeof(arr[0])<<endl; //10
//   cout<<sizeof(b)/sizeof(b[1])<<endl; //100
//   cout<<sizeof(arr)/sizeof(arr[1])<<endl; //10
//   cout<<sizeof(b)/sizeof(char)<<endl; //100
//   cout<<sizeof(arr)/sizeof(char)<<endl; //10
//   cout<<sizeof(b)/sizeof(b[2])<<endl; //100
//   cout<<sizeof(arr)/sizeof(arr[2])<<endl; //10           

//    int n=sizeof(arr)/sizeof(char);
  // cout << "Length of the array: " << n-1 << endl; // Exclude null terminator
   return 0;
}