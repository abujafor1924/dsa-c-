#include <iostream>
#include <string>
using namespace std;

int main() {
    // DECLARE a character array with capacity for 100 characters
    // This array will store the user input characters
    char sentence[100];  

    // READ the first character from user input using cin.get()
    // cin.get() reads a single character including whitespace (unlike cin >> which skips whitespace)
    char tamp = cin.get();  
    
    // INITIALIZE length counter to 1
    // Starting at 1 because we already read the first character
    // NOTE: This creates an off-by-one error - actual character count will be len-1
    int len = 1;  

    // LOOP until newline character is encountered
    // COMMENTED OUT: while(tamp != '#') - This was the previous version that stopped at # character
    // CURRENT: while(tamp != '\n') - This stops when user presses ENTER key
    // DIFFERENCE: '#' stops at specific character, '\n' stops at end of line
    while(tamp != '\n') {   
        // STORE the current character in the array
        // sentence[len] = tamp - stores current character at position 'len'
        // len++ - increments the length counter after storing (post-increment)
        sentence[len++] = tamp; 

        // COMMENTED OUT: len++; - This was separate increment (now combined in sentence[len++])
        // COMMENTED OUT: cout << tamp; - This was echoing each character as it was read (now removed)

        // READ the next character from input
        // cin.get() continues reading character by character from input stream
        // It reads ALL characters including spaces, tabs, and eventually the newline
        tamp = cin.get();  
    }
    
    // PRINT a newline after the input loop ends
    // This creates visual separation between input and output
    cout << endl;  
    
    // ADD null terminator at the end of the string
    // Null terminator '\0' marks the end of valid string data in C-style strings
    // Essential for proper string printing and manipulation
    sentence[len] = '\0'; 
    
    // OUTPUT the length of the string as counted by our program
    // WARNING: This shows len which started at 1, so actual characters = len-1
    cout << "Length of the string: " << len << endl;
    
    // OUTPUT the size of the array in bytes
    // sizeof(sentence) returns total memory allocated: 100 chars × 1 byte each = 100 bytes
    cout << "Size of the array: " << sizeof(sentence) << endl;
    
    // OUTPUT the size of the array in number of elements
    // sizeof(sentence)/sizeof(char) calculates capacity: 100 bytes ÷ 1 byte per char = 100 elements
    cout << "Size of the string: " << sizeof(sentence)/sizeof(char) << endl;
    
    // OUTPUT the actual string content stored in the array
    // WARNING: This prints from sentence[0] which contains garbage value (never initialized)
    // Then continues printing actual data from sentence[1] to sentence[len-1]
    // The garbage character at start appears as � or some random symbol
    cout << sentence << endl;

    // END program with success status (return 0)
    return 0;
}