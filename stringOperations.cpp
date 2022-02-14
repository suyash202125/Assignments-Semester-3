#include <iostream>

using namespace std;

//Reverse function to reverse the string.
string Reverse(string str){
        
        string reverse;
        for(int i = str.length() - 1; i>=0; i--){
            reverse.push_back(str[i]);
        }
        return reverse;
}

int main(){

    string myStr1, myStr2;
    cout << "Enter the 1st string: ";
    getline(cin, myStr1);
    cout << endl;
    cout << "Enter the 2nd string: ";
    getline(cin, myStr2);

    cout << endl;

    //1st Operation - Finding the length of the strings.
    cout << "The length of string \"" << myStr1 << "\" is " << myStr1.length() << "." << endl;
    cout << "The length of string \"" << myStr2 << "\" is " << myStr2.length() << "." << endl;

    cout << endl;
    //2nd Operation - Concatenating the strings.
    cout << "The concatenated string is: " << myStr1 + myStr2 << endl;

    cout << endl;
    //3rd Operation - Reversing the strings by calling the Reverse function.
    cout << "The reverse of " << myStr1 << " is: " << Reverse(myStr1) << endl;
    cout << "The reverse of " << myStr2 << " is: " << Reverse(myStr2) << endl;

    cout << endl;
    //4th Operation - Copying the strings.
    string copied_string;
    copied_string = myStr1;//copying myStr1 to copied_string variable.
    cout << "The copied string of 1st string is: " << copied_string << endl;

    copied_string = myStr2;//copying myStr2 to copied_string variable.
    cout << "The copied string of 2nd string is: " << copied_string << endl;

    return 0;
}