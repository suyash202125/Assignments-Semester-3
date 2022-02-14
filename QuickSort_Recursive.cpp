#include <iostream>
using namespace std;

//swapping two numbers.
void swap(int *x, int *y){ 

    int temp; 
         temp = *x;
           *x = *y;
           *y = temp;       
}

//partitioning the array.
int partition(int array[], int lowest_index, int highest_index){
    int pivot;
    pivot = array[highest_index];
    int i = lowest_index - 1;

    for(int j = lowest_index; j < highest_index; j++){

        if(array[j] < array[highest_index]){
            i++;
            swap(&array[i], &array[j]);
        }
    }
    swap(&array[i+1], &array[highest_index]);

    return (i+1);
}

//Quicksort recursive algorithm
void quicksort(int array[], int lowest_index, int highest_index){

    if(lowest_index < highest_index){

        int pivot_index = partition(array, lowest_index, highest_index);

        //calling quicksort recursively for the left of the pivot subarray.
        quicksort(array, lowest_index, pivot_index - 1);
        //calling quicksort recursively for the right of the pivot subarray.
        quicksort(array, pivot_index + 1, highest_index);
    }
}


int main(){

    int array_size;
    cout << "Enter the size of array: ";
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

    quicksort(arr, 0, array_size - 1);// calling the quicksort function.

    cout << "\nThe sorted array is: " << endl;
    for(int i=0; i<array_size; i++){//printing the array.
        cout << arr[i] << " ";
    }

    return 0;
}