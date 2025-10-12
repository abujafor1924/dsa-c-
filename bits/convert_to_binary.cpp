#include <iostream>
using namespace std;

int convert_to_binary(int n)
{
    int binary = 0, place = 1;
    while (n > 0) {
        int last_bit = n & 1; // Extract the last bit
        binary += last_bit * place; // Add it to the binary number
        place *= 10; // Move to the next place value
        n >>= 1; // Right shift to process the next bit
    }
    return binary;
}


int main()
{


     int n;
     cin >> n;
     cout << "Binary representation of " << n << " is: " << convert_to_binary(n) << endl;
     return 0;
}