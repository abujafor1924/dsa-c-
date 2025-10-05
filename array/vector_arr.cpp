#include<iostream>
#include<vector>
using namespace std;

int main() {
//     vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    vector<int> arr[5][6]; // vector of size 5, each element is an empty vector
    arr[0][0].push_back(10); // add 10 at the end of the first vector
    arr[0][0].pop_back();    // remove the last element of the first vector

    cout << arr[0][0].size() << endl;  // size of the vector
    cout << arr[0][0].capacity() << endl; // capacity of the vector
    cout << arr[0][0].max_size() << endl; // maximum size of the vector
    cout << arr[0][0].empty() << endl; // check if the vector is empty or not (0 -> false, 1 -> true)

    return 0;
}





/*

# C++ Vector সম্পূর্ণ বিস্তারিত বাংলায় ব্যাখ্যা

## Vector কী?

**Vector** হল C++ STL (Standard Template Library)-এর একটি ডাইনামিক অ্যারে (Dynamic Array) যা স্বয়ংক্রিয়ভাবে তার সাইজ adjust করতে পারে। এটি একটি টেমপ্লেট ক্লাস যেখানে আমরা যেকোনো ডাটা টাইপ স্টোর করতে পারি।

```cpp
#include <vector>
using namespace std;
```

## Vector এর বিশেষ বৈশিষ্ট্য:

1. **ডাইনামিক সাইজ** - স্বয়ংক্রিয়ভাবে বড় বা ছোট হতে পারে
2. **কন্টিগুয়াস মেমরি** - এলিমেন্টগুলো মেমরিতে পরপর থাকে
3. **অটোমেটিক মেমরি ম্যানেজমেন্ট** - নিজে নিজে মেমরি allocate/deallocate করে

## Vector ডিক্লারেশন ও ইনিশিয়ালাইজেশন:

```cpp
// বিভিন্ন ভাবে Vector ডিক্লারেশন
vector<int> v1;                    // খালি vector
vector<int> v2(5);                 // 5টি এলিমেন্ট, সবগুলো 0
vector<int> v3(5, 10);             // 5টি এলিমেন্ট, সবগুলো 10
vector<int> v4 = {1, 2, 3, 4, 5}; // ইনিশিয়াল ভ্যালু সহ
vector<int> v5(v4);                // অন্য vector থেকে কপি
```

## সাধারণ Member Functions:

### 1. **এলিমেন্ট অ্যাক্সেস করার মেথড:**

```cpp
vector<int> v = {10, 20, 30, 40, 50};

// বিভিন্নভাবে এলিমেন্ট অ্যাক্সেস
cout << v[2];      // 30 (বাউন্ড চেক করে না)
cout << v.at(2);   // 30 (বাউন্ড চেক করে)
cout << v.front(); // 10 (প্রথম এলিমেন্ট)
cout << v.back();  // 50 (শেষ এলিমেন্ট)
```

### 2. **ক্যাপাসিটি সম্পর্কিত মেথড:**

```cpp
vector<int> v;

cout << v.size();     // Vector-এ কতগুলো এলিমেন্ট আছে
cout << v.capacity(); // কতগুলো এলিমেন্টের জন্য মেমরি allocated
cout << v.empty();    // Vector খালি কি না (true/false)
```

### 3. **মডিফায়ার মেথড:**

```cpp
vector<int> v = {1, 2, 3};

// এলিমেন্ট যোগ
v.push_back(4);       // শেষে 4 যোগ -> {1,2,3,4}
v.pop_back();         // শেষের এলিমেন্ট remove -> {1,2,3}

// নির্দিষ্ট পজিশনে যোগ
v.insert(v.begin() + 1, 10); // index 1-এ 10 যোগ -> {1,10,2,3}

// এলিমেন্ট ডিলিট
v.erase(v.begin() + 1);      // index 1-এর এলিমেন্ট ডিলিট -> {1,2,3}
v.clear();                   // সব এলিমেন্ট ডিলিট -> {}
```

## Practical Examples:

### উদাহরণ ১: Basic Vector Operations

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> numbers;
    
    // এলিমেন্ট যোগ
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);
    
    // সব এলিমেন্ট প্রিন্ট
    cout << "Vector elements: ";
    for(int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << " ";
    }
    // Output: Vector elements: 10 20 30
    
    // Size এবং Capacity
    cout << "\nSize: " << numbers.size();        // 3
    cout << "\nCapacity: " << numbers.capacity(); // 4 (বা তার বেশি)
    
    return 0;
}
```

### উদাহরণ ২: Vector Traversal (Iteration)

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<string> names = {"Alice", "Bob", "Charlie", "Diana"};
    
    // Method 1: Index দিয়ে
    cout << "Method 1: ";
    for(int i = 0; i < names.size(); i++) {
        cout << names[i] << " ";
    }
    
    // Method 2: Range-based for loop
    cout << "\nMethod 2: ";
    for(string name : names) {
        cout << name << " ";
    }
    
    // Method 3: Iterator দিয়ে
    cout << "\nMethod 3: ";
    for(auto it = names.begin(); it != names.end(); it++) {
        cout << *it << " ";
    }
    
    return 0;
}
```

### উদাহরণ ৩: 2D Vector (Matrix)

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 2D Vector (3x3 ম্যাট্রিক্স)
    vector<vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    // ম্যাট্রিক্স প্রিন্ট
    cout << "2D Vector (Matrix):\n";
    for(int i = 0; i < matrix.size(); i++) {
        for(int j = 0; j < matrix[i].size(); j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
```

### উদাহরণ ৪: Vector with Algorithms

```cpp
#include <iostream>
#include <vector>
#include <algorithm> // sort, find এর জন্য
using namespace std;

int main() {
    vector<int> numbers = {5, 2, 8, 1, 9, 3};
    
    // সর্ট করা
    sort(numbers.begin(), numbers.end());
    
    cout << "Sorted vector: ";
    for(int num : numbers) {
        cout << num << " ";
    }
    // Output: Sorted vector: 1 2 3 5 8 9
    
    // খুঁজে বের করা
    auto it = find(numbers.begin(), numbers.end(), 5);
    if(it != numbers.end()) {
        cout << "\nFound 5 at position: " << (it - numbers.begin());
    }
    
    return 0;
}
```

## Vector এর Advantages (সুবিধা):

1. **ডাইনামিক সাইজ** - Runtime-এ সাইজ change করা যায়
2. **মেমরি ম্যানেজমেন্ট** - অটোমেটিকভাবে মেমরি ব্যবস্থাপনা
3. **STL Support** - Algorithm, Iterator সহ সম্পূর্ণ STL সাপোর্ট
4. **Type Safety** - Type checking থাকে

## Vector এর Disadvantages (অসুবিধা):

1. **Insert/Delete Cost** - মাঝখানে এলিমেন্ট insert/delete করতে বেশি সময় লাগে
2. **Memory Overhead** - কিছু অতিরিক্ত মেমরি ব্যবহার করে

## Important Notes:

```cpp
// Vector এর Performance
v.push_back()    // সাধারণত O(1), কিন্তু resize হলে O(n)
v.insert()       // O(n) - কারণ এলিমেন্ট shift করতে হয়
v.erase()        // O(n) - কারণ এলিমেন্ট shift করতে হয়
v[i]             // O(1) - direct access

// Capacity Management
v.reserve(100);  // 100 এলিমেন্টের জন্য মেমরি reserve করে
v.shrink_to_fit(); // এক্সট্রা capacity কমায়
```

## Real-life Use Cases:

1. **ডাইনামিক লিস্ট** - যখন事先 সাইজ জানা নেই
2. **ডাটা স্ট্রাকচার** - Stack, Queue ইম্প্লিমেন্ট করতে
3. **অ্যালগরিদম** - Sorting, Searching অ্যালগরিদমে
4. **গেম ডেভেলপমেন্ট** - Game objects, Positions store করতে

Vector হল C++-এর সবচেয়ে বেশি ব্যবহৃত এবং ইউজফুল কন্টেইনারগুলোর মধ্যে একটি যা প্রোগ্রামিংকে অনেক সহজ এবং efficient করে তোলে!













*/