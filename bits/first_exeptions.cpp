#include <iostream>
#include <stdexcept>
using namespace std;     

int fastExponentiation(int base, int exponent) {
    if (exponent < 0) {
        throw invalid_argument("Exponent should be non-negative.");
    }
    int result = 1;
    while (exponent > 0) {
        if (exponent % 2 == 1) { // If exponent is odd
            result *= base;
        }
        base *= base; // Square the base
        exponent /= 2; // Divide exponent by 2
    }
    return result;
}

int main() {
     int a, b;
     cin >> a >> b;
     try {
         cout << a << " raised to the power " << b << " is: " << fastExponentiation(a, b) << endl;
     } catch (const invalid_argument& e) {
         cerr << e.what() << endl;
     }
    return 0;
}