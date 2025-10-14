#include <iostream>
using namespace std;

int countWays(int n) {
    if (n <= 3) return 1;
    if (n == 4) return 2;
    
    int dp[n+1];
    // বেস কেস সেটআপ
    dp[0] = dp[1] = dp[2] = dp[3] = 1;
    dp[4] = 2;
    
    // ডিপি টেবিল পূরণ
    for (int i = 5; i <= n; i++) {
        dp[i] = dp[i-1] + dp[i-4];
    }
    
    return dp[n];
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    cout << "Number of ways: " << countWays(n) << endl;
    return 0;
}