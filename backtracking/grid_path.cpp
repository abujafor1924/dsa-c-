#include <iostream>
using namespace std;

int  gridways(int i, int j, int m, int n)
{
    // Base case: If we reach the bottom-right corner, there's one way
    if (i == m - 1 && j == n - 1) return 1;

    // If we go out of bounds, there's no way
    if (i >= m || j >= n) return 0;

    // Move right and down
    return gridways(i + 1, j, m, n) + gridways(i, j + 1, m, n);
}


int main() {
    int m = 3, n = 3; // Grid size
    cout << "Number of ways to reach the bottom-right corner: " << gridways(0, 0, m, n) << endl;
    return 0;
}






// #include <bits/stdc++.h>
// using namespace std;

// bool isValid(int x, int y, vector<vector<char>> &grid, vector<vector<bool>> &visited) {
//     int m = grid.size();
//     int n = grid[0].size();
//     return (x >= 0 && y >= 0 && x < m && y < n && grid[x][y] != 'X' && !visited[x][y]);
// }

// void findPaths(int x, int y, vector<vector<char>> &grid, vector<pair<int,int>> &path, vector<vector<pair<int,int>>> &allPaths, vector<vector<bool>> &visited) {
//     int m = grid.size();
//     int n = grid[0].size();
    
//     // End point এ পৌঁছালে
//     if(x == m-1 && y == n-1) {
//         allPaths.push_back(path);
//         return;
//     }
    
//     visited[x][y] = true;
    
//     // Right Move
//     if(isValid(x, y+1, grid, visited)) {
//         path.push_back({x, y+1});
//         findPaths(x, y+1, grid, path, allPaths, visited);
//         path.pop_back(); // Backtrack
//     }
    
//     // Down Move
//     if(isValid(x+1, y, grid, visited)) {
//         path.push_back({x+1, y});
//         findPaths(x+1, y, grid, path, allPaths, visited);
//         path.pop_back(); // Backtrack
//     }
    
//     visited[x][y] = false; // Backtrack
// }

// int main() {
//     vector<vector<char>> grid = {
//         {'S','_','_'},
//         {'_','X','_'},
//         {'_','_','E'}
//     };
    
//     vector<vector<pair<int,int>>> allPaths;
//     vector<pair<int,int>> path;
//     path.push_back({0,0});
//     int m = grid.size();
//     int n = grid[0].size();
//     vector<vector<bool>> visited(m, vector<bool>(n, false));
    
//     findPaths(0, 0, grid, path, allPaths, visited);
    
//     cout << "All Paths:\n";
//     for(auto &p : allPaths) {
//         for(auto &cell : p) {
//             cout << "(" << cell.first << "," << cell.second << ") ";
//         }
//         cout << "\n";
//     }
    
//     return 0;
// }
