#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

template <typename T> // Template declaration, it is used to create generic class, it is used to create class with any data type, custom vector class
class VectorClass {
    T *arr; // dynamic array
    int cs;   // current size
    int ms;   // max size or capacity

public:
    VectorClass(int default_size = 2) // constructor
    {
        cs = 0; // current size starts at 0
        ms = default_size; // max size or capacity
        arr = new T[ms]; // dynamic array
        
        cout << "Constructor called" << endl;
        cout << "Size: " << cs << endl;
        cout << "Capacity: " << ms << endl;
    }

    void push_back(const T& data) // add element at last
    {
        if (cs == ms) // if current size is equal to max size
        {
            T *oldArr = arr; // store old array
            ms = ms * 2; // double the max size
            arr = new T[ms]; // create new array with double size
            for (int i = 0; i < cs; i++) // copy old array to new array
            {
                arr[i] = oldArr[i]; // copy old array to new array
            }
            delete[] oldArr; // delete old array
        }
        arr[cs] = data; // add element at last
        cs++; // increment current size
    }

    void pop_back()
    {
        if (cs > 0) // if current size is greater than 0
        {
            cs--; // decrement current size
        }
    }

    bool isEmpty() const // check if vector is empty
    {
        return cs == 0; // if current size is 0 then vector is empty
    }

    bool isFull() const // check if vector is full
    {
        return cs == ms; // if current size is equal to max size then vector is full
    }

    int size() const // return current size
    {
        return cs; // current size
    }

    int capacity() const
    {
        return ms; // max size
    }

    T front() const // return first element
    {
        if (!isEmpty()) // if vector is not empty
        {
            return arr[0]; // return first element
        }
        return T(); // return default constructed value
    }

    T back() const // return last element
    {
        if (!isEmpty()) // if vector is not empty
        {
            return arr[cs - 1]; // return last element
        }
        return T(); // return default constructed value
    }

    T at(int i) const
    {
        if (i < cs && i >= 0)
        {
            return arr[i];
        }
        return T(); // return default constructed value
    }

    ~VectorClass() // destructor
    {
        delete[] arr; // delete dynamic array
        cout << "Destructor called" << endl;
    }

    T& operator[](int i) // operator overloading for non-const objects
    {
        return arr[i]; // return element at index i
    }

    const T& operator[](int i) const // operator overloading for const objects
    {
        return arr[i]; // return element at index i
    }
};

#endif