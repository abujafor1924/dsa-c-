#include <bits/stdc++.h>
using namespace std;

int main()
{
  char a[100] = "apple";
     char b[100];
     cout << strlen(a) << endl; // 5

     strcpy(b, a); // copy a to b
     cout << b << endl; // apple
     cout << strlen(b) << endl; // 5
     cout << strlen(a) << endl; // 5
     cout << strcmp(a, b) << endl; // 0, a and b are equal
     cout << strcmp(a, "banana") << endl; // negative value, a is less than banana
     cout << strcmp("banana", a) << endl; // positive value, banana is greater than a

     char web[]="www";
     char domain[]="example.com";

     strcpy(b,strcat(web,domain)); // concatenate web and domain, then copy to b
     cout << b << endl; // wwwexample.com
     cout << strlen(b) << endl; // 15
     cout << strlen(web) << endl; // 15, web is modified after strcat
     cout <<strcmp(web,b) << endl; // 0, web and b are equal
     cout <<strcmp(web,"wwwexample.com") << endl; // 0, web and "wwwexample.com" are equal
     cout <<strcmp("WWWexample.com",web) << endl; // negative value, "WWWexample.com" is less than web

     return 0;
}