#include<bits/stdc++.h>
using namespace std;


int main() {
    int x;
    cin >> x;
    if ((x & (x - 1)) == 0) {
        cout << "Power of 2" << endl;
    } else {
        cout << "Not a Power of 2" << endl;
    }
    return 0;
}