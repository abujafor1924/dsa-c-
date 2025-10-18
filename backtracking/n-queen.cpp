#include <iostream>
#include <vector>
#include <string>
using namespace std;

class NQueenRecursive {
private:
    vector<vector<string>> solutions;

    // Recursive function with detailed explanation
    void solve(int n, int row, vector<string>& board) {
        // BASE CASE: All queens placed successfully
        if (row == n) {
            solutions.push_back(board);
            return;
        }
        
        // RECURSIVE CASE: Try each column in current row
        for (int col = 0; col < n; col++) {
            if (isValid(board, row, col, n)) {
                // CHOOSE: Place queen at (row, col)
                board[row][col] = 'Q';
                
                // EXPLORE: Recursively try next row
                solve(n, row + 1, board);
                
                // UNCHOOSE: Backtrack - remove queen
                board[row][col] = '.';
            }
        }
        // If no valid position found in this row, function returns
        // and backtracking happens automatically
    }

    // Check if placing queen at (row, col) is valid
    bool isValid(vector<string>& board, int row, int col, int n) {
        // Check column (above rows)
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q')
                return false;
        }
        
        // Check upper left diagonal
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q')
                return false;
        }
        
        // Check upper right diagonal
        for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }
        
        return true;
    }

public:
    vector<vector<string>> solveNQueens(int n) {
        solutions.clear();
        vector<string> board(n, string(n, '.'));
        solve(n, 0, board);
        return solutions;
    }
    
    void visualizeRecursion(int n, int depth = 0) {
        vector<string> board(n, string(n, '.'));
        cout << "Recursion Visualization for N=" << n << ":\n";
        visualizeSolve(n, 0, board, depth);
    }
    
private:
    void visualizeSolve(int n, int row, vector<string>& board, int depth) {
        // Indent based on recursion depth
        string indent(depth * 2, ' ');
        cout << indent << "Row " << row << ": ";
        
        if (row == n) {
            cout << "SOLUTION FOUND!\n";
            return;
        }
        
        for (int col = 0; col < n; col++) {
            if (isValid(board, row, col, n)) {
                cout << "Q@" << col << " ";
                board[row][col] = 'Q';
                visualizeSolve(n, row + 1, board, depth + 1);
                board[row][col] = '.';
            }
        }
        cout << indent << "Backtrack from row " << row << endl;
    }
};

// Simplified version focusing on recursion
class SimpleNQueen {
public:
    int countSolutions(int n) {
        vector<string> board(n, string(n, '.'));
        return countHelper(n, 0, board);
    }
    
private:
    int countHelper(int n, int row, vector<string>& board) {
        if (row == n) {
            return 1; // Found one solution
        }
        
        int count = 0;
        for (int col = 0; col < n; col++) {
            if (isSafe(board, row, col, n)) {
                board[row][col] = 'Q';
                count += countHelper(n, row + 1, board);
                board[row][col] = '.'; // Backtrack
            }
        }
        return count;
    }
    
    bool isSafe(vector<string>& board, int row, int col, int n) {
        // Check column
        for (int i = 0; i < row; i++) {
            if (board[i][col] == 'Q') return false;
        }
        
        // Check diagonals
        for (int i = row-1, j = col-1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = row-1, j = col+1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q') return false;
        }
        
        return true;
    }
};

// Demonstration of recursion tree
void demonstrateRecursionTree() {
    cout << "RECURSION TREE FOR N=3:\n";
    cout << "======================\n";
    
    SimpleNQueen solver;
    int solutions = solver.countSolutions(3);
    cout << "Total solutions for N=3: " << solutions << endl;
    
    cout << "\nRecursive calls would follow this pattern:\n";
    cout << "Start at row 0\n";
    cout << "  Try col 0 -> row 1\n";
    cout << "    Try col 0 -> conflict\n";
    cout << "    Try col 1 -> conflict\n"; 
    cout << "    Try col 2 -> row 2\n";
    cout << "      Try col 0 -> conflict\n";
    cout << "      Try col 1 -> conflict\n";
    cout << "      Backtrack to row 1\n";
    cout << "  Backtrack to row 0\n";
    cout << "  Try col 1 -> row 1\n";
    cout << "    Try col 0 -> conflict\n";
    cout << "    Try col 1 -> conflict\n";
    cout << "    Try col 2 -> conflict\n";
    cout << "  Backtrack to row 0\n";
    cout << "  Try col 2 -> ... (similar pattern)\n";
}

// Main function to test
int main() {
    cout << "=== N-QUEEN RECURSIVE BACKTRACKING ===\n\n";
    
    // Test recursive solver
    NQueenRecursive solver;
    
    // Test for small N values
    for (int n = 1; n <= 6; n++) {
        auto solutions = solver.solveNQueens(n);
        cout << "N = " << n << ": " << solutions.size() << " solutions\n";
        
        if (n <= 4 && !solutions.empty()) {
            cout << "First solution:\n";
            for (const auto& row : solutions[0]) {
                for (char cell : row) {
                    cout << cell << " ";
                }
                cout << endl;
            }
            cout << "---\n";
        }
    }
    
    cout << "\n";
    demonstrateRecursionTree();
    
    // Count only solutions
    SimpleNQueen counter;
    cout << "\nSolution Counts:\n";
    for (int n = 1; n <= 8; n++) {
        cout << "N=" << n << ": " << counter.countSolutions(n) << " solutions\n";
    }
    
    return 0;
}