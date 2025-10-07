#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int n;
    cout << "Enter number of strings: ";
    cin >> n;
    cin.get(); // consume newline
    
    char sentence[1000];
    char largest[1000] = ""; // PROPERLY initialized
    int largest_len = 0;

   while (n--)
   {
     cin.getline(sentence, 1000);
     int len = strlen(sentence);
     if (len > largest_len) {
         largest_len = len;
         strcpy(largest, sentence);
     }
   }
   
    
    cout << "Largest string: '" << largest << "'" << endl;
//     cout << "Length: " << largest_len << endl;
    
    return 0;
}