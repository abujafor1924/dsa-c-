#include <iostream>
#include <cmath>
using namespace std;

bool solvSudoku(int mat[][9], int i, int j,int n)
{
    // Base case
    if (i == n)
    {
        return true;
    }
    if (j == n)
    {
        return solvSudoku(mat, i + 1, 0, n);
    }
    if (mat[i][j] != 0)
    {
        return solvSudoku(mat, i, j + 1, n);
    }

    // Recursive case
    for (int num = 1; num <= 9; num++)
    {
        // Check if number can be placed
        bool canPlace = true;

        // Check row and column
        for (int x = 0; x < n; x++)
        {
            if (mat[i][x] == num || mat[x][j] == num)
            {
                canPlace = false;
                break;
            }
        }

        // Check 3x3 subgrid
        int startRow = i - i % 3;
        int startCol = j - j % 3;
        for (int x = 0; x < 3; x++)
        {
            for (int y = 0; y < 3; y++)
            {
                if (mat[startRow + x][startCol + y] == num)
                {
                    canPlace = false;
                    break;
                }
            }
        }

        if (canPlace)
        {
            mat[i][j] = num;
            if (solvSudoku(mat, i, j + 1, n))
            {
                return true;
            }
            mat[i][j] = 0; // Backtrack
        }
    }
    return false;
}


int main()
{
    int n = 9;
    int mat[9][9] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (solvSudoku(mat, 0, 0,n))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << mat[i][j] << " ";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "No solution exists" << endl;
    }

    return 0;
}












// #include <iostream>
// using namespace std;

// #define N 9

// // ফাংশন: চেক করবে number কি row, col, এবং 3x3 box-এ বসানো যাবে কি না
// bool isSafe(int grid[N][N], int row, int col, int num) {
//     // সারি চেক
//     for (int x = 0; x < N; x++)
//         if (grid[row][x] == num)
//             return false;

//     // কলাম চেক
//     for (int x = 0; x < N; x++)
//         if (grid[x][col] == num)
//             return false;

//     // 3x3 বক্স চেক
//     int startRow = row - row % 3;
//     int startCol = col - col % 3;
//     for (int i = 0; i < 3; i++)
//         for (int j = 0; j < 3; j++)
//             if (grid[startRow + i][startCol + j] == num)
//                 return false;

//     return true;
// }

// // Sudoku solver ফাংশন
// bool solveSudoku(int grid[N][N]) {
//     for (int row = 0; row < N; row++) {
//         for (int col = 0; col < N; col++) {
//             if (grid[row][col] == 0) { // খালি ঘর
//                 for (int num = 1; num <= 9; num++) {
//                     if (isSafe(grid, row, col, num)) {
//                         grid[row][col] = num; // বসানো হলো

//                         if (solveSudoku(grid))
//                             return true; // যদি সফল হয়

//                         grid[row][col] = 0; // backtrack
//                     }
//                 }
//                 return false; // কোন সংখ্যা মানায় না
//             }
//         }
//     }
//     return true; // সব ঘর পূর্ণ
// }

// // Sudoku board print করার ফাংশন
// void printGrid(int grid[N][N]) {
//     for (int row = 0; row < N; row++) {
//         for (int col = 0; col < N; col++)
//             cout << grid[row][col] << " ";
//         cout << endl;
//     }
// }

// int main() {
//     int grid[N][N] = {
//         {5,3,0,0,7,0,0,0,0},
//         {6,0,0,1,9,5,0,0,0},
//         {0,9,8,0,0,0,0,6,0},
//         {8,0,0,0,6,0,0,0,3},
//         {4,0,0,8,0,3,0,0,1},
//         {7,0,0,0,2,0,0,0,6},
//         {0,6,0,0,0,0,2,8,0},
//         {0,0,0,4,1,9,0,0,5},
//         {0,0,0,0,8,0,0,7,9}
//     };

//     if (solveSudoku(grid))
//         printGrid(grid);
//     else
//         cout << "No solution exists" << endl;

//     return 0;
// }
