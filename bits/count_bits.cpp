#include<bits/stdc++.h>
using namespace std;

// Method 1: Normal approach - check each bit
int countSetBits(int n) {
    int count = 0;
    while (n) {
        count += (n & 1);  // Check last bit
        n >>= 1;           // Right shift
    }
    return count;
}

// Method 2: Optimized hack approach
int count_bits_hack(int n) {
    int ans = 0;
    while (n > 0) {
        n = n & (n - 1);  // Clear the least significant set bit
        ans++;
    }
    return ans;
}

int main() {
    int x;
    cin >> x;
    cout << "Number of set bits in " << x << " is: " << countSetBits(x) << endl;
    cout << "Number of set bits in " << x << " (hack): " << count_bits_hack(x) << endl;
    return 0;
}