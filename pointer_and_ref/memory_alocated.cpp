#include <iostream>
using namespace std;


// This program demonstrates dynamic memory allocation for a 1D array in C++
int main() {
    int n;
    
    cout << "Enter array size: ";
    cin >> n;
    
    // ডাইনামিক অ্যারে অ্যালোকেশন
    int *arr = new int[n];
    
    // ইনপুট নেওয়া
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    // ক্যালকুলেশন
    int sum = 0;
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    cout << "Sum: " << sum << endl;
    cout << "Average: " << (double)sum / n << endl;
    cout << "Array size in bytes: " << sizeof(int) * n << endl;

    
    // মেমোরি ফ্রি করা
    delete[] arr;
    arr = nullptr;

    cout << "Memory freed successfully." << endl;
    cout << "Address after deletion: " << arr << endl; // arr এখন nullptr
    
    return 0;
}










// This is another example of dynamic memory allocation in C++
/* #include <iostream>
using namespace std;

int main() {
    // ডাইনামিক মেমোরি অ্যালোকেশন
    int *ptr = new int;
    
    // ভ্যালু অ্যাসাইন
    *ptr = 100;
    
    cout << "Value: " << *ptr << endl;
    cout << "Address: " << ptr << endl;
    cout << "Size: " << sizeof(*ptr) << " bytes" << endl;
    
    // মেমোরি ফ্রি করা
    delete ptr;
    ptr = nullptr;  // ড্যানগলিং পয়েন্টার এড়ানো
    
    return 0;
}

*/







// This is an example of dynamic 2D array allocation in C++
/*
#include <iostream>
using namespace std;

int main() {
    int rows, cols;
    
    cout << "Enter rows and columns: ";
    cin >> rows >> cols;
    
    // 2D অ্যারে অ্যালোকেশন
    int **matrix = new int*[rows];  // row পয়েন্টারদের অ্যারে
    for(int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];  // প্রতিটি row এর জন্য কলাম
    }
    
    // ডাটা ইনিশিয়ালাইজ
    int counter = 1;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            matrix[i][j] = counter++;
        }
    }
    
    // ডাটা প্রিন্ট
    cout << "Matrix:" << endl;
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    
    // মেমোরি ফ্রি করা
    for(int i = 0; i < rows; i++) {
        delete[] matrix[i];  // প্রতিটি row ফ্রি
    }
    delete[] matrix;  // row পয়েন্টার অ্যারে ফ্রি
    matrix = nullptr;
    
    return 0;
}


*/