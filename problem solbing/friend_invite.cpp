

#include <iostream>
using namespace std;

int countFriendsPairings(int n) {
    if (n == 0) return 1;
    if (n == 1) return 1;
    if (n == 2) return 2;
    
    return countFriendsPairings(n - 1) + (n - 1) * countFriendsPairings(n - 2);
}

int main() {
    int n;
    cout << "Enter number of friends: ";
    cin >> n;
    cout << "Total ways: " << countFriendsPairings(n) << endl;
    return 0;
}