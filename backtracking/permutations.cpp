#include <iostream>
using namespace std;


//permutations of r items from n items
// nPr = n! / (n-r)! 
// Generate all permutations of a given string using backtracking

void permutationsHelper(string &s, int index) {
    if (index == s.size() - 1) {
        cout << s << endl;
        return;
    }
    for (int i = index; i < s.size(); i++) {
        swap(s[index], s[i]);
        permutationsHelper(s, index + 1);
        swap(s[index], s[i]); // backtrack
    }
}

void generatePermutations(string s) {
    permutationsHelper(s, 0);
}

int main() {
    string s = "ABC";
    generatePermutations(s);
    return 0;
}