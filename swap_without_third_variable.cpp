//Program for swapping two numbers without using third variable.
#include <iostream>
using namespace std;


int main(){

    int num1, num2;
    cout << "Enter the value of num1: ";
    cin >> num1;
    cout << "Enter the value of num2: ";
    cin >> num2;

    cout << endl;
    cout << "Before swapping: " << endl << "num1 = " << num1 << endl << "num2 = " << num2 << endl;

    //swapping two number without using third variable.
    num1 = num1 - num2;
    num2 = num2 + num1;
    num1 = num2 - num1;

    cout << endl << "After swapping without using third variable: " << endl;
    cout << "num1 = " << num1 << endl << "num2 = " << num2 << endl;

    return 0;
}