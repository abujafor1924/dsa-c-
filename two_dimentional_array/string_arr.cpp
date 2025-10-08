#include<iostream>
using namespace std;

int main(){


     char number[][10] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten"};

     for(int i=0; i<10; i++){
         cout<<number[i]<<endl;
     }
     return 0;
}