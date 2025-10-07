#include <iostream>
using namespace std;

int main() {
   
     string str = "Hello, World!";
     cout << str << endl; // Output the string
     cout << "Length: " << str.length() << endl; // Output the length of the string
     str += " Welcome to C++ programming."; // Concatenate another string
     cout << str << endl; // Output the modified string
     cout << "Length: " << str.length() << endl; // Output the new length
    
    return 0;
}