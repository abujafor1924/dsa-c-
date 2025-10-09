
// This is an example of dynamic 2D array allocation in C++

#include <iostream>
using namespace std;


int** create2darray(int rows, int cols) {
    int **matrix = new int*[rows];  // row পয়েন্টারদের অ্যারে
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];  // প্রতিটি row এর জন্য কলাম
    }
    return matrix;
}

int main() {
    int rows, cols; // rows and columns
    
    cout << "Enter rows and columns: ";
    cin >> rows >> cols; // user input
    
    // 2D অ্যারে অ্যালোকেশন
    int **matrix = new int*[rows];  // row পয়েন্টারদের অ্যারে
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];  // প্রতিটি row এর জন্য কলাম
    }
    
    // ডাটা ইনিশিয়ালাইজ
    int counter = 1;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) { 
            matrix[i][j] = counter++; // filling with sequential numbers
        }
    }
    
    // ডাটা প্রিন্ট
    cout << "Matrix:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t"; // printing each element
        }
        cout << endl;
    }
    
    // মেমোরি ফ্রি করা
    for(int i = 0; i < rows; i++) {
        delete[] matrix[i];  // প্রতিটি row ফ্রি
    }
    delete[] matrix;  // row পয়েন্টার অ্যারে ফ্রি
    matrix = nullptr; // avoiding dangling pointer
    
    return 0;
}


