#include <iostream>
#include <vector>
#include "vector.h"

using namespace std;

int main()


{
     vector<char> vc;
     vc.push_back('a');
     vc.push_back('b');
     vc.push_back('c');

     for (char ch : vc) {
          cout << "[" << ch << "] ";
     }
     cout << endl;
    // STL vector demonstration
    cout << "=== STL Vector ===" << endl;
    vector<int> v; // STL vector
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    
    cout << "STL Vector elements: ";
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    
    cout << "size: " << v.size() << endl;
    cout << "capacity: " << v.capacity() << endl;
    cout << "front: " << v.front() << endl;
    cout << "back: " << v.back() << endl;
    cout << "at(1): " << v.at(1) << endl;
    cout << "isEmpty: " << v.empty() << endl;
    cout << "operator[1]: " << v[1] << endl;
    
    cout << "\n=== Custom Vector Class (int) ===" << endl;
    VectorClass<int> vec; // object of class with int type
    
    // Add elements to custom vector
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30); // This should trigger resizing
    vec.push_back(40);
    
    cout << "Custom Vector elements: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;
    
    cout << "size: " << vec.size() << endl;
    cout << "capacity: " << vec.capacity() << endl;
    cout << "front: " << vec.front() << endl;
    cout << "back: " << vec.back() << endl;
    cout << "at(1): " << vec.at(1) << endl;
    cout << "isEmpty: " << vec.isEmpty() << endl;
    cout << "isFull: " << vec.isFull() << endl;
    cout << "operator[1]: " << vec[1] << endl;
    
    // Test pop_back
    vec.pop_back();
    cout << "\nAfter pop_back:" << endl;
    cout << "size: " << vec.size() << endl;
    cout << "back: " << vec.back() << endl;
    
    cout << "\n=== Custom Vector Class (double) ===" << endl;
    VectorClass<double> doubleVec; // object of class with double type
    
    doubleVec.push_back(1.1);
    doubleVec.push_back(2.2);
    doubleVec.push_back(3.3);
    
    cout << "Double Vector elements: ";
    for (int i = 0; i < doubleVec.size(); i++) {
        cout << doubleVec[i] << " ";
    }
    cout << endl;
    
    cout << "size: " << doubleVec.size() << endl;
    cout << "capacity: " << doubleVec.capacity() << endl;
    
    cout << "\n=== Custom Vector Class (string) ===" << endl;
    VectorClass<string> stringVec; // object of class with string type
    
    stringVec.push_back("Hello");
    stringVec.push_back("World");
    stringVec.push_back("Template");
    
    cout << "String Vector elements: ";
    for (int i = 0; i < stringVec.size(); i++) {
        cout << stringVec[i] << " ";
    }
    cout << endl;
    
    return 0;
}