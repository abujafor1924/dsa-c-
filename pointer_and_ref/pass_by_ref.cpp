#include<iostream>
using namespace std;

void applyTex(int income)
{
     float tax=0.3;
     income = income - (income * tax); // modifying the local copy
     cout << "Salary after tax inside function: " << income << endl;

}


int main() {
     int salary;
     cout << "Enter your salary: ";
     cin >> salary;

    applyTex(salary); // passing by value
    cout << "Salary after function call: " << salary << endl; // salary remains unchanged

    return 0;
}