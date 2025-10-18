#include <iostream>
using namespace std;

bool canPlaceQueen(int board[][20], int n, int x, int y) {
    // Check column
    for (int i = 0; i < x; i++) {
        if (board[i][y] == 1) return false;
    }
    
    // Check upper left diagonal
    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) return false;
    }
    
    // Check upper right diagonal
    for (int i = x, j = y; i >= 0 && j < n; i--, j++) {
        if (board[i][j] == 1) return false;
    }
    
    return true;
}

int solveNQueenUtil(int board[][20], int n, int x) {
    if (x >= n) {
        return 1; // Found a solution
    }

    int count = 0;
    for (int col = 0; col < n; col++) {
        if (canPlaceQueen(board, n, x, col)) {
            board[x][col] = 1; // Place queen
            count += solveNQueenUtil(board, n, x + 1); // Recur to place rest
            board[x][col] = 0; // Backtrack
        }
    }
    return count;
}

int solveNQueen(int n) {
    if (n <= 0 || n > 20) {
        cout << "N should be between 1 and 20" << endl;
        return 0;
    }
    int board[20][20] = {0}; // Initialize board with zeros
    return solveNQueenUtil(board, n, 0);
}

// Optional: Function to print a solution (for visualization)
void printSolution(int board[][20], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (board[i][j] == 1)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

// Version that prints all solutions
int solveNQueenWithPrint(int board[][20], int n, int x) {
    if (x >= n) {
        printSolution(board, n);
        return 1;
    }

    int count = 0;
    for (int col = 0; col < n; col++) {
        if (canPlaceQueen(board, n, x, col)) {
            board[x][col] = 1;
            count += solveNQueenWithPrint(board, n, x + 1);
            board[x][col] = 0;
        }
    }
    return count;
}

void printAllSolutions(int n) {
    if (n <= 0 || n > 20) {
        cout << "N should be between 1 and 20" << endl;
        return;
    }
    int board[20][20] = {0};
    int total = solveNQueenWithPrint(board, n, 0);
    cout << "Total solutions printed: " << total << endl;
}

int main() {
    int n;
    cout << "Enter the value of N for N-Queens (1-20): ";
    cin >> n;
    
    if (n < 1 || n > 20) {
        cout << "Please enter a value between 1 and 20." << endl;
        return 1;
    }
    
    int totalSolutions = solveNQueen(n);
    cout << "Total solutions for N=" << n << ": " << totalSolutions << endl;
    
    // Ask if user wants to see all solutions
    if (totalSolutions > 0 && totalSolutions <= 20) {
        char choice;
        cout << "Do you want to see all solutions? (y/n): ";
        cin >> choice;
        if (choice == 'y' || choice == 'Y') {
            cout << "\nAll solutions for " << n << "-Queens:\n" << endl;
            printAllSolutions(n);
        }
    } else if (totalSolutions > 20) {
        cout << "Too many solutions to display (" << totalSolutions << " solutions found)" << endl;
    }
    
    return 0;
}