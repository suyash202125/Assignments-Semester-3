//Iterative solution for finding an element in the array using binary search.
#include <iostream>
using namespace std;

void BinarySearch(int array[], int size, int searchValue){

    bool flag = 0;
    int low = 0;
    int high = size - 1;

    int mid;

    while(low <= high)
    {

        mid = (low + high) / 2; //assigning the mid index.

        if(searchValue == array[mid])
        {
            flag = 1;//This indicates that the condition in the parentheses is true.
            break;
        }
        else if(searchValue < array[mid])
        {
            high = mid - 1;//updating the high index.
        }
        else
        {
            low = mid + 1;//updating the low index.
        }
    }

    if(flag == 0){
        cout << "The element " << searchValue << " is not in the array." << endl;
    }
    else{
        cout << "The element " << searchValue << " is present at the index " << mid << "." << endl;
    }
}

int main(){
     
    //array must be sorted that's why we have taken a sorted array.
    int arr[] = {4, 6, 14, 17, 37, 51, 59, 72, 85, 93};

    int N = sizeof(arr) / sizeof(arr[0]);//N refers to number of elements in the array.

    int userValue; //variable for the value entered by the user.
    cout << "Enter the element you are looking for: ";
    cin >> userValue; //taking the input of the value from the user.

    BinarySearch(arr, N, userValue);//Calling the Binary Search function.

    return 0;
}