#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> pos(n+1);
    for(int i = 1; i <= n; i++){
        int x;
        cin >> x;
        pos[x] = i;
    }
    int m;
    cin >> m;
    long long a = 0, b = 0;
    for(int i = 0; i < m; i++){
        int x;
        cin >> x;
        a += pos[x];
        b += n - pos[x] + 1;
    }
    cout << a << " " << b << "\n"; 
     return 0;
}