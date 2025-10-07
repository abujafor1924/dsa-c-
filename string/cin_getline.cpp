#include <iostream>
using namespace std;


int main() {
   char sentence[100];
     cout << "Enter a sentence: ";
     //  cin.getline(sentence, 100, '.');
     // cin.getline(sentence, 100, '#'); // custom delimiter
     // cin.getline(sentence, 100); // default delimiter is newline
     cin.getline(sentence, 100, '\n'); // explicit newline delimiter
     cout << "You entered: " << sentence << endl;
   return 0;
}