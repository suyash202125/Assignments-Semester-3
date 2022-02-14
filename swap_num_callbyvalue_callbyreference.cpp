//C++ program for swapping two numbers using "call by value" and "call by reference".
#include <iostream>
using namespace std;

//function for swapping two numbers and to be called by value.
void Swap_CallByValue(int a, int b){
    int temp;
    temp = a;
       a = b;
       b = temp;
}

//function for swapping two numbers and to called by reference.
void Swap_CallByReference(int &a, int &b){
    int temp;
    temp = a;
       a = b;
       b = temp;
}


int main(){

    int num1, num2;

    cout << "Enter the value of num1: ";
    cin >> num1;
    cout << "Enter the value of num2: ";
    cin >> num2;

    cout << endl;
    cout << "Before swapping: " << endl << "num1 = " << num1 << endl << "num2 = " << num2 << endl;

    //calling by value.
    Swap_CallByValue(num1, num2);

    cout << endl << "After swapping using call by value: " << endl;
    cout << "num1 = " << num1 << endl << "num2 = " << num2 << endl;

    //calling by reference.
    Swap_CallByReference(num1, num2);

    cout << endl << "After swapping using call by reference: " << endl;
    cout << "num1 = " << num1 << endl << "num2 = " << num2 << endl;

    return 0;
}