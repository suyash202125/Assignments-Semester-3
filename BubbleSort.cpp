//Program for sorting array using bubblesort.
#include <iostream>
using namespace std;

//function for swapping two numbers.
void swap(int *a, int *b){
    int temp = *a;
          *a = *b;
          *b = temp;
}

//bubblesort algorithm
void bubblesort(int array[], int n){
    
    bool isSwap;
    for(int i = 0; i < n - 1; i++){
        isSwap = false;
        for(int j = 0; j < (n - i - 1); j++){
            if(array[j] > array[j+1]){
                    swap(&array[j], &array[j+1]);
                    isSwap = true;
            }
        }
        if(isSwap == false){
            break;
        }
    }
}

int main(){

    int array_size;
    cout << "Enter the size of the array: ";
    cin >> array_size;

    int arr[array_size];

    cout << endl;
    for(int i = 0; i < array_size; i++){//taking the input of the elements of array
        cout << "Enter the element at index " << i << " in the array: ";
        cin >> arr[i];       
    }

    cout << endl;
    //unsorted array output.
    cout << "The unsorted array is: " << endl;
    for(int i=0; i<array_size; i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    //calling the bubblesort function.
    bubblesort(arr, array_size);
    
    //printing the sorted array
    cout << endl << "The sorted array is: " << endl;
    for(int i = 0; i<array_size; i++){
        cout << arr[i] << " ";
    }

    return 0;
}