#include<iostream>
using namespace std;

string compress(string str)
{
    int n = str.length();
    string output = "";

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        // Count consecutive duplicate characters
        while (i < n - 1 && str[i] == str[i + 1])
        {
            count++;
            i++;
        }
        output += str[i];
        output += to_string(count);
    }
    
    // Return original string if compressed version isn't smaller
    if (output.length() >= str.length())
    {
        return str;
    }
    return output;
}

int main()
{
    string s1 = "aaabbccccd";
    cout << "Original: " << s1 << endl;
    cout << "Compressed: " << compress(s1) << endl;
    cout << endl;

    string s2 = "abcd";
    cout << "Original: " << s2 << endl;
    cout << "Compressed: " << compress(s2) << endl;
    
    return 0;
}