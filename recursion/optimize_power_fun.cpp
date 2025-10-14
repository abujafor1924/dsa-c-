
#include <iostream>
using namespace std;

int power(int base, int exp)
{
    if (exp == 0)
        return 1;
    return base * power(base, exp - 1);
}

int firstPower(int base, int exp)
{
    if (exp == 0)
        return 1;

   int subPower = firstPower(base, exp / 2);
   int subPowerSq = subPower * subPower;
   if (exp & 1)
       return base * subPowerSq;
   return subPowerSq;
}

int main()
{
    int base, exp;
    cout << "Enter base and exponent: ";
    cin >> base >> exp;

    int result = firstPower(base, exp);
    cout << base << "^" << exp << " = " << result << endl;

    return 0;
}




// #include <iostream>
// using namespace std;
// int optimizedPower(int base, int exp)
// {
//     if (exp == 0)
//         return 1;
//     int halfPower = optimizedPower(base, exp / 2);
//     int halfPowerSquared = halfPower * halfPower;
//     if (exp % 2 == 0)
//         return halfPowerSquared;
//     else
//         return base * halfPowerSquared;
// }

// int main()
// {
//     int base, exp;
//     cout << "Enter base and exponent: ";
//     cin >> base >> exp;

//     int result = optimizedPower(base, exp);
//     cout << base << "^" << exp << " = " << result << endl;

//     return 0;
// }