#include<iostream>
#include<vector>

using namespace std;

int main()
{
     vector<vector<int>> vec2d = {
          {1, 2, 3},
          {4, 5, 6},
          {7, 8, 9}
     };

     // for (const auto& row : vec2d) {
     //      cout << row[0] << " " << row[1] << " " << row[2];
     //      // for (const auto& elem : row) {
     //      //      cout << elem << " ";
     //      // }
     //      cout << endl;
     // }

     for (size_t i = 0; i < vec2d.size(); ++i) {
          for ( int num : vec2d[i]) {
               cout << num << " ,";
          }    
          cout << endl;
     }

    return 0;
}
