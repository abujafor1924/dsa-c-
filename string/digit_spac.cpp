#include <iostream>
using namespace std;

int main() {
   char ch;
   cout << "Enter a string: ";
 cin.get(ch);
 int alpha=0;
 int space=0;
 int digit=0;
   while (ch != '\n') {
    if (ch >= '0' && ch <= '9') {
        digit++;
    } else if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
        alpha++;
    } else if (ch == ' ' || ch == '\t') {
        space++;
    }
    cin.get(ch);
   }
   cout << "Number of spaces: " << space << endl;
   cout << "Number of digits: " << digit << endl; 
   cout << "Number of alphabetic characters: " << alpha << endl;
   return 0;
}