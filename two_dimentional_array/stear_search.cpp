#include <iostream>
using namespace std;

pair<int, int> searchInMatrix(int arr[][4], int n, int m, int target) {
    if (target < arr[0][0] || target > arr[n-1][m-1]) {
        return {-1, -1}; // Target is out of the matrix bounds
    }     
    int i=0, j=m-1; // Start from the top-right corner
    while (i<=n-1 and j>=0)
    {
        if (arr[i][j] == target) {
            return {i, j}; // Target found
        } else if (arr[i][j] > target) {
            j--; // Move left
        } else {
            i++; // Move down
        }
    }
     return {-1, -1};
    // Target not found
}

int main()
{
      int arr[][4] = {
          {10, 20, 30, 40},
          {15, 25, 35, 45},
          {27, 29, 37, 48},
          {32, 33, 39, 50}
      };
      int n = 4, m = 4;
      
      pair<int, int> coords = searchInMatrix(arr, n, m, 29);
      cout << "Target found at: (" << coords.first << ", " << coords.second << ")\n";
      
      return 0;
}