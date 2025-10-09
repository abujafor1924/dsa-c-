#include<iostream>
using namespace std;


void watch_video(int * viewsptr)
{
   *viewsptr = *viewsptr + 1; // incrementing the value at the address pointed to by viewsptr
}

int main()
{
    int videoID = 123; // some video ID
   int views = 0; // initial views
   cout << "Video ID before function call: " << videoID << endl;
   cout << "Views before function call: " << views << endl;
   watch_video(&views); // passing the address of views
   cout << "Video ID after function call: " << videoID << endl; // videoID remains unchanged
   cout << "Views after function call: " << views << endl; // views should be incremented
   return 0;
}