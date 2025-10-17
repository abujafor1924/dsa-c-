#include <iostream>
using namespace std;

void findSubsets(char *input, char *output, int index, int j) {
    // Base case: If we reach the end of the input string
    if (input[index] == '\0') {
        output[j] = '\0'; // Null-terminate the output string
        cout << output << endl; // Print the current subset
        return;
    }

    // Include the current character in the subset
    output[j] = input[index];
    findSubsets(input, output, index + 1, j + 1);

    // Exclude the current character from the subset
    findSubsets(input, output, index + 1, j);
}

int main() {
    char input[100];
    cout << "Enter a string: ";
    cin >> input;
    char output[100]; // Assuming the output will not exceed 100 characters
    findSubsets(input, output, 0, 0);
    return 0;
}














// #include<iostream>
// #include<vector>
// using namespace std;

// void findSubsets(int index, vector<int>& arr, vector<int>& currentSubset, vector<vector<int>>& allSubsets) {
//     // Base case: If index reaches the size of the array, store the current subset
//     if (index == arr.size()) {
//         allSubsets.push_back(currentSubset);
//         return;
//     }

//     // Include the current element
//     currentSubset.push_back(arr[index]);
//     findSubsets(index + 1, arr, currentSubset, allSubsets);

//     // Exclude the current element
//     currentSubset.pop_back();
//     findSubsets(index + 1, arr, currentSubset, allSubsets);
// }

// int main() {
//     vector<int> arr = {1, 2, 3};
//     vector<vector<int>> allSubsets;
//     vector<int> currentSubset;
//     findSubsets(0, arr, currentSubset, allSubsets);

//     // Print all subsets
//     for (const auto& subset : allSubsets) {
//         for (int num : subset) {
//             cout << num << " ";
//         }
//         cout << endl;
//     }

//     return 0;
// }