#include <iostream>
using namespace std;

int BinarySearch(int array[], int low, int high, int searchValue){

    int mid;

    if(low <= high){
        mid = (low + high) / 2;
        if(searchValue == array[mid]){
            return mid;
        }
        else if(searchValue < array[mid]){
            return BinarySearch(array, low, mid - 1, searchValue);
        }
        else if(searchValue > array[mid]){
            return BinarySearch(array, mid - 1, high, searchValue);
        }
    }
    
    return -1;
}

int main(){

    //array must be sorted that's why we have taken a sorted array.
    int arr[] = {4, 6, 14, 17, 37, 51, 59, 72, 85, 93};

    int N = sizeof(arr) / sizeof(arr[0]);//N refers to number of elements in the array.

    int userValue; //variable for the value entered by the user.
    cout << "Enter the element you are looking for: ";
    cin >> userValue; //taking the input of the value from the user.

    int res = BinarySearch(arr, 0, N - 1, userValue);//Calling the Binary Search function.

    if(res == -1){
        cout << "The element " << userValue << " is not in the array." << endl;
    }
    else{
        cout << "The element " << userValue << " is present at the index " << res << "." << endl;
    }

    return 0;
}