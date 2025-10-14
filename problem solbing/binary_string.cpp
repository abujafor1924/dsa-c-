#include <iostream>
using namespace std;


int countBinaryStrings(int n) {
    if (n == 0) return 1; // empty string
    if (n == 1) return 2; // "0" or "1"
    
    int prevPrev = 2; // f(1)
    int prev = 3;     // f(2)
    int current;
    
    for (int i = 3; i <= n; i++) {
        current = prev + prevPrev;
        prevPrev = prev;
        prev = current;
    }
    
    return prev;
}

int main() {
    int N;
    cin >> N;
    
    cout << countBinaryStrings(N) << endl;
    
    return 0;
}