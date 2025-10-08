#include <iostream>
#include <vector>
using namespace std;


/*আমাদের একটি N x N গ্রিড দেওয়া আছে, যেখানে কিছু সেলে ম্যাঙ্গো গাছ আছে (1) 
এবং কিছু সেলে নেই (0)। আমাদেরকে এমন একটি বিন্দু (x,y) খুঁজে বের করতে হবে যেটি গ্রিডকে 
৪টি rectangle-এ ভাগ করে এবং প্রতিটি rectangle-এ সমান সংখ্যক ম্যাঙ্গো গাছ থাকে।*/



class MangoTreeSolver {
private:
    vector<vector<int>> prefix; // 2D prefix sum array
    int N; // Size of grid (N x N)
    
public:
    // Constructor: builds prefix sum matrix from the grid
    MangoTreeSolver(vector<vector<int>>& grid) {
        N = grid.size();
        // Initialize prefix sum matrix with extra row and column for easier calculations
        prefix.resize(N+1, vector<int>(N+1, 0));
        
        // Build prefix sum matrix using dynamic programming approach
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                // prefix[i][j] = sum of all elements from (0,0) to (i-1,j-1)
                prefix[i][j] = grid[i-1][j-1]  // Current cell value
                             + prefix[i-1][j]   // Sum from top rectangle
                             + prefix[i][j-1]   // Sum from left rectangle  
                             - prefix[i-1][j-1]; // Subtract overlapping part (added twice)
            }
        }
    }
    
    // Function to count mango trees in rectangle from (r1,c1) to (r2,c2) inclusive
    int countMangoes(int r1, int c1, int r2, int c2) {
        // Using prefix sum formula for rectangle sum:
        // sum = bottom_right - top_right - bottom_left + top_left
        return prefix[r2+1][c2+1] // Sum from (0,0) to (r2,c2)
             - prefix[r1][c2+1]   // Subtract sum from (0,0) to (r1-1,c2)
             - prefix[r2+1][c1]   // Subtract sum from (0,0) to (r2,c1-1)
             + prefix[r1][c1];    // Add back the overlapping subtracted part
    }
    
    // Main function to find division point (x,y) that splits grid into 4 equal mango regions
    pair<int, int> findDivisionPoint() {
        // Calculate total number of mango trees in entire grid
        int totalMangoes = countMangoes(0, 0, N-1, N-1);
        
        // If total mangoes cannot be divided equally into 4 parts, no solution
        if(totalMangoes % 4 != 0) {
            return {-1, -1}; // Return invalid point
        }
        
        int requiredPerQuadrant = totalMangoes / 4; // Each quadrant should have this many mangoes
        
        // Try all possible division points (x,y)
        // x ranges from 0 to N-2 (since we need at least 1 row in bottom halves)
        // y ranges from 0 to N-2 (since we need at least 1 column in right halves)
        for(int x = 0; x < N-1; x++) {
            for(int y = 0; y < N-1; y++) {
                // Calculate mango count in each of the 4 quadrants:
                
                // Quadrant 1: Top-left (from (0,0) to (x,y))
                int Q1 = countMangoes(0, 0, x, y);
                
                // Quadrant 2: Top-right (from (0,y+1) to (x,N-1))
                int Q2 = countMangoes(0, y+1, x, N-1);
                
                // Quadrant 3: Bottom-left (from (x+1,0) to (N-1,y))
                int Q3 = countMangoes(x+1, 0, N-1, y);
                
                // Quadrant 4: Bottom-right (from (x+1,y+1) to (N-1,N-1))
                int Q4 = countMangoes(x+1, y+1, N-1, N-1);
                
                // Check if all quadrants have equal number of mango trees
                if(Q1 == requiredPerQuadrant && 
                   Q2 == requiredPerQuadrant && 
                   Q3 == requiredPerQuadrant && 
                   Q4 == requiredPerQuadrant) {
                    return {x, y}; // Found valid division point
                }
            }
        }
        
        return {-1, -1}; // No valid division point found
    }
    
    // Utility function to print the prefix sum matrix (for debugging)
    void printPrefixMatrix() {
        cout << "Prefix Sum Matrix:" << endl;
        for(int i = 1; i <= N; i++) {
            for(int j = 1; j <= N; j++) {
                cout << prefix[i][j] << "\t";
            }
            cout << endl;
        }
    }
};

// Helper function to print the grid
void printGrid(vector<vector<int>>& grid) {
    cout << "Original Grid:" << endl;
    for(auto row : grid) {
        for(int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    // Test case 1: Example grid that can be divided equally
    vector<vector<int>> grid1 = {
        {1, 0, 0, 1},
        {0, 1, 1, 0},
        {1, 0, 1, 0},
        {0, 1, 0, 1}
    };
    
    cout << "=== Test Case 1 ===" << endl;
    printGrid(grid1);
    
    MangoTreeSolver solver1(grid1);
    pair<int, int> result1 = solver1.findDivisionPoint();
    
    if(result1.first != -1) {
        cout << "Division point found at: (" << result1.first << ", " << result1.second << ")" << endl;
        
        // Verify the solution
        int total = solver1.countMangoes(0, 0, 3, 3);
        int Q1 = solver1.countMangoes(0, 0, result1.first, result1.second);
        int Q2 = solver1.countMangoes(0, result1.second+1, result1.first, 3);
        int Q3 = solver1.countMangoes(result1.first+1, 0, 3, result1.second);
        int Q4 = solver1.countMangoes(result1.first+1, result1.second+1, 3, 3);
        
        cout << "Verification - Q1: " << Q1 << ", Q2: " << Q2 << ", Q3: " << Q3 << ", Q4: " << Q4 << endl;
        cout << "All quadrants equal: " << (Q1 == Q2 && Q2 == Q3 && Q3 == Q4 ? "YES" : "NO") << endl;
    } else {
        cout << "No division point found!" << endl;
    }
    
    cout << endl;
    
    // Test case 2: Grid that cannot be divided equally
    vector<vector<int>> grid2 = {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };
    
    cout << "=== Test Case 2 ===" << endl;
    printGrid(grid2);
    
    MangoTreeSolver solver2(grid2);
    pair<int, int> result2 = solver2.findDivisionPoint();
    
    if(result2.first != -1) {
        cout << "Division point found at: (" << result2.first << ", " << result2.second << ")" << endl;
    } else {
        cout << "No division point found! (Total mangoes: " << solver2.countMangoes(0, 0, 2, 2) 
             << ", divisible by 4: " << (solver2.countMangoes(0, 0, 2, 2) % 4 == 0 ? "YES" : "NO") << ")" << endl;
    }
    
    return 0;
}